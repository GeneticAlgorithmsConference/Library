#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <iostream>

#define unitTest(a) UnitTest::processTest(a, #a)

class UnitTest
{
public:
	static void processTest(bool condition, const char* conditionText);
	static void printLog();

private:
	static int passedNum;
	static int failedNum;
};

#endif
