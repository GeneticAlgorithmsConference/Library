#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>

#include "log.h"
#include "genetic.h"
#include "geneticsettings.h"
#include "dnatypes.h"
#include "individual.h"
#include "generation.h"

#include "linearindividual.h"

#include "minsearchindividual.h"

//#include "treeindividual.h"
//#include "testindividual.h"
//#include "treeexpressionindividual.h"

using namespace std;
using namespace Genetic;

class MyTargetFunction
{
public:
    static double getResult(LinearRealDna &arguments)
    {
        double x = arguments[0];
        double y = arguments[1];
        return sin(x) - sin(y);
        return fabs(3.0 * x * x * x - 6.0 * x * x + 12.0 * x - 24.0);
    }
};

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

	Generation < MinSearchIndividual <MyTargetFunction> > test(2, &sets);
	test.init(time(NULL), 2);

	for(int i = 0; i < 100; ++i)
	{
		dnalog << "Step: " << i << endl;
		test.genNext();
	}


	// Population < Generation < TestIndividual > > test(10);
	// test.initGeneration(time(NULL));

	// for(int i = 0; i < 1000; ++i)
	// {
	// 	test.genNextGeneration();
	// }

//	Population <Generation <TreeExpressionIndividual> > test(10, ELITE_SELECTION, PANMIXIA);

//	Population < Generation < MinSearchIndividual <MyTargetFunction> > >
//		test(10, ELITE_SELECTION, INBREEDING_FENOTYPE);
//	test.initGeneration(time(NULL));
//
//	for(int i = 0; i < 100; ++i)
//	{
//		dnalog << "Step: " << i << endl;
//		test.genNextGeneration();
//	}

	return 0;
}

