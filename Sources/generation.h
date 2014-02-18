
#ifndef GENERATION_H
#define GENERATION_H

#include <assert.h>
#include <vector>
#include <algorithm>
#include <math.h>

#include "individual.h"
#include "geneticsettings.h"

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

	template <typename I>
	class Generation
	{
	public:

		Generation(int _individualsNum, Genetic::GeneticSettings* _geneticSettings);
		~Generation();

		void genNext();
		void init(unsigned int seed, double dnaGenerationParameter);

	protected:

		std::vector <I*> individuals;
		int individualsNum;

		GeneticSettings* geneticSettings;

	public:

		/**
		 * Set the array of individuals
		 * @param new_var the new array of individuals
		 */
		void setIndividuals(const std::vector <I*>& value);

		/**
		 * Get the array of individuals
		 * @return the array of individuals
		 */
		std::vector <I*>& getIndividuals();

		/**
		 * Get the array of individuals sorted by score
		 * @return the array of individuals sorted by score
		 */
		std::vector <I*>& getIndividualsSorted();

		/**
		 * Get the best individual in generation
		 * @return the best individual in generation
		 */
		I* getIndividualBest();

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
		 * Set the value of individualsNum
		 * @param new_var the new value of individualsNum
		 */
		void setGeneticSettings(GeneticSettings* value);

		/**
		 * Get the value of individualsNum
		 * @return the value of individualsNum
		 */
		GeneticSettings* getGeneticSettings();
	};
}; // end of package namespace

template <typename I>
Genetic::Generation <I>::Generation(int _individualsNum, Genetic::GeneticSettings* _geneticSettings)
{
	individualsNum = _individualsNum;
	geneticSettings = _geneticSettings;
	assert(individualsNum % 2 == 0);
}

template <typename I>
Genetic::Generation <I>::~Generation()
{
	for(int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();
}

template <typename I>
void Genetic::Generation <I>::genNext()
{
	std::vector <I*> nextIndividuals(individualsNum);
	for(int i = 0; i < individualsNum; ++i)
	{
		nextIndividuals[i] = new I();
	}

    // Recombination
	switch(geneticSettings -> getParentsSelectionType())
	{
        case PANMIXIA:
        {
            int individualsNum = individuals.size();
            for(int i = 0; i < individualsNum / 2; ++i)
            {
                int firstParent = rand() % individualsNum;
                int secondParent = rand() % (individualsNum - 1);
                if(secondParent >= firstParent)
                {
                    ++secondParent;
                }
                I::recombine(individuals[firstParent], individuals[secondParent],
                                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
            }
            break;
        }
        case INBREEDING_FENOTYPE:
        {
            int firstParent, secondParent;
            double minDistance;
            double currentDistance;
            for(int i = 0; i < individualsNum / 2; ++i)
            {
                firstParent = rand() % individualsNum;

                minDistance = (firstParent == 0) ? (individuals[0] -> getDna().getDistance(individuals[1] -> getDna()))
                    : individuals[0] -> getDna().getDistance(individuals[firstParent] -> getDna());
                secondParent = (firstParent == 0) ? 1 : 0;
                for(int j = 0; j < individualsNum; ++j)
                {
                    if((j != firstParent)
                       && (minDistance > (currentDistance = individuals[firstParent]
                                          -> getDna().getDistance(individuals[j] -> getDna()))))
                    {
                        minDistance = currentDistance;
                        secondParent = j;
                    }
                }

                I::recombine(individuals[firstParent], individuals[secondParent],
                                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
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

                I::recombine(individuals[firstParent], individuals[secondParent],
                                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
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
                maxDistance = (firstParent == 0) ? (individuals[0] -> getDna().getDistance(individuals[1] -> getDna()))
                    : individuals[0] -> getDna().getDistance(individuals[firstParent] -> getDna());
                secondParent = (firstParent == 0) ? 1 : 0;
                for(int j = 0; j < individualsNum; ++j)
                {
                    if((j != firstParent)
                       && (maxDistance < (currentDistance = individuals[firstParent]
                                          -> getDna().getDistance(individuals[j] -> getDna()))))
                    {
                        maxDistance = currentDistance;
                        secondParent = j;
                    }
                }

                I::recombine(individuals[firstParent], individuals[secondParent],
                                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
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

                I::recombine(individuals[firstParent], individuals[secondParent],
                                      nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
            }
            break;
        }
	}

	// Testing
    // For old `parents`
	for(int i = 0; i < individualsNum; ++i)
	{
		individuals[i] -> test();
		nextIndividuals.push_back(individuals[i]);
	}
    // For new `children`
	for(int i = 0; i < individualsNum; ++i)
	{
		nextIndividuals[i] -> mutate(geneticSettings);
		nextIndividuals[i] -> test();
	}

	individuals.clear();
	sort(nextIndividuals.begin(), nextIndividuals.end(), individualComparator<I>);

	// Selection individuals for new generation.
	switch(geneticSettings -> getNewGenerationSelectionType())
	{
	case TRUNCATION_SELECTION:
	{
		int possibleIndividualsNum = individualsNum *
                                     (geneticSettings -> getGenerationSelectionParameter());
		std::vector <bool> used(nextIndividuals.size(), false);
		assert(possibleIndividualsNum != 0);
		for(int i = 0; i < individualsNum; ++i)
		{
			int currentId = rand() % possibleIndividualsNum;
			used[currentId] = true;
			I* tmp = new I();
			*tmp = *nextIndividuals[currentId];
			individuals.push_back(tmp);
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

	#ifdef ENABLE_DNALOG_BestPerStep
	dnalog << "Best: ";
	nextIndividuals[0] -> getDna().print();
	dnalog << " with score " << nextIndividuals[0] -> getScore() << std::endl;
	#endif

	nextIndividuals.clear();
}

template <typename I>
void Genetic::Generation <I>::init(unsigned int seed, double dnaGenerationParameter)
{
    srand(seed);

    for(int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();

	I* tmpIndividual;

	for(int i = 0; i < individualsNum; ++i)
	{
		tmpIndividual = new I();
		tmpIndividual -> generate(dnaGenerationParameter);
		tmpIndividual -> test();
		individuals.push_back(tmpIndividual);
	}
}

template <typename I>
void Genetic::Generation <I>::setIndividuals(const std::vector <I*>& value)
{
	individuals = value;
}

template <typename I>
std::vector <I*>& Genetic::Generation <I>::getIndividuals()
{
	return individuals;
}

template <typename I>
std::vector <I*>& Genetic::Generation <I>::getIndividualsSorted()
{
    std::vector <I*> ans = individuals;
	sort(ans.begin(), ans.end(), individualComparator<I>);
	return ans;
}

template <typename I>
I* Genetic::Generation <I>::getIndividualBest()
{
    assert(individuals.size() > 0);
    I* ans = individuals[0];
    for(int i = 1; i < individuals.size(); ++i)
        if(ans -> getScore() > individuals[i] -> getScore())
            ans = individuals[i];
    return ans;
}

template <typename I>
void Genetic::Generation <I>::setGeneticSettings(Genetic::GeneticSettings* value)
{
	geneticSettings = value;
}

template <typename I>
Genetic::GeneticSettings* Genetic::Generation <I>::getGeneticSettings()
{
	return geneticSettings;
}

#endif // GENERATION_H
