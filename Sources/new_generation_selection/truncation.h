#ifndef TRUNCATION_SELECTION_H
#define TRUNCATION_SELECTION_H

#include "new_generation_selection.h"

namespace Genetic
{

class TruncationSelection : public NewGenerationSelection
{
public:
	TruncationSelection();
	TruncationSelection(double _truncateCoefficient);
	~TruncationSelection();
	void process(std::vector <BaseIndividual*>& nextIndividuals,
	             std::vector <BaseIndividual*>& individuals) override;
private:
	double truncationCoefficient;
};

}

#endif
