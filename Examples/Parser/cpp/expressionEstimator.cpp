/******************************************************
Copyright (c/c++) 2013-doomsday by Alexey Slovesnov 
homepage http://slovesnov.narod.ru/indexe.htm
email slovesnov@yandex.ru
All rights reserved.
******************************************************/

#include "stdafx.h"
#include "exception.h"
#include "expressionEstimator.h"

const char* CONSTANT_NAME[]={"PI", "E", "SQRT2", "SQRT1_2", "LN2", "LN10", "LOG2E", "LOG10E", NULL};
const double CONSTANT_VALUE[]={	PI, exp(1), sqrt(2), sqrt(0.5), log(2), log(10), 1/log(2), 1/log(10) };

const char* OPERATOR[]={ 
	"PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", "COMMA" 
	,"SIN", "COS", "TAN", "COT", "SEC", "CSC"
	,"ASIN", "ACOS", "ATAN", "ACOT", "ASEC", "ACSC"
	,"SINH", "COSH", "TANH", "COTH", "SECH", "CSCH"
	,"ASINH", "ACOSH", "ATANH", "ACOTH", "ASECH", "ACSCH"
	,"RANDOM", "CEIL", "FLOOR", "ROUND", "ABS", "EXP", "LOG", "SQRT", "POW", "ATAN2", "MIN", "MAX"
	,"X", "NUMBER", "UNARY_MINUS", "END",NULL
};

#ifdef _DEBUG
	int	ExpressionEstimator::totalDestroyed=0;
	int	ExpressionEstimator::totalCreated=0;
#endif


int ExpressionEstimator::getIndex(const char* a[],const char *v) throw (IllegalArgumentException){
	const char* n;
	int i;
	for(i=0 ; (n=a[i])!=NULL ; i++){
		if(strcmp(n,v)==0){
			return i;
		}
	}
	throw IllegalArgumentException();
}

void ExpressionEstimator::getToken() throw (Exception){
	int i;
	char*c;
	const char T[]="+-*/()[]{},";
	
	if(position==expression.length()){
		_operator = END;
	}
	else if( (c=strchr(T,expression[position]))!=NULL ){
		position++;
		_operator=(OPERATOR_ENUM)(c-T);
	}
	else if(isLetter()){
		for(i=position++;isFunctionSymbol();position++);
		std::string token =expression.substr(i,position-i);;
   
		try{
		  if(token[0]=='X' && token.length()==1){
			  throw Exception("unknown keyword");
		  }
		  else if(token[0]=='X' && token.length()>1  && isDigit(token[1])){
		  	i=atoi(token.substr(1).c_str());
	      if(i<0){
			    throw Exception("index of 'x' should be nonnegative integer number");
		    }
	      if(arguments<i+1){
	      	arguments=i+1;
	      }
	      _operator=X;
	      tokenValue=i;
		  }
		  else{
				_operator=(OPERATOR_ENUM)getIndex(OPERATOR,token.c_str());
			  i=_operator;
			  if( i<SIN || i>MAX ){
			    throw IllegalArgumentException();
			  }
		  }		  	
		}
		catch (IllegalArgumentException){
		  try{
				tokenValue=CONSTANT_VALUE[getIndex(CONSTANT_NAME,token.c_str())];
		  	_operator=NUMBER;
		  }
			catch (IllegalArgumentException){
			  throw Exception("unknown keyword");
			}
		}
	}
	else if(isDigit() || isPoint()){
		for(i=position++ ; isDigit() || isPoint() || expression[position]=='E' 
			|| expression[position-1]=='E' && strchr("+-",expression[position])!=NULL; position++);
		tokenValue =atof(expression.substr(i,position-i).c_str());
		_operator = NUMBER;
	}
	else{
    throw Exception("unknown symbol");
	}

}      

