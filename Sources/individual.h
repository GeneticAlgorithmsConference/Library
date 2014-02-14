
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

namespace Genetic {


    /**
     * class Individual
     *
     */

    template <typename D>
    class Individual
    {
	public:

	    Individual() {};

		virtual void test() = 0;

		static void recombine(Genetic::Individual <D>* parent_individual1,
		                      Genetic::Individual <D>* parent_individual2,
		                      Genetic::Individual <D>* child_individual1,
		                      Genetic::Individual <D>* child_individual2,
		                      Genetic::GeneticSettings* geneticSettings);

        virtual void generate(double dnaGenerationParameter) = 0;

		void mutate(Genetic::GeneticSettings* geneticSettings);

	protected:

		double score;	///< Score value
		D dna;

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
		void setDna(D& value);

		/**
		 * Get the value of dna
		 * @return the value of dna
		 */
		D* getDna();

	};
};

template <typename D>
void Genetic::Individual <D>::mutate(Genetic::GeneticSettings* geneticSettings)
{
    int attempts = geneticSettings -> getMutationAttempts();
    double probability = geneticSettings -> getMutationProbability();
    double parameter = geneticSettings -> getMutationParameter();

	for(int attemptNo = 0; attemptNo < attempts; ++attemptNo)
	{
	    double rndVal = static_cast<double>(rand() % 10000) / 10000.0;
		if(rndVal <= probability)
		{
		    dna.mutate(parameter);
		}
	}
}

template <typename D>
void Genetic::Individual <D>::setScore(double value)
{
	score = value;
}

template <typename D>
double Genetic::Individual <D>::getScore()
{
	return score;
}

template <typename D>
void Genetic::Individual <D>::setDna(D& value)
{
	dna = value;
}

template <typename D>
D* Genetic::Individual <D>::getDna()
{
	return &dna;
}

#endif // INDIVIDUAL_H
