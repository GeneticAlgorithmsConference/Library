#include "unittest.h"

int UnitTest::passedNum = 0;
int UnitTest::failedNum = 0;

void UnitTest::processTest(bool condition, const char* conditionText)
{
	if(!condition)
	{
		std::cout << "Test failed: " << conditionText << std::endl;
		++failedNum;
	} else {
		++passedNum;
	}
}

void UnitTest::printLog()
{
	if(failedNum == 0)
	{
		std::cout << "All tests are passsed!" << std::endl;
	} else {
		std::cout << "Passed: " << passedNum << std::endl;
		std::cout << "Failed: " << failedNum << std::endl;
	}
}

