
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
 * @class Generation
 * This class implements a single generation.
 */

	template <typename Individual, typename ParentsSelection>
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

		void genNext(ParentsSelectionType parentSelectionType,
		             NewGenerationSelectionType newGenerationSelectionType,
		             double truncationParameter);

		/**
		 * @param  parameter for dna generator
		 */
		void init();

	protected:

		ParentsSelection parentsSelection;

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

template <typename Individual, typename ParentsSelection>
Genetic::Generation <Individual, ParentsSelection>::Generation(int _individualsNum)
{
	individualsNum = _individualsNum;
	assert(individualsNum % 2 == 0);
}

template <typename Individual, typename ParentsSelection>
Genetic::Generation <Individual, ParentsSelection>::~Generation()
{
	for(int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();
}

template <typename Individual, typename ParentsSelection>
void Genetic::Generation <Individual, ParentsSelection>::test()
{
}

template <typename Individual, typename ParentsSelection>
void Genetic::Generation <Individual, ParentsSelection>::genNext(ParentsSelectionType parentsSelectionType,
                                                                 NewGenerationSelectionType newGenerationSelectionType,
                                                                 double truncationParameter)
{
	std::vector <Individual*> nextIndividuals(individualsNum);
	for(int i = 0; i < individualsNum; ++i)
	{
		nextIndividuals[i] = new Individual(false);
	}
	parentsSelection.process(individuals, nextIndividuals);
	switch(parentsSelectionType)
	{
	case INBREEDING_FENOTYPE:
	{
		int firstParent, secondParent;
		double minDistance;
		double currentDistance;
		for(int i = 0; i < individualsNum / 2; ++i)
		{
			firstParent = rand() % individualsNum;
			minDistance = (firstParent == 0) ? (individuals[0] -> getDna() -> getDistance(individuals[1] -> getDna()))
				: individuals[0] -> getDna() -> getDistance(individuals[firstParent] -> getDna());
			secondParent = (firstParent == 0) ? 1 : 0;
			for(int j = 0; j < individualsNum; ++j)
			{
				if((j != firstParent)
				   && (minDistance > (currentDistance = individuals[firstParent]
				                      -> getDna() -> getDistance(individuals[j] -> getDna()))))
				{
					minDistance = currentDistance;
					secondParent = j;
				}
			}

			Individual::recombine(individuals[firstParent], individuals[secondParent],
			                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1]);
		}
		break;
	}
	case INBREEDING_GENOTYPE:
	{
		int firstParent, secondParent;
		double minDistance;
		double currentDistance;
		for(int i = 0; i < individualsNum / 2; ++i)
		{
			firstParent = rand() % individualsNum;
			minDistance = (firstParent == 0) ? fabs(individuals[0] -> getScore() - individuals[1] -> getScore())
				: fabs(individuals[0] -> getScore() - individuals[firstParent] -> getScore());
			secondParent = (firstParent == 0) ? 1 : 0;
			for(int j = 0; j < individualsNum; ++j)
			{
				if((j != firstParent)
				   && (minDistance > (currentDistance =
				                      fabs(individuals[firstParent] -> getScore() - individuals[j] -> getScore()))))
				{
					minDistance = currentDistance;
					secondParent = j;
				}
			}

			Individual::recombine(individuals[firstParent], individuals[secondParent],
			                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1]);
		}
		break;
	}
	case OUTBREEDING_FENOTYPE:
	{
		int firstParent, secondParent;
		double maxDistance;
		double currentDistance;
		for(int i = 0; i < individualsNum / 2; ++i)
		{
			firstParent = rand() % individualsNum;
			maxDistance = (firstParent == 0) ? (individuals[0] -> getDna() -> getDistance(individuals[1] -> getDna()))
				: individuals[0] -> getDna() -> getDistance(individuals[firstParent] -> getDna());
			secondParent = (firstParent == 0) ? 1 : 0;
			for(int j = 0; j < individualsNum; ++j)
			{
				if((j != firstParent)
				   && (maxDistance < (currentDistance = individuals[firstParent]
				                      -> getDna() -> getDistance(individuals[j] -> getDna()))))
				{
					maxDistance = currentDistance;
					secondParent = j;
				}
			}

			Individual::recombine(individuals[firstParent], individuals[secondParent],
			                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1]);
		}
		break;
	}
	case OUTBREEDING_GENOTYPE:
	{
		int firstParent, secondParent;
		double maxDistance;
		double currentDistance;
		for(int i = 0; i < individualsNum / 2; ++i)
		{
			firstParent = rand() % individualsNum;
			maxDistance = (firstParent == 0) ? fabs(individuals[0] -> getScore() - individuals[1] -> getScore())
				: fabs(individuals[0] -> getScore() - individuals[firstParent] -> getScore());
			secondParent = (firstParent == 0) ? 1 : 0;
			for(int j = 0; j < individualsNum; ++j)
			{
				if((j != firstParent)
				   && (maxDistance < (currentDistance =
				                      fabs(individuals[firstParent] -> getScore() - individuals[j] -> getScore()))))
				{
					maxDistance = currentDistance;
					secondParent = j;
				}
			}

			Individual::recombine(individuals[firstParent], individuals[secondParent],
			                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1]);
		}
		break;
	}
	}

	// Testing
	for(int i = 0; i < individualsNum; ++i)
	{
		nextIndividuals.push_back(individuals[i]);
		individuals[i] -> test();
		nextIndividuals[i] -> mutate();
		nextIndividuals[i] -> test();
	}

	individuals.clear();
	sort(nextIndividuals.begin(), nextIndividuals.end(), individualComparator<Individual>);
	// Selection individuals for new generation.
	switch(newGenerationSelectionType)
	{
	case TRUNCATION_SELECTION:
	{
		int possibleIndividualsNum = individualsNum * truncationParameter;
		std::vector <bool> used(nextIndividuals.size(), false);
		assert(possibleIndividualsNum != 0);
		for(int i = 0; i < individualsNum; ++i)
		{
			int currentId = rand() % possibleIndividualsNum;
			used[currentId] = true;
			Individual* tmp = new Individual(false);
			*tmp = *nextIndividuals[currentId];
			individuals.push_back(tmp);
		}
		for(int i = 0; i < nextIndividuals.size(); ++i)
		{
			delete nextIndividuals[i];
		}
		break;
	}
	case ELITE_SELECTION:
	{
		for(int i = 0; i < individualsNum; ++i)
		{
			individuals.push_back(nextIndividuals[i]);
			delete nextIndividuals[individualsNum + i];
		}
		break;
	}
	default:
		break;
	}
	dnalog << "Best: ";
	nextIndividuals[0] -> getDna() -> print();
	dnalog << " with score " << nextIndividuals[0] -> getScore() << std::endl;
	nextIndividuals.clear();
}

template <typename Individual, typename ParentsSelection>
void Genetic::Generation <Individual, ParentsSelection>::init()
{
	Individual* tmpIndividual;

	for(int i = 0; i < individualsNum; ++i)
	{
		tmpIndividual = new Individual(true);
		tmpIndividual -> test();
		individuals.push_back(tmpIndividual);
	}
}

template <typename Individual, typename ParentsSelection>
void Genetic::Generation <Individual, ParentsSelection>::setIndividuals(const std::vector <Individual*>& value)
{
	individuals = value;
}

template <typename Individual, typename ParentsSelection>
std::vector <Individual*>& Genetic::Generation <Individual, ParentsSelection>::getIndividuals()
{
	return individuals;
}

template <typename Individual, typename ParentsSelection>
void Genetic::Generation <Individual, ParentsSelection>::setIndividualsNum(int value)
{
	individualsNum = value;
}

template <typename Individual, typename ParentsSelection>
int Genetic::Generation <Individual, ParentsSelection>::getIndividualsNum()
{
	return individualsNum;
}

#endif // GENERATION_H
