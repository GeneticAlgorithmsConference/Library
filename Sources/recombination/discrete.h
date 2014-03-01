#ifndef DISCRETE_RECOMBINATION_H
#define DISCRETE_RECOMBINATION_H

#include "recombination.h"
#include "../log.h"
#include <cstdlib>

namespace Genetic
{

template <typename I>
class DiscreteRecombination : public Genetic::Recombination
{
public:
	void process(Genetic::BaseIndividual* parentIndividual1, Genetic::BaseIndividual* parentIndividual2,
	             Genetic::BaseIndividual* childIndividual1, Genetic::BaseIndividual* childIndividual2) override;
private:
};

}

template <typename I>
void Genetic::DiscreteRecombination <I>::process(Genetic::BaseIndividual* _parentIndividual1, Genetic::BaseIndividual* _parentIndividual2,
                                                    Genetic::BaseIndividual* _childIndividual1, Genetic::BaseIndividual* _childIndividual2)
{
	I* parentIndividual1 = dynamic_cast<I*>(_parentIndividual1);
	I* parentIndividual2 = dynamic_cast<I*>(_parentIndividual2);
	I* childIndividual1 = dynamic_cast<I*>(_childIndividual1);
	I* childIndividual2 = dynamic_cast<I*>(_childIndividual2);
	childIndividual1->dna.resize(parentIndividual1->dna.size());
	childIndividual2->dna.resize(parentIndividual2->dna.size());
	for(int i = 0; i < parentIndividual1->dna.size(); ++i)
	{
		if(rand() & 1)
		{
			childIndividual1->dna[i] = parentIndividual1->dna[i];
		} else {
			childIndividual1->dna[i] = parentIndividual2->dna[i];
		}
		if(rand() & 1)
		{
			childIndividual2->dna[i] = parentIndividual1->dna[i];
		} else {
			childIndividual2->dna[i] = parentIndividual2->dna[i];
		}
	}
}


#endif
