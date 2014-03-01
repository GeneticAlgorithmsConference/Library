#include "inbreeding_fenotype.h"
#include "../generation.h"

#include <algorithm>
#include <cstdlib>

void Genetic::InbreedingFenotype::process(std::vector <Genetic::BaseIndividual*>& individuals,
                                          std::vector <Genetic::BaseIndividual*>& resultIndividuals,
                                          Genetic::Recombination* recombination)
{
	int individualsNum = individuals.size();
	int firstParent, secondParent;
	std::sort(individuals.begin(), individuals.end(), Genetic::scoreComparator);
	for(int i = 0; i < individualsNum / 2; ++i)
	{
		firstParent = rand() % individualsNum;

		secondParent = (firstParent == 0) ? 1 : 0;
		for(int j = 0; j < individualsNum; ++j)
		{
			if((j != firstParent)
			   && individuals[firstParent]->dnaDistanceLessThan(individuals[j], individuals[firstParent], individuals[secondParent]))
			{
				secondParent = j;
			}
		}

		recombination->process(individuals[firstParent], individuals[secondParent],
		                       resultIndividuals[i * 2], resultIndividuals[i * 2 + 1]);
	}
}