bool ExpressionEstimator::compile(const char* _expression) throw(Exception){
	position=0;
	arguments=0;
	expression="";
	root=NULL;
	clear();
	argument=NULL;
	const char * pc=_expression;
	for( ; *pc!=0 ; pc++){//make upper string
		if(*pc==' ' || *pc=='\t'){
			continue;
		}
		expression+=toupper(*pc);
	}

	//printf("[%s]",expression.c_str());

	getToken();
	if(_operator==END){
		throw Exception("unexpected end of expression");
	}
	root = parse();
	if(_operator!=END){
		throw Exception("end of expression expected");
	}

	return true;
}

Node* ExpressionEstimator::parse() throw(Exception){
	Node* node = parse1();
	while(_operator==PLUS || _operator==MINUS){
    node = createNode(_operator, node);
		getToken();
		if(_operator==PLUS || _operator==MINUS){
    	throw Exception("two operators in a row");
		}
		node->right=parse1();
	}
	return node;
}
 
Node* ExpressionEstimator::parse1() throw (Exception){
	Node* node = parse2();
	while(_operator==MULTIPLY || _operator==DIVIDE){
    node = createNode(_operator, node);
		getToken();
		if(_operator==PLUS || _operator==MINUS){
    	throw Exception("two operators in a row");
		}
		node->right=parse2();
	}
	return node;
}

Node* ExpressionEstimator::parse2() throw (Exception){
	Node* node;
	if(_operator==MINUS){
		getToken();
    node = createNode(UNARY_MINUS, parse3());
	}
	else{
		if(_operator==PLUS){
			getToken();
		}
		node = parse3();
	}
	return node;      
}

Node* ExpressionEstimator::parse3() throw (Exception){
	Node* node;
	OPERATOR_ENUM open;

	if(_operator>=SIN && _operator<=MAX){
		int arguments;
  	if( _operator>=POW  && _operator<=MAX ){
  		arguments=2;
  	}
  	else{
  		arguments=_operator==RANDOM?0:1;
  	}
  		
    node = createNode(_operator);
		getToken();
		open=_operator;
		if(_operator!=LEFT_BRACKET && _operator!=LEFT_SQUARE_BRACKET && _operator!=LEFT_CURLY_BRACKET ){
			throw Exception("open bracket expected");
		}
		getToken();
  
		if(arguments>0){
			node->left = parse();
			
	  	if( arguments==2 ){
				if(_operator!=COMMA){
					throw Exception("comma expected");
				}
				getToken();
				node->right = parse();
	  	}
		}
		checkBracketBalance(open);
	}
	else{
		switch(_operator){

	  case X:
	  case NUMBER:
	    node = createNode(_operator,tokenValue);
	    break;
	    
	  case LEFT_BRACKET:
	  case LEFT_SQUARE_BRACKET:
	  case LEFT_CURLY_BRACKET:
	    open=_operator;
	    getToken();
	    node = parse();
	    checkBracketBalance(open);
	    break;

	  default:
	    throw Exception("unexpected operator");
		}

	}
  getToken();
	return node;
}


double ExpressionEstimator::calculate() throw (Exception){
  if(root==NULL){
  	throw Exception("using of calculate() without compile()");
  }

  int length = argument==NULL?0:argumentSize;

  if(length!=arguments){
  	throw Exception("invalid number of expression arguments");
  }
  return root->calculate();
}

double ExpressionEstimator::calculate(const char* s) throw (Exception) {
	ExpressionEstimator estimator=ExpressionEstimator(); 
	estimator.compile(s);
	estimator.argument=NULL;//clear all arguments
	return estimator.calculate();
}

void ExpressionEstimator::clear(){
	std::vector<Node*>::iterator it;
	for(it=vnode.begin();it!=vnode.end();it++){
		delete *it;
	}
#ifdef _DEBUG
	if(vnode.size()!=0){
		printf("destroyed %d node(s)\n",vnode.size());
	}
	totalDestroyed+=vnode.size();
#endif
	vnode.clear();

}

ExpressionEstimator::~ExpressionEstimator(){
	clear();
}