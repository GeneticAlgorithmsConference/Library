#include <cassert>
#include <cstdlib>

#include "truncation.h"
#include "../log.h"

Genetic::TruncationSelection::TruncationSelection() :
	truncationCoefficient(1.0)
{

}

Genetic::TruncationSelection::TruncationSelection(double _truncationCoefficient) :
	truncationCoefficient(_truncationCoefficient)
{
	assert(truncationCoefficient > 1.0);
}

Genetic::TruncationSelection::~TruncationSelection()
{
}

void Genetic::TruncationSelection::process(std::vector <BaseIndividual*>& nextIndividuals,
                                           std::vector <BaseIndividual*>& individuals)
{
	dnalog << "Processing..." << std::endl;
	unsigned int individualsNum = nextIndividuals.size() / 2;
	unsigned int possibleIndividualsNum = static_cast<double>(individualsNum) * truncationCoefficient;
	dnalog << possibleIndividualsNum << std::endl;

	assert(possibleIndividualsNum >= individualsNum);

	for(unsigned int i = 0; i < individualsNum; ++i)
	{
		int currentId = rand() % possibleIndividualsNum;
		individuals.push_back(nextIndividuals[currentId]);
	}
	dnalog << "End processing" << std::endl;
}
