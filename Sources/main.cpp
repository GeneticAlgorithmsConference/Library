#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>

#include "log.h"
#include "genetic.h"
#include "unittest.h"
#include "testindividual.h"
#include "test_calculator.h"

using namespace Genetic;

double func(double x)
{
    return x * tan(cos(x));
}

void generateFunctionValues()
{
	std::ofstream out("tests.txt");
    int testsNumber = 10;
    out << testsNumber << std::endl;
    for(int i = 0; i < testsNumber; ++i)
    {
        double current = static_cast<double>(rand() % 10000 - 5000) / 100.0;
        out << std::setprecision(8) << std::fixed << current << " " << func(current) << std::endl;
    }
}

int main()
{
	GeneticSettings sets;
	sets.setParentsSelection(new InbreedingFenotype);
	sets.setNewGenerationSelection(new EliteSelection);
	sets.setRecombination(new DiscreteRecombination <TestIndividual>);
	sets.setMutation(new BinaryDnaMutation(2));
	sets.setFunctionCalculator(new TestCalculator);

    Generation <TestIndividual> test(10, &sets);
	test.init(time(NULL));

	for(int i = 0; i < 100; ++i)
	{
		dnalog << "Step: " << i << std::endl;
		test.genNext();
	}
	test.getIndividualsSorted();

	delete sets.getNewGenerationSelection();


    return 0;
}

