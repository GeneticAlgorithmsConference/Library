#ifndef PARENTS_SELECTION_INBREEDING_GENOTYPE_H
#define PARENTS_SELECTION_INBREEDING_GENOTYPE_H

#include "parents_selection.h"

namespace Genetic
{

class InbreedingGenotype : public Genetic::ParentsSelection
{
public:
	void process(std::vector <Genetic::BaseIndividual*>& individuals,
	             std::vector <Genetic::BaseIndividual*>& resultIndividuals,
	             Genetic::Recombination* recombination) override;
};

}

#endif
