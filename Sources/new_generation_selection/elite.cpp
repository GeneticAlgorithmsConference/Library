#include "elite.h"
#include "../log.h"
#include "new_generation_selection.h"

Genetic::EliteSelection::~EliteSelection()
{
}

void Genetic::EliteSelection::process(std::vector <BaseIndividual*>& nextIndividuals,
                                      std::vector <BaseIndividual*>& individuals)
{
	unsigned int individualsNum = nextIndividuals.size() / 2;
	for(unsigned int i = 0; i < individualsNum; ++i)
	{
		individuals.push_back(nextIndividuals[i]);
	}
}
