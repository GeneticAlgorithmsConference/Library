
#ifndef TREEINDIVIDUAL_H
#define TREEINDIVIDUAL_H

#include <stdlib.h>
#include <vector>

#include "genetic.h"

namespace Genetic {


/**
 * class TreeIndividual
 *
 */

	template <typename D, typename S>
	class TreeIndividual: public Individual<D, S>
	{
	public:

        void mutate(Genetic::GeneticSettings* geneticSettings);

		static void recombine(Genetic::TreeIndividual <D, S>* parentIndividual1,
		                      Genetic::TreeIndividual <D, S>* parentIndividual2,
		                      Genetic::TreeIndividual <D, S>* childIndividual1,
		                      Genetic::TreeIndividual <D, S>* childIndividual2,
		                      Genetic::GeneticSettings* geneticSettings);
	};
};

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::mutate(Genetic::GeneticSettings* geneticSettings)
{
    // double attempts = geneticSettings -> getMutationAttempts();
    // double probability = geneticSettings -> getMutationProbability();
    // double parameter = geneticSettings -> getMutationParameter();

	// for(int attemptNo = 0; attemptNo < attempts; ++attemptNo)
	// {
	//     double rndVal = static_cast<double>(rand() % 10000) / 10000.0;
	// 	if(rndVal <= probability)
	// 	{
	// 	    this -> dna.getRandom() -> mutate(parameter);
	// 	}
	// }
}

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::recombine(Genetic::TreeIndividual <D, S>* parentIndividual1,
                                               Genetic::TreeIndividual <D, S>* parentIndividual2,
                                               Genetic::TreeIndividual <D, S>* childIndividual1,
                                               Genetic::TreeIndividual <D, S>* childIndividual2,
                                               Genetic::GeneticSettings* geneticSettings)
{
	D* dna1;
	D* dna2;
	childIndividual1 -> dna = parentIndividual1 -> dna;
	childIndividual2 -> dna = parentIndividual2 -> dna;
	if((childIndividual1 -> dna.getChildrenNum() > 0)
	   && (childIndividual2 -> dna.getChildrenNum() > 0))
	{
		// Swaping two verticies of trees.
		D::swapRandomChildren(childIndividual1 -> dna.getRandomWithChildren(),
		                      childIndividual2 -> dna.getRandomWithChildren());
    }/* else if(childIndividual2 -> dna.getChildrenNum() > 0)
	{
        auto dna1 = childIndividual2 -> dna.getRandomWithChildren();
		int id1 = rand() % dna1 -> getChildrenNum();
        auto tmp = childIndividual1 -> dna;
		childIndividual1 -> dna = dynamic_cast<D&>(dna1 -> getChild(id1));
		dna1 -> setChild(id1, tmp);
	} else if(childIndividual1 -> dna.getChildrenNum() > 0)
	{
        auto dna1 = childIndividual1 -> dna.getRandomWithChildren();
		int id1 = rand() % dna1 -> getChildrenNum();
        auto tmp = childIndividual2 -> dna;
		childIndividual2 -> dna = dynamic_cast<D&>(dna1 -> getChild(id1));
		dna1 -> setChild(id1, tmp);
	} else {
		// Do nothing
    }*/
}

#endif // TREEINDIVIDUAL_H
