#include "expressionEstimator.h"
#include <stdio.h>

int main(){
	try {
		ExpressionEstimator::Init();
		double v=ExpressionEstimator::calculate("sin(pi/4)");
		printf("%lf",v);
	}catch(Exception e){
		printf("%s\n",e.what());
	}
	return 0;
}
