/******************************************************
Copyright (c/c++) 2013-doomsday by Alexey Slovesnov 
homepage http://slovesnov.narod.ru/indexe.htm
email slovesnov@yandex.ru
All rights reserved.
******************************************************/

#ifndef _node_h_
#define _node_h_

#include "operatorEnum.h"
#include "exception.h"

class ExpressionEstimator;

class Node{

	friend class ExpressionEstimator;

	ExpressionEstimator* estimator;

	inline static double round(double d){
		return floor(d + 0.5);
	}

	inline static double min(double x,double y){
		return x<=y?x:y;
	}

	inline static double max(double x,double y){
		return x>=y?x:y;
	}


	OPERATOR_ENUM _operator;
	double value;
	Node* left,*right;
	
	void init(ExpressionEstimator* _estimator, OPERATOR_ENUM __operator,double _value, Node* _left);

	double calculate() throw (Exception);

};

#endif
