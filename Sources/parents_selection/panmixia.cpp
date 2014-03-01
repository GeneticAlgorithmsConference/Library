#include "panmixia.h"

#include <vector>
#include <cstdlib>

void Genetic::Panmixia::process(std::vector <Genetic::BaseIndividual*>& individuals,
                                std::vector <Genetic::BaseIndividual*>& resultIndividuals,
                                Genetic::Recombination* recombination)
{
	int individualsNum = individuals.size();
	for(int i = 0; i < individualsNum / 2; ++i)
	{
		int firstParent = rand() % individualsNum;
		int secondParent = rand() % (individualsNum - 1);
		if(secondParent >= firstParent)
		{
			++secondParent;
		}
		
		recombination->process(individuals[firstParent], individuals[secondParent],
		                       resultIndividuals[i * 2], resultIndividuals[i * 2 + 1]);
	}
}
