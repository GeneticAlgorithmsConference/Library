
#ifndef POPULATION_H
#define POPULATION_H

#include <string>
#include <vector>

#include "genetic.h"

namespace Genetic {


/**
 * class Population
 *
 */

	template <typename Generation>
	class Population
	{
	public:

		/// Empty constructor
		Population();

		Population(int _generationSize, NewPopulationSelectionType _selectionType = ELITE_SELECTION);

		/**
		 * Empty Destructor
		 */
		virtual ~Population();

		/**
		 * @param  seed
		 */
		void init(unsigned int seed, double dnaGenerateParameter = 10.0);


		/**
		 */
		void genNextGeneration();

	protected:

		Generation* currentGeneration;
		int generationSize;
		NewPopulationSelectionType selectionType;

		RecombinationType recombinationType;
		double recombinationParameter;
		int crossover_points_num;

		double mutationProbability;
		int mutationAttempts;
		double mutationParameter;

	public:

		/**
		 * Set the value of currentGeneration
		 * @param new_var the new value of currentGeneration
		 */
		void setCurrentGeneration(Generation* value);

		/**
		 * Get the value of currentGeneration
		 * @return the value of currentGeneration
		 */
		Generation* getCurrentGeneration();

		/**
		 * Set the value of mutationParameter
		 * @param new_var the new value of mutationParameter
		 */
		void setMutationParameter(double value);

		/**
		 * Get the value of mutationParameter
		 * @return the value of mutationParameter
		 */
		double getMutationParameter();

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

	};
};

template <typename Generation>
Genetic::Population <Generation>::Population()
{
	currentGeneration = nullptr;
	generationSize = 10;
	selectionType = ELITE_SELECTION;

	recombinationType = CROSSOVER;
	crossover_points_num = 1;
	recombinationParameter = 1;

	mutationProbability = 0.3;
	mutationParameter = 3;
	mutationAttempts = 1;
}

template <typename Generation>
Genetic::Population <Generation>::Population(int _generationSize,
                                             NewPopulationSelectionType _selectionType)
{
	currentGeneration = nullptr;
	generationSize = _generationSize;
	selectionType = _selectionType;
}

template <typename Generation>
Genetic::Population <Generation>::~Population()
{
	delete currentGeneration;
}

template <typename Generation>
void Genetic::Population <Generation>::init(unsigned int seed, double dnaGenerateParameter)
{
	srand(seed);
	if(currentGeneration != nullptr)
	{
		delete currentGeneration;
	}
	currentGeneration = new Generation(generationSize);
	currentGeneration -> init(dnaGenerateParameter);
}

template <typename Generation>
void Genetic::Population <Generation>::genNextGeneration()
{
	currentGeneration -> genNext(recombinationType,
                                 recombinationParameter,
                                 crossover_points_num,
                                 mutationProbability,
                                 mutationAttempts,
                                 mutationParameter);
}

template <typename Generation>
void Genetic::Population <Generation>::setCurrentGeneration(Generation* value)
{
	currentGeneration = value;
}

template <typename Generation>
Generation* Genetic::Population <Generation>::getCurrentGeneration()
{
	return currentGeneration;
}

template <typename Generation>
void Genetic::Population <Generation>::setMutationProbability(double value)
{
	mutationProbability = value;
}

template <typename Generation>
double Genetic::Population <Generation>::getMutationProbability()
{
	return mutationProbability;
}

template <typename Generation>
void Genetic::Population <Generation>::setMutationAttempts(int value)
{
	mutationAttempts = value;
}

template <typename Generation>
int Genetic::Population <Generation>::getMutationAttempts()
{
	return mutationAttempts;
}
template <typename Generation>
void Genetic::Population <Generation>::setMutationParameter(double value)
{
	mutationParameter = value;
}

template <typename Generation>
double Genetic::Population <Generation>::getMutationParameter()
{
	return mutationParameter;
}

#endif // POPULATION_H
