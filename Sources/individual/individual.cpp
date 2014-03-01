#include "individual.h"

bool scoreComparator(Genetic::BaseIndividual* individual1, Genetic::BaseIndividual* individual2)
{
	return individual1->scoreLessThan(individual2);
}
