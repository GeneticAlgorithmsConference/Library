#ifndef PARENTS_SELECTION_PANMIXIA
#define PARENTS_SELECTION_PANMIXIA

#include <vector>
#include <stdlib.h>

namespace Genetic
{
namespace ParentsSelection
{

template <typename Individual>
class Panmixia
{
public:
	void process(std::vector <Individual*>& individuals, std::vector <Individual*>& resultIndividuals);
private:
	
};

template <typename Individual>
void Panmixia<Individual>::process(std::vector <Individual*>& individuals, std::vector <Individual*>& resultIndividuals)
{
	// Recombination
	int individualsNum = individuals.size();
	for(int i = 0; i < individualsNum / 2; ++i)
	{
		int firstParent = rand() % individualsNum;
		int secondParent = rand() % (individualsNum - 1);
		if(secondParent >= firstParent)
		{
			++secondParent;
		}
		Individual::recombine(individuals[firstParent], individuals[secondParent],
		                      resultIndividuals[i * 2], resultIndividuals[i * 2 + 1]);
	}
}

}
};

#endif
