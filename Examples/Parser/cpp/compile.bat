@rem this is helper file for gnu compiler
@rem add mingw path Go to Start -> Settings -> Control Panel -> System -> Advanced -> Environment Variables, then either update the system path or add/modify the user path. 
@rem use c++ or g++ compiler
@rem g++ -D _DEBUG -O3 -o v  StdAfx.cpp ExpressionEstimator.cpp Node.cpp main.cpp
g++ -O3 -o v  stdafx.cpp expressionEstimator.cpp node.cpp main.cpp
