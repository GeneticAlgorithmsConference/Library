
#ifndef GENERATION_H
#define GENERATION_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "individual.h"

template <class T>
bool individualComparator(T* i1, T* i2)
{
	return (i1 -> getScore() < i2 -> getScore());
}

using std::endl;

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
		Generation(int _individualsNum);

		/**
		 * Empty Destructor
		 */
		virtual ~Generation();

		/**
		 */
		virtual void test();

		void genNext(RecombinationType recombinationType, double recombinationParameter, int crossover_points_num,
                     double mutationProbability, int mutationAttempts, double mutationParameter);

		/**
		 * @param  parameter for dna generator
		 */
		void init(double dnaGenerateParameter);

	protected:

		std::vector <Individual*> individuals;
		int individualsNum;

	public:

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
	};
}; // end of package namespace

template <typename Individual>
Genetic::Generation <Individual>::Generation(int _individualsNum)
{
    for(int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();

	individualsNum = _individualsNum;
	assert(individualsNum % 2 == 0);
}

template <typename Individual>
Genetic::Generation <Individual>::~Generation()
{
	for(int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();
}

template <typename Individual>
void Genetic::Generation <Individual>::test()
{
}

template <typename Individual>
void Genetic::Generation <Individual>::genNext(RecombinationType recombinationType, double recombinationParameter, int crossover_points_num,
                                               double mutationProbability, int mutationAttempts, double mutationParameter)
{
	std::vector <Individual*> nextIndividuals(individualsNum);
	for(int i = 0; i < individualsNum; ++i)
	{
		nextIndividuals[i] = new Individual(false);
	}

    // Recombination
	int firstParent, secondParent;
	for(int i = 0; i < individualsNum / 2; ++i)
	{
		firstParent = rand() % individualsNum;
		secondParent = rand() % (individualsNum - 1);
		if(secondParent >= firstParent)
		{
			++secondParent;
		}

//		 dnalog << "Before:" << endl;;
//		 individuals[firstParent] -> getDna() -> print();
//		 dnalog << endl;
//		 individuals[secondParent] -> getDna() -> print();
//		 dnalog << endl;
//		 nextIndividuals[i * 2] -> getDna() -> print();
//		 dnalog << endl;
//		 nextIndividuals[i * 2 + 1] -> getDna() -> print();
//		 dnalog << endl;

		 Individual::recombine(individuals[firstParent], individuals[secondParent],
		                       nextIndividuals[i * 2], nextIndividuals[i * 2 + 1],
                               recombinationType, recombinationParameter, crossover_points_num);

//		 dnalog << "After:" << endl;
//		 individuals[firstParent] -> getDna() -> print();
//		 dnalog << endl;
//		 individuals[secondParent] -> getDna() -> print();
//		 dnalog << endl;
//		 nextIndividuals[i * 2] -> getDna() -> print();
//		 dnalog << endl;
//		 nextIndividuals[i * 2 + 1] -> getDna() -> print();
//		 dnalog << endl;
	}

	// Testing
	for(int i = 0; i < individualsNum; ++i)
	{
		nextIndividuals.push_back(individuals[i]);
		individuals[i] -> test();
		nextIndividuals[i] -> mutate(mutationProbability, mutationAttempts, mutationParameter);
		nextIndividuals[i] -> test();
	}

	individuals.clear();
	sort(nextIndividuals.begin(), nextIndividuals.end(), individualComparator<Individual>);
	dnalog << "Best: ";
    nextIndividuals[0] -> getDna() -> print();
    dnalog << " with score " << nextIndividuals[0] -> getScore() << std::endl;
	for(int i = 0; i < individualsNum; ++i)
	{
		individuals.push_back(nextIndividuals[i]);
		delete nextIndividuals[individualsNum + i];
	}
	nextIndividuals.clear();
}

template <typename Individual>
void Genetic::Generation <Individual>::init(double dnaGenerateParameter)
{
	Individual* tmpIndividual;

	for(int i = 0; i < individualsNum; ++i)
	{
		tmpIndividual = new Individual(true, dnaGenerateParameter);
		individuals.push_back(tmpIndividual);
	}
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

#endif // GENERATION_H
