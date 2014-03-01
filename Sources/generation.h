
#ifndef GENERATION_H
#define GENERATION_H

#include <assert.h>
#include <vector>
#include <algorithm>
#include <math.h>

#include "individual/individual.h"
#include "genetic_settings.h"

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
		void init(unsigned int seed);

	protected:

		std::vector <Genetic::BaseIndividual*> individuals;
		int individualsNum;

		GeneticSettings* geneticSettings;

	public:

		/**
		 * Set the array of individuals
		 * @param new_var the new array of individuals
		 */
		void setIndividuals(const std::vector <Genetic::BaseIndividual*>& value);

		/**
		 * Get the array of individuals
		 * @return the array of individuals
		 */
		std::vector <Genetic::BaseIndividual*>& getIndividuals();

		/**
		 * Get the array of individuals sorted by score
		 * @return the array of individuals sorted by score
		 */
		std::vector <Genetic::BaseIndividual*> getIndividualsSorted();

		/**
		 * Get the best individual in generation
		 * @return the best individual in generation
		 */
		Genetic::BaseIndividual* getIndividualBest();

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
    for(unsigned int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();
}

template <typename I>
void Genetic::Generation <I>::genNext()
{
	std::vector <Genetic::BaseIndividual*> nextIndividuals(individualsNum);
	for(unsigned int i = 0; i < nextIndividuals.size(); ++i)
	{
		nextIndividuals[i] = new I();
	}

	geneticSettings->getParentsSelection()->process(individuals, nextIndividuals,
	                                                geneticSettings->getRecombination());

    // Recombination
	// switch(geneticSettings -> getParentsSelectionType())
	// {
    //     case INBREEDING_GENOTYPE:
    //     {
    //         int firstParent, secondParent;
    //         double minDistance;
    //         double currentDistance;
    //         for(int i = 0; i < individualsNum / 2; ++i)
    //         {
    //             firstParent = rand() % individualsNum;
    //             minDistance = (firstParent == 0) ? fabs(individuals[0] -> getScore() - individuals[1] -> getScore())
    //                 : fabs(individuals[0] -> getScore() - individuals[firstParent] -> getScore());
    //             secondParent = (firstParent == 0) ? 1 : 0;
    //             for(int j = 0; j < individualsNum; ++j)
    //             {
    //                 if((j != firstParent)
    //                    && (minDistance > (currentDistance =
    //                                       fabs(individuals[firstParent] -> getScore() - individuals[j] -> getScore()))))
    //                 {
    //                     minDistance = currentDistance;
    //                     secondParent = j;
    //                 }
    //             }

    //             I::recombine(individuals[firstParent], individuals[secondParent],
    //                                   nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
    //         }
    //         break;
    //     }
    //     case OUTBREEDING_FENOTYPE:
    //     {
    //         int firstParent, secondParent;
    //         double maxDistance;
    //         double currentDistance;
    //         for(int i = 0; i < individualsNum / 2; ++i)
    //         {
    //             firstParent = rand() % individualsNum;
    //             maxDistance = (firstParent == 0) ? (individuals[0] -> getDna().getDistance(individuals[1] -> getDna()))
    //                 : individuals[0] -> getDna().getDistance(individuals[firstParent] -> getDna());
    //             secondParent = (firstParent == 0) ? 1 : 0;
    //             for(int j = 0; j < individualsNum; ++j)
    //             {
    //                 if((j != firstParent)
    //                    && (maxDistance < (currentDistance = individuals[firstParent]
    //                                       -> getDna().getDistance(individuals[j] -> getDna()))))
    //                 {
    //                     maxDistance = currentDistance;
    //                     secondParent = j;
    //                 }
    //             }

    //             I::recombine(individuals[firstParent], individuals[secondParent],
    //                                   nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
    //         }
    //         break;
    //     }
    //     case OUTBREEDING_GENOTYPE:
    //     {
    //         int firstParent, secondParent;
    //         double maxDistance;
    //         double currentDistance;
    //         for(int i = 0; i < individualsNum / 2; ++i)
    //         {
    //             firstParent = rand() % individualsNum;
    //             maxDistance = (firstParent == 0) ? fabs(individuals[0] -> getScore() - individuals[1] -> getScore())
    //                 : fabs(individuals[0] -> getScore() - individuals[firstParent] -> getScore());
    //             secondParent = (firstParent == 0) ? 1 : 0;
    //             for(int j = 0; j < individualsNum; ++j)
    //             {
    //                 if((j != firstParent)
    //                    && (maxDistance < (currentDistance =
    //                                       fabs(individuals[firstParent] -> getScore() - individuals[j] -> getScore()))))
    //                 {
    //                     maxDistance = currentDistance;
    //                     secondParent = j;
    //                 }
    //             }

    //             I::recombine(individuals[firstParent], individuals[secondParent],
    //                                   nextIndividuals[i * 2], nextIndividuals[i * 2 + 1], geneticSettings);
    //         }
    //         break;
    //     }
	// }

	// Mutations
	for(unsigned int i = 0; i < nextIndividuals.size(); ++i)
	{
		geneticSettings->getMutation()->process(dynamic_cast<I*>(nextIndividuals[i])->getDna());
	}

	// Testing
	geneticSettings->getFunctionCalculator()->process(nextIndividuals);
	for(unsigned int i = 0; i < individuals.size(); ++i)
	{
		nextIndividuals.push_back(individuals[i]);
	}

	// Select new generation
	individuals.clear();
	sort(nextIndividuals.begin(), nextIndividuals.end(), Genetic::scoreComparator);
	geneticSettings->getNewGenerationSelection()->process(nextIndividuals, individuals);

	// Clear memory
	for(unsigned int i = 0; i < nextIndividuals.size(); ++i)
	{
		bool selected = false;
		for(unsigned int j = 0; j < individuals.size(); ++j)
		{
			if(nextIndividuals[i] == individuals[j])
			{
				selected = true;
				break;
			}
		}
		if(!selected)
		{
			delete nextIndividuals[i];
		}
	}

	#ifdef ENABLE_LOG
	dnalog << "Best: ";
	dynamic_cast<I*>(nextIndividuals[0])->getDna().print();
	dnalog << " with score " << dynamic_cast<I*>(nextIndividuals[0])->getScore() << std::endl;
	#endif
}

