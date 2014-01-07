
#ifndef TREEINDIVIDUAL_H
#define TREEINDIVIDUAL_H

#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <iostream>

#include "genetic.h"
#include "treeexpressiondna.h"

namespace Genetic {


/**
 * class TreeIndividual
 *
 */

	template <typename D, typename S>
	class TreeIndividual
	{
	public:
		/// Empty Constructor2.
		TreeIndividual();

		/// Empty Destructor.
		virtual ~TreeIndividual();

		virtual void test() = 0;

		/// Recombine method.
		static void recombine(Genetic::TreeIndividual <D, S>* parentIndividual1,
		                      Genetic::TreeIndividual <D, S>* parentIndividual2,
		                      Genetic::TreeIndividual <D, S>* childIndividual1,
		                      Genetic::TreeIndividual <D, S>* childIndividual2);

		/// Generate method.
		virtual void generate();

		/// Update parameters from dna.
		virtual void updateParameters();

		virtual void mutate();
		
		/**
		 * Set the value of score
		 * @param new_var the new value of score
		 */
		void setScore(S value);

		/**
		 * Get the value of score
		 * @return the value of score
		 */
		S getScore();

		/**
		 * Set the value of dna
		 * @param new_var the new value of dna
		 */
		void setDna(D* value);

		/**
		 * Get the value of dna
		 * @return the value of dna
		 */
		const D* getDna() const;

	protected:

		S score;	///< Score value
		D* dna;
	};
};

/**
 * Detailed description of empty constructor.
 */
template <typename D, typename S>
Genetic::TreeIndividual <D, S>::TreeIndividual()
{

}

template <typename D, typename S>
Genetic::TreeIndividual <D, S>::~TreeIndividual()
{
	delete dna;
}

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::recombine(Genetic::TreeIndividual <D, S>* parentIndividual1,
                                               Genetic::TreeIndividual <D, S>* parentIndividual2,
                                               Genetic::TreeIndividual <D, S>* childIndividual1,
                                               Genetic::TreeIndividual <D, S>* childIndividual2)
{
	D* dna1;
	D* dna2;
	*(childIndividual1 -> dna) = *(parentIndividual1 -> dna);
	*(childIndividual2 -> dna) = *(parentIndividual2 -> dna);
	if((childIndividual1 -> dna -> getChildrenNum() > 0)
	   && (childIndividual2 -> dna -> getChildrenNum() > 0))
	{
		// Swaping two verticies of trees.
		D::swapRandomChildren(childIndividual1 -> dna -> getRandomWithChildren(),
		                      childIndividual2 -> dna -> getRandomWithChildren());
	} else if(childIndividual2 -> dna -> getChildrenNum() > 0)
	{
		auto dna1 = childIndividual2 -> dna -> getRandomWithChildren();
		int id1 = rand() % dna1 -> getChildrenNum();
		auto tmp = childIndividual1 -> dna;
		childIndividual1 -> dna = dynamic_cast<D*>(dna1 -> getChild(id1));
		dna1 -> setChild(id1, tmp);
	} else if(childIndividual1 -> dna -> getChildrenNum() > 0)
	{
		auto dna1 = childIndividual1 -> dna -> getRandomWithChildren();
		int id1 = rand() % dna1 -> getChildrenNum();
		auto tmp = childIndividual2 -> dna;
		childIndividual2 -> dna = dynamic_cast<D*>(dna1 -> getChild(id1));
		dna1 -> setChild(id1, tmp);
	} else {
		// Do nothing
	}
}

template <typename D, typename S>        
void Genetic::TreeIndividual <D, S>::mutate()
{
	dna -> getRandom() -> mutate();
}

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::generate()
{
}

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::updateParameters()
{
}

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::setScore(S value)
{
	score = value;
}

template <typename D, typename S>
S Genetic::TreeIndividual <D, S>::getScore()
{
	return score;
}

template <typename D, typename S>
void Genetic::TreeIndividual <D, S>::setDna(D* value)
{
	dna = value;
}

template <typename D, typename S>
const D* Genetic::TreeIndividual <D, S>::getDna() const
{
	return dna;
}

#endif // TREEINDIVIDUAL_H
