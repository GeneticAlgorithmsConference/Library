
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

	template <typename D>
	class TreeIndividual
	{
	public:
		/// Empty Constructor2.
		TreeIndividual();

		/// Empty Destructor.
		virtual ~TreeIndividual();

		virtual void test() = 0;

		/// Recombine method.
		static void recombine(Genetic::TreeIndividual <D>* parentIndividual1,
		                      Genetic::TreeIndividual <D>* parentIndividual2,
		                      Genetic::TreeIndividual <D>* childIndividual1,
		                      Genetic::TreeIndividual <D>* childIndividual2);

		/// Generate method.
		virtual void generate();

		/// Update parameters from dna.
		virtual void updateParameters();

		virtual void mutate();
		
		/**
		 * Set the value of score
		 * @param new_var the new value of score
		 */
		void setScore(double value);

		/**
		 * Get the value of score
		 * @return the value of score
		 */
		double getScore();

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

		double score;	///< Score value
		D* dna;
	};
};

/**
 * Detailed description of empty constructor.
 */
template <typename D>
Genetic::TreeIndividual <D>::TreeIndividual()
{

}

template <typename D>
Genetic::TreeIndividual <D>::~TreeIndividual()
{
	delete dna;
}

template <typename D>
void Genetic::TreeIndividual <D>::recombine(Genetic::TreeIndividual <D>* parentIndividual1,
                                            Genetic::TreeIndividual <D>* parentIndividual2,
                                            Genetic::TreeIndividual <D>* childIndividual1,
                                            Genetic::TreeIndividual <D>* childIndividual2)
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

template <typename D>        
void Genetic::TreeIndividual <D>::mutate()
{
	dna -> getRandom() -> mutate();
}

template <typename D>
void Genetic::TreeIndividual <D>::generate()
{
}

template <typename D>
void Genetic::TreeIndividual <D>::updateParameters()
{
}

template <typename D>
void Genetic::TreeIndividual <D>::setScore(double value)
{
	score = value;
}

template <typename D>
double Genetic::TreeIndividual <D>::getScore()
{
	return score;
}

template <typename D>
void Genetic::TreeIndividual <D>::setDna(D* value)
{
	dna = value;
}

template <typename D>
const D* Genetic::TreeIndividual <D>::getDna() const
{
	return dna;
}

#endif // TREEINDIVIDUAL_H
