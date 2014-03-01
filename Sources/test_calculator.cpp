#include "test_calculator.h"
#include "testindividual.h"

void TestCalculator::process(std::vector <Genetic::BaseIndividual*>& individuals)
{
	for(unsigned int i = 0; i < individuals.size(); ++i)
	{
		TestIndividual* tmpIndividual = dynamic_cast<TestIndividual*>(individuals[i]);
		tmpIndividual->test();
	}
}
