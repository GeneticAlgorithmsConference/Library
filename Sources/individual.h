
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <iostream>

#include "genetic.h"
#include "geneticsettings.h"
#include "dna.h"

namespace Genetic {


    /**
     * class Individual
     *
     */

	template <typename D, typename S>
    class Individual
    {
	public:

	    Individual();
	    ~Individual();

        void generate(double dnaGenerationParameter);

		virtual void mutate(Genetic::GeneticSettings* geneticSettings) = 0;
		virtual void test() = 0;
		static void recombine(Genetic::Individual <D, S>* parent_individual1,
		                      Genetic::Individual <D, S>* parent_individual2,
		                      Genetic::Individual <D, S>* child_individual1,
		                      Genetic::Individual <D, S>* child_individual2,
		                      Genetic::GeneticSettings* geneticSettings);

	protected:

		S score;
		D* dna;

    public:

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
		D* getDna();

	};
};

template <typename D, typename S>
Genetic::Individual <D, S>::Individual()
{
    dna = new D();
}

template <typename D, typename S>
Genetic::Individual <D, S>::~Individual()
{
    delete dna;
}

template <typename D, typename S>
void Genetic::Individual <D, S>::generate(double dnaGenerationParameter)
{
    dna -> generate(dnaGenerationParameter);
}

template <typename D, typename S>
void Genetic::Individual <D, S>::setScore(double value)
{
	score = value;
}

template <typename D, typename S>
double Genetic::Individual <D, S>::getScore()
{
	return score;
}

template <typename D, typename S>
void Genetic::Individual <D, S>::setDna(D* value)
{
	dna = value;
}

template <typename D, typename S>
D* Genetic::Individual <D, S>::getDna()
{
	return dna;
}

#endif // INDIVIDUAL_H
