#include "expressionEstimator.h"
#include <stdio.h>

int main(){
	try {
		ExpressionEstimator::Init();
		ExpressionEstimator estimator;
		estimator.compile("x0+x1");

		const int arguments=2;
    const double values[][arguments]={ {3,6}, {8,6} };
		const int valuesSize=sizeof(values)/sizeof(values[0]);
    for(int i=0;i<valuesSize;i++){
			printf("%lf\n", estimator.calculate(values[i],arguments) );
		}
	}catch(Exception e){
		printf("%s\n",e.what());
	}
	return 0;
}
