#ifndef NEW_GENERATION_SELECTION_H
#define NEW_GENERATION_SELECTION_H

#include <vector>

#include "../individual/base_individual.h"

namespace Genetic
{

class NewGenerationSelection
{
public:
	virtual ~NewGenerationSelection() {}
	virtual void process(std::vector <BaseIndividual*>& nextIndividuals,
	                     std::vector <BaseIndividual*>& individuals) = 0;
private:
};

}

#endif
