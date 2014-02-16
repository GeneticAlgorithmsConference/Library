#include "expressionEstimator.h"
#include <stdio.h>
#include <string>

std::string arraytoString(const double *v,const int arguments){
	std::string s="[";
	char buff[32];
	for(int i=0;i<arguments;i++){
		sprintf(buff, "%lf", v[i]);
		s+=buff;
		s+= i==arguments-1 ? "]" : ", " ;
	}
	return s;
}

int main(){
	ExpressionEstimator::Init();
	ExpressionEstimator estimator;
	int i;
	const char*s;
	const char* expression[]={"sin(pi/4)","1+2+"};
	const int expressionSize=sizeof(expression)/sizeof(expression[0]);
	for(i=0;i<expressionSize;i++){
		s=expression[i];
		printf("\"%s\"=",s);
		try {
			printf("%lf\n",ExpressionEstimator::calculate(s));
		} catch (Exception e) {
			printf("%s\n",e.what());
		}
	}

  const char* expression1[]={"3*x0+2*x1*x0","6*x0"};
	const int expression1Size=sizeof(expression1)/sizeof(expression1[0]);

	const int arguments=2;
	const double values[][arguments]={ {3,6}, {8,6} };
	const int valuesSize=sizeof(values)/sizeof(values[0]);

	const double*v;
	for(i=0;i<valuesSize;i++){
		v=values[i];
		s=expression1[i];
		printf("\"%s\"%s=",s,arraytoString(v,arguments).c_str());
		try {
			estimator.compile(s);
			printf("%lf\n",estimator.calculate(v,arguments));
		} catch (Exception e) {
			printf("%s\n",e.what());
		}
	}

	return 0;
}
