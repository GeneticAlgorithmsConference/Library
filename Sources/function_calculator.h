#ifndef FUNCTION_CALCULATOR_H
#define FUNCTION_CALCULATOR_H

#include "individual/base_individual.h"

#include <vector>

namespace Genetic
{

class FunctionCalculator
{
public:
	virtual void process(std::vector <Genetic::BaseIndividual*>& individuals) = 0;
};

}

#endif
