
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
		void setScore(int value);

		/**
		 * Get the value of score
		 * @return the value of score
		 */
		int getScore();

		/**
		 * Set the value of dna
		 * @param new_var the new value of dna
		 */
		void setDNA(D* value);

		/**
		 * Get the value of dna
		 * @return the value of dna
		 */
		const D* getDNA() const;

	protected:

		int score;	///< Score value
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
}

template <typename D>
void Genetic::TreeIndividual <D>::recombine(Genetic::TreeIndividual <D>* parentIndividual1,
                                            Genetic::TreeIndividual <D>* parentIndividual2,
                                            Genetic::TreeIndividual <D>* childIndividual1,
                                            Genetic::TreeIndividual <D>* childIndividual2)
{
	D* dna1;
	D* dna2;
	*(childIndividual1 -> dna) = parentIndividual1 -> dna;
	*(childIndividual2 -> dna) = parentIndividual2 -> dna;
	if((childIndividual1 -> dna -> getChildrenNum() > 0)
	   && (childIndividual2 -> dna -> getChildrenNum() > 0))
	{
		// Swaping two verticies of trees.
		dna1 = childIndividual1 -> dna -> getRandomWithChildren();
		dna2 = childIndividual2 -> dna -> getRandomWithChildren();
		int id1 = rand() % dna1 -> getChildrenNum();
		int id2 = rand() % dna2 -> getChildrenNum();
		D* tmp = dna1 -> getChild(id1);
		dna1 -> setChild(id1, dna2 -> getChild(id2));
		dna2 -> setChild(id2, tmp);
	} else if(childIndividual2 -> dna -> getChildrenNum() > 0)
	{
		dna1 = childIndividual2 -> dna -> getRandomWithChildren();
		int id = rand() % dna1 -> getChildrenNum();
		D* tmp = childIndividual1 -> dna;
		childIndividual1 -> dna = dna1 -> getChild(id);
		dna1 -> setChild(tmp);		
	} else if(childIndividual1 -> dna -> getChildrenNum() > 0)
	{
		dna1 = childIndividual1 -> dna -> getRandomWithChildren();
		int id = rand() % dna1 -> getChildrenNum();
		D* tmp = childIndividual2 -> dna;
		childIndividual2 -> dna = dna1 -> getChild(id);
		dna1 -> setChild(id, tmp);
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
void Genetic::TreeIndividual <D>::setScore(int value)
{
	score = value;
}

template <typename D>
int Genetic::TreeIndividual <D>::getScore()
{
	return score;
}

template <typename D>
void Genetic::TreeIndividual <D>::setDNA(D* value)
{
	dna = value;
}

template <typename D>
const D* Genetic::TreeIndividual <D>::getDNA() const
{
	return dna;
}

#endif // TREEINDIVIDUAL_H
