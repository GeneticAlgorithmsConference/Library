/******************************************************
Copyright (c/c++) 2013-doomsday by Alexey Slovesnov 
homepage http://slovesnov.narod.ru/indexe.htm
email slovesnov@yandex.ru
All rights reserved.
******************************************************/

#include "stdafx.h"
#include "node.h"
#include "expressionEstimator.h"

void Node::init(ExpressionEstimator* _estimator, OPERATOR_ENUM __operator,double _value, Node* _left){
	estimator=_estimator;
	estimator->vnode.push_back(this);
	_operator=__operator;
	value = _value; 
	left = _left; 
	right= NULL;
#ifdef _DEBUG
	ExpressionEstimator::totalCreated++;
	//printf("create node %lx\n",this);
#endif
}

double Node::calculate() throw (Exception){
	double x;
	switch(_operator){
	
	case NUMBER:
		return value;

  case PLUS:
    return left->calculate()+right->calculate();

  case MINUS:
    return left->calculate()-right->calculate();

  case MULTIPLY:
    return left->calculate()*right->calculate();

  case DIVIDE:
    return left->calculate()/right->calculate();

  case UNARY_MINUS:
    return -left->calculate();

  case SIN:
    return sin(left->calculate());

  case COS:
    return cos(left->calculate());

  case TAN:
    return tan(left->calculate());

  case COT:
    return 1/tan(left->calculate());

  case SEC:
    return 1/cos(left->calculate());

  case CSC:
    return 1/sin(left->calculate());

  case ASIN:
    return asin(left->calculate());

  case ACOS:
    return acos(left->calculate());

  case ATAN:
    return atan(left->calculate());

  case ACOT:
    return PI/2-atan(left->calculate());
    
  case ASEC:
    return acos(1/left->calculate());
    
  case ACSC:
    return asin(1/left->calculate());
   
  case SINH:
    x=left->calculate();
    return (exp(x)-exp(-x))/2;

  case COSH:
    x=left->calculate();
    return (exp(x)+exp(-x))/2;

  case TANH:
    x=left->calculate();
    return (exp(2*x)-1)/(exp(2*x)+1);

  case COTH:
    x=left->calculate();
    return (exp(2*x)+1)/(exp(2*x)-1);

  case SECH:
    x=left->calculate();
    return 2/(exp(x)+exp(-x));

  case CSCH:
    x=left->calculate();
    return 2/(exp(x)-exp(-x));
    
  case ASINH:
    x=left->calculate();
    return log(x+sqrt(x*x+1));

  case ACOSH:
    x=left->calculate();
    return log(x+sqrt(x*x-1));

  case ATANH:
    x=left->calculate();
    return log((1+x)/(1-x))/2;

  case ACOTH:
    x=left->calculate();
    return log((x+1)/(x-1))/2;

  case ASECH:
    x=left->calculate();
    return log( (1+sqrt(1-x*x))/x );

  case ACSCH:
    x=left->calculate();
    return log( (1/x+sqrt(1+x*x))/fabs(x) );
    
  case RANDOM:
    return double(rand())/RAND_MAX;

  case CEIL:
    return ceil(left->calculate());

  case FLOOR:
    return floor(left->calculate());

  case ROUND:
    return round(left->calculate());

  case ABS:
    return fabs(left->calculate());

  case EXP:
    return exp(left->calculate());

  case LOG:
    return log(left->calculate());

  case SQRT:
    return sqrt(left->calculate());
    
  case POW:
    return pow(left->calculate(),right->calculate());
    
  case ATAN2:
    return atan2(left->calculate(),right->calculate());
    
  case MIN:
    return min(left->calculate(),right->calculate());

  case MAX:
    return max(left->calculate(),right->calculate());
    
  case X:
    return estimator->argument[(int)value];
	    
	default:
		throw Exception("Node.calculate error");
	}
}	  