template <typename I>
void Genetic::Generation <I>::init(unsigned int seed)
{
    srand(seed);

    for(unsigned int i = 0; i < individuals.size(); ++i)
	{
		delete individuals[i];
	}
	individuals.clear();

	BaseIndividual* tmpIndividual;

	for(int i = 0; i < individualsNum; ++i)
	{
		tmpIndividual = new I();
		tmpIndividual->generate();
		tmpIndividual->test();
		individuals.push_back(tmpIndividual);
	}
}

template <typename I>
	void Genetic::Generation <I>::setIndividuals(const std::vector <Genetic::BaseIndividual*>& value)
{
	individuals = value;
}

template <typename I>
	std::vector <Genetic::BaseIndividual*>& Genetic::Generation <I>::getIndividuals()
{
	return individuals;
}

template <typename I>
	std::vector <Genetic::BaseIndividual*> Genetic::Generation <I>::getIndividualsSorted()
{
    std::vector <BaseIndividual*> ans = individuals;
    sort(ans.begin(), ans.end(), scoreComparator);
	return ans;
}

template <typename I>
	Genetic::BaseIndividual* Genetic::Generation <I>::getIndividualBest()
{
	assert(individuals.size() > 0);
	I* ans = dynamic_cast<I*>(individuals[0]);
	for(int i = 1; i < individuals.size(); ++i)
	{
	if(ans->getScore() > dynamic_cast<I*>(individuals[i])->getScore())
	{
	ans = dynamic_cast<I*>(individuals[i]);
}
       
}
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
