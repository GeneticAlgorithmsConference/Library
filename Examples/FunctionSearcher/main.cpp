#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>

#include "log.h"
#include "genetic.h"
#include "generation.h"
#include "treeexpressionindividual.h"

using namespace std;
using namespace Genetic;

double func(double x)
{
    return x * tan(cos(x));
}
void generateFunctionValues()
{
    ofstream out("tests.txt");
    int testsNumber = 10;
    out << testsNumber << endl;
    for(int i = 0; i < testsNumber; ++i)
    {
        double current = static_cast<double>(rand() % 10000 - 5000) / 100.0;
        out << setprecision(8) << fixed << current << " " << func(current) << endl;
    }
}

int main()
{
    // srand(time(NULL));
    generateFunctionValues();


    GeneticSettings sets =     GeneticSettings(10,
                               NewGenerationSelectionType::ELITE_SELECTION,
                               ParentsSelectionType::INBREEDING_FENOTYPE,
                               RecombinationType::CROSSOVER);
    sets.setMutationAttempts(3);
    sets.setMutationParameter(1);
    sets.setMutationProbability(0.5);
    sets.setRecombinationParameter(1);
    sets.setGenerationSelectionParameter(1);

    Generation < TreeExpressionIndividual > test(10, &sets);
	test.init(time(NULL), 5);

	for(int i = 0; i < 100; ++i)
	{
		dnalog << "Step: " << i << endl;
		test.genNext();
	}

    return 0;
}

