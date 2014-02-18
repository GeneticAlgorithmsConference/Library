#ifndef MINSEARCHINDIVIDUAL_H
#define MINSEARCHINDIVIDUAL_H

#include <vector>

#include "log.h"
#include "genetic.h"
#include "geneticsettings.h"
#include "dnatypes.h"
#include "linearindividual.h"
#include "parser.h"

extern Parser<double> minSearchParser;
namespace Genetic
{
	class MinSearchIndividual : public Genetic::LinearIndividual <LinearRealDna, double>
    {
	public:
        void test();
	};
}

#endif // MINSEARCHINDIVIDUAL_H
