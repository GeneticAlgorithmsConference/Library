#ifndef PARENTS_SELECTION_PANMIXIA_H
#define PARENTS_SELECTION_PANMIXIA_H

#include "parents_selection.h"

namespace Genetic
{

class Panmixia : public Genetic::ParentsSelection
{
public:
	void process(std::vector <Genetic::BaseIndividual*>& individuals,
	             std::vector <Genetic::BaseIndividual*>& resultIndividuals,
	             Genetic::Recombination* recombination) override;
private:
	
};

}

#endif
