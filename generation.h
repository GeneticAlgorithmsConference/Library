
#ifndef GENERATION_H
#define GENERATION_H

#include <string>
#include <vector>
#include "individual.h"

namespace Genetic {


/**
 * class Generation
 *
 */

	template <typename Individual>
	class Generation
	{
	public:
		/**
		 * Empty Constructor
		 */
		Generation(int individualsNum);

		/**
		 * Empty Destructor
		 */
		virtual ~Generation();

		/**
		 */
		virtual void test();


		/**
		 * @param  seed
		 */
		void init();

	protected:

		std::vector <Individual*> individuals;
		int individualsNum;
		double mutationProbability;
		int mutationAttempts;
		int crossoverPointsNum;

	public:


		// Protected attribute accessor methods
		//


		/**
		 * Set the value of individuals
		 * @param new_var the new value of individuals
		 */
		void setIndividuals(const std::vector <Individual*>& value);

		/**
		 * Get the value of individuals
		 * @return the value of individuals
		 */
		std::vector <Individual*>& getIndividuals();

		/**
		 * Set the value of individualsNum
		 * @param new_var the new value of individualsNum
		 */
		void setIndividualsNum(int value);

		/**
		 * Get the value of individualsNum
		 * @return the value of individualsNum
		 */
		int getIndividualsNum();

		/**
		 * Set the value of mutationProbability
		 * @param new_var the new value of mutationProbability
		 */
		void setMutationProbability(double value);

		/**
		 * Get the value of mutationProbability
		 * @return the value of mutationProbability
		 */
		double getMutationProbability();

		/**
		 * Set the value of mutationAttempts
		 * @param new_var the new value of mutationAttempts
		 */
		void setMutationAttempts(int value);

		/**
		 * Get the value of mutationAttempts
		 * @return the value of mutationAttempts
		 */
		int getMutationAttempts();

		/**
		 * Set the value of crossoverPointsNum
		 * @param new_var the new value of crossoverPointsNum
		 */
		void setCrossoverPointsNum(int value);

		/**
		 * Get the value of crossoverPointsNum
		 * @return the value of crossoverPointsNum
		 */
		int getCrossoverPointsNum();
	};
}; // end of package namespace

template <typename Individual>
Genetic::Generation <Individual>::Generation(int _individualsNum)
{
	individualsNum = _individualsNum;

	Individual* tmpIndividual;

	for(int i = 0; i < individualsNum; ++i)
	{
		tmpIndividual = new Individual();
		individuals.push_back(tmpIndividual);
	}
}

template <typename Individual>
Genetic::Generation <Individual>::~Generation()
{
}

template <typename Individual>
void Genetic::Generation <Individual>::test()
{
}

template <typename Individual>
void Genetic::Generation <Individual>::init()
{
}

template <typename Individual>
void Genetic::Generation <Individual>::setIndividuals(const std::vector <Individual*>& value)
{
	individuals = value;
}

template <typename Individual>
std::vector <Individual*>& Genetic::Generation <Individual>::getIndividuals()
{
	return individuals;
}

template <typename Individual>
void Genetic::Generation <Individual>::setIndividualsNum(int value)
{
	individualsNum = value;
}

template <typename Individual>
int Genetic::Generation <Individual>::getIndividualsNum()
{
	return individualsNum;
}

template <typename Individual>
void Genetic::Generation <Individual>::setMutationProbability(double value)
{
	mutationProbability = value;
}

template <typename Individual>
double Genetic::Generation <Individual>::getMutationProbability()
{
	return mutationProbability;
}

template <typename Individual>
void Genetic::Generation <Individual>::setMutationAttempts(int value)
{
	mutationAttempts = value;
}

template <typename Individual>
int Genetic::Generation <Individual>::getMutationAttempts()
{
	return mutationAttempts;
}

template <typename Individual>
void Genetic::Generation <Individual>::setCrossoverPointsNum(int value)
{
	crossoverPointsNum = value;
}

template <typename Individual>
int Genetic::Generation <Individual>::getCrossoverPointsNum()
{
	return crossoverPointsNum;
}

#endif // GENERATION_H
