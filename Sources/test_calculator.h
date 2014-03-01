#ifndef TEST_CALCULATOR_H
#define TEST_CALCULATOR_H

#include "function_calculator.h"

class TestCalculator : public Genetic::FunctionCalculator
{
public:
	virtual void process(std::vector <Genetic::BaseIndividual*>& individuals);
};

#endif
