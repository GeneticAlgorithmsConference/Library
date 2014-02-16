/******************************************************
Copyright (c/c++) 2013-doomsday by Alexey Slovesnov 
homepage http://slovesnov.narod.ru/indexe.htm
email slovesnov@yandex.ru
All rights reserved.
******************************************************/

#include "expressionEstimator.h"
#include <stdio.h>

int main(){
#ifdef _DEBUG
	{
#endif
	ExpressionEstimator::Init();
	ExpressionEstimator estimator;
	const char* expressions[]={"min(1.1,2.2)","x0*x1+3"};
	const char* expression;

	try{
		expression=expressions[0];
		estimator.compile(expression);
		printf("%s=%.6lf\n",expression,estimator.calculate() );

	}
	catch(Exception ex){
		printf("%s exception %s\n",expression,ex.what() );
	}

	try{
		expression=expressions[1];
		estimator.compile(expression);
		double v[]={3.,5.,7.};
		printf("%s=%.6lf\n",expression,estimator.calculate(v,sizeof(v)/sizeof(v[0])));
		double v1[]={4.,5.};
		printf("%s=%.6lf\n",expression,estimator.calculate(v1,sizeof(v1)/sizeof(v1[0])));
	}
	catch(Exception ex){
		printf("%s exception %s\n",expression,ex.what() );
	}

#ifdef _DEBUG
	}
	printf("total created %d destroyed %d\n",ExpressionEstimator::totalCreated,ExpressionEstimator::totalDestroyed );
#endif
	return 0;
}

