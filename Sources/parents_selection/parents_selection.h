#ifndef PARENTS_SELECTION_H
#define PARENTS_SELECTION_H

#include "../individual/base_individual.h"
#include "../recombination/recombination.h"

#include <vector>

namespace Genetic
{

class ParentsSelection
{
public:
	virtual void process(std::vector <BaseIndividual*>& individuals,
	                     std::vector <BaseIndividual*>& resultIndividuals,
	                     Genetic::Recombination* recombination) = 0;
private:
};

}

#endif
