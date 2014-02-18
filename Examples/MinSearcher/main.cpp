#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>

#include "log.h"
#include "genetic.h"
#include "generation.h"
#include "minsearchindividual.h"

using namespace std;
using namespace Genetic;

class MyTargetFunction
{
public:
    static double getResult(LinearRealDna arguments)
    {
        double x = (arguments)[0];
        double y = (arguments)[1];
        return sin(x/20.0) - sin(y/20.0);
        return fabs(3.0 * x * x * x - 6.0 * x * x + 12.0 * x - 24.0);
    }
};

int main()
{
	// srand(time(NULL));


    GeneticSettings sets =     GeneticSettings(10,
                                               NewGenerationSelectionType::ELITE_SELECTION,
                                               ParentsSelectionType::INBREEDING_FENOTYPE,
                                               RecombinationType::DISCRETE);
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

	return 0;
}

