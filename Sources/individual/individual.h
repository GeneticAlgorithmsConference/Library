
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "../dna/dna.h"
#include "base_individual.h"

namespace Genetic {

bool scoreComparator(BaseIndividual* individual1, BaseIndividual* individual2);

    /**
     * class Individual
     *
     */

	template <typename D, typename S>
	class Individual : public BaseIndividual
    {
	public:

	    Individual();
	    ~Individual();

	    virtual bool scoreLessThan(BaseIndividual* individual);
	    virtual bool dnaDistanceLessThan(Genetic::BaseIndividual* individual2,
	                                     Genetic::BaseIndividual* individual3,
	                                     Genetic::BaseIndividual* individual4);

        virtual void generate() = 0;

		virtual void test() = 0;

	public:

		S score;
		D dna;

    public:

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
		void setDna(D value);

		/**
		 * Get the value of dna
		 * @return the value of dna
		 */
		D& getDna();

	};
};

template <typename D, typename S>
Genetic::Individual <D, S>::Individual()
{

}

template <typename D, typename S>
Genetic::Individual <D, S>::~Individual()
{

}

template <typename D, typename S>
bool Genetic::Individual <D, S>::scoreLessThan(BaseIndividual* individual)
{
	Individual <D, S>* tmp_individual = dynamic_cast<Individual <D, S>*>(individual);
	return (score < tmp_individual->score);
}

template <typename D, typename S>
bool Genetic::Individual <D, S>::dnaDistanceLessThan(Genetic::BaseIndividual* individual2,
                                                     Genetic::BaseIndividual* individual3,
                                                     Genetic::BaseIndividual* individual4)
{
	Genetic::Individual <D, S>* tmp_individual1 = this;
	Genetic::Individual <D, S>* tmp_individual2 = dynamic_cast<Individual <D, S>*>(individual2);
	Genetic::Individual <D, S>* tmp_individual3 = dynamic_cast<Individual <D, S>*>(individual3);
	Genetic::Individual <D, S>* tmp_individual4 = dynamic_cast<Individual <D, S>*>(individual4);
	return (tmp_individual1->dna.getDistance(tmp_individual2->dna) <
	        tmp_individual3->dna.getDistance(tmp_individual4->dna));
}

template <typename D, typename S>
void Genetic::Individual <D, S>::setScore(S value)
{
	score = value;
}

template <typename D, typename S>
S Genetic::Individual <D, S>::getScore()
{
	return score;
}

template <typename D, typename S>
void Genetic::Individual <D, S>::setDna(D value)
{
	dna = value;
}

template <typename D, typename S>
D& Genetic::Individual <D, S>::getDna()
{
	return dna;
}

#endif // INDIVIDUAL_H
