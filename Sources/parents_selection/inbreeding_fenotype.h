#ifndef PARENTS_SELECTION_INBREEDING_FENOTYPE_H
#define PARENTS_SELECTION_INBREEDING_FENOTYPE_H

#include "parents_selection.h"

namespace Genetic
{

class InbreedingFenotype : public Genetic::ParentsSelection
{
public:
	void process(std::vector <Genetic::BaseIndividual*>& individuals,
	             std::vector <Genetic::BaseIndividual*>& resultIndividuals,
	             Genetic::Recombination* recombination) override;
};

}

#endif
