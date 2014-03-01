#ifndef RECOMBINATION_H
#define RECOMBINATION_H

#include "../individual/base_individual.h"

namespace Genetic
{

class Recombination
{
public:
	virtual void process(Genetic::BaseIndividual* parentIndividual1, Genetic::BaseIndividual* parentIndividual2,
	                     Genetic::BaseIndividual* childIndividual1, Genetic::BaseIndividual* childIndividual2) = 0;
private:
};

}

#endif
