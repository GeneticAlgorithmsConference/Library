#ifndef ELITE_SELECTION_H
#define ELITE_SELECTION_H

#include "new_generation_selection.h"

namespace Genetic
{

class EliteSelection : public NewGenerationSelection
{
public:
	~EliteSelection();
	void process(std::vector <BaseIndividual*>& nextIndividuals,
	             std::vector <BaseIndividual*>& individuals) override;
private:
};

}

#endif
