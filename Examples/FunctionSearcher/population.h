
#ifndef POPULATION_H
#define POPULATION_H

#include <string>
#include <vector>

#include "genetic.h"

namespace Genetic {


/**
 * @class Population
 * @brief Class 'Population' contains all gentic settings and a pointer to the current Generation.
 */

	template <typename Generation>
	class Population
	{
	public:

        /// @name Constructor/destructor
        /// @{

		/**@brief
		 * Constructor. If no arguments are given, all genetic settings will be set to their defaults.
		 * The meaning of all parameters can be easily found in description of class attributes
		 */
		Population(int _generationSize = 10, NewGenerationSelectionType _newGenerationSelectionType = ELITE_SELECTION,
             ParentsSelectionType _parentsSelectionType = PANMIXIA, RecombinationType _recombinationType = CROSSOVER);

		///@brief Destructor. Deletes current generation.
		~Population();

        /// @}
        /// @name Working with generation
        /// @{

		/**@brief
         * Initialize a new generation. This method kills all individuals in current generation (if they exist) and
         * generates new ones.
		 * @param seed Seed which is used for random initialization.
		 * @param dnaGenerateParameter An argument which will be transmitted to the DNA generator
		 */
		void initGeneration(unsigned int seed);

		/**@brief
		 * Generates next generation by calling genNext method for current genertion
		 * with genetic settings that where set for the instance of this class.
		 */
		void genNextGeneration();

        /**@brief
		 * Set the value of currentGeneration
		 * @param value the new value of currentGeneration
		 */
		void setCurrentGeneration(Generation* value);

		/**@brief
		 * Get the value of currentGeneration
		 * @return the value of currentGeneration
		 */
		Generation* getCurrentGeneration();
        /// @}

	protected:

        /// @name Generation
        /// @{

        /// @brief
        /// A pointer on the current generation
		Generation* currentGeneration;

        /// @brief
        /// A number of individuals in each generation
		int generationSize;

        /// @}
        /// @name Genetic settings
        /// @{

        /// @brief
        /// Type of selection of individual for new generation that will be used in generating a new generation
		NewGenerationSelectionType newGenerationSelectionType;

        /// @brief
		/// A parameter which will be transmitted to the 'genNext' method of generation.
		/// Sence of this parameter depends on a used new generation selection type.
		double newGenerationSelectionParameter;

        /// @brief
        /// Type of parents selection that will be used
		RecombinationType parentsSelectionType;

        /// @brief
        /// Type of recombination that will be used
		RecombinationType recombinationType;

        /// @brief
		/// A parameter which will be transmitted to the 'recombine' method.
		/// Sence of this parameter depends on a selected recombination method.
		double recombinationParameter;

        /// @brief
        /// Type of recombination that will be used in generating a new generation
        /// It influence the average number of 'good' mutation attempts per individual.
		double mutationProbability;

        /// @brief
        /// A number of attempts to mutate per each individual.
        /// It influence the average number of 'good' mutation attempts per individual
        /// and the maximum count of them.
		int mutationAttempts;

        /// @brief
		/// A parameter which will be transmitted to the 'mutate' method.
		/// Sence of this parameter depends on a used DNA type (DNA`s mutation type).
		double mutationParameter;


        /// @}

	public:

        /// @name Setiing/getting genetic settings
        /// @{

		/**@brief
		 * Set the value of newGenerationSelectionType
		 * @param value the new value of newGenerationSelectionType
		 */
		void setNewGenerationSelectionType(NewGenerationSelectionType value);

		/**@brief
		 * Get the value of newGenerationSelectionType
		 * @return the value of newGenerationSelectionType
		 */
		NewGenerationSelectionType getNewGenerationSelectionType();

		/**@brief
		 * Set the value of recombinationType
		 * @param value the new value of recombinationType
		 */
		void setRecombinationType(RecombinationType value);

		/**@brief
		 * Get the value of recombinationType
		 * @return the value of recombinationType
		 */
		RecombinationType getRecombinationType();

		/**@brief
		 * Set the value of recombinationParameter
		 * @param value the new value of recombinationParameter
		 */
		void setRecombinationParameter(double value);

		/**@brief
		 * Get the value of recombinationParameter
		 * @return the value of recombinationParameter
		 */
		double getRecombinationParameter();

		/**@brief
		 * Set the value of mutationParameter
		 * @param value the new value of mutationParameter
		 */
		void setMutationParameter(double value);

		/**@brief
		 * Get the value of mutationParameter
		 * @return the value of mutationParameter
		 */
		double getMutationParameter();

		/**@brief
		 * Set the value of mutationProbability
		 * @param value the new value of mutationProbability
		 */
		void setMutationProbability(double value);

		/**@brief
		 * Get the value of mutationProbability
		 * @return the value of mutationProbability
		 */
		double getMutationProbability();

		/**@brief
		 * Set the value of mutationAttempts
		 * @param value the new value of mutationAttempts
		 */
		void setMutationAttempts(int value);

		/**@brief
		 * Get the value of mutationAttempts
		 * @return the value of mutationAttempts
		 */
		int getMutationAttempts();

		/**@brief
		 * Set the value of selectionParameter
		 * @param value the new value of selectionParameter
		 */
		void setSelectionParameter(double value);

		/**@brief
		 * Get the value of selectionParameter
		 * @return the value of selectionParameter
		 */
		double getSelectionParameter();

        /// @}
	};
};



template <typename Generation>
Genetic::Population <Generation>::Population(int _generationSize, NewGenerationSelectionType _newGenerationSelectionType,
                                             ParentsSelectionType _parentsSelectionType, RecombinationType _recombinationType)
{
    currentGeneration = nullptr;
    generationSize = _generationSize;
    parentsSelectionType = _parentsSelectionType;
    newGenerationSelectionType = _newGenerationSelectionType;
    recombinationType = _recombinationType;

    selectionParameter = 1.0;
    recombinationParameter = 1.0;
    mutationProbability = 0.25;
    mutationParameter = 1.0;
    mutationAttempts = 1;
}

template <typename Generation>
Genetic::Population <Generation>::~Population()
{
	delete currentGeneration;
}

template <typename Generation>
void Genetic::Population <Generation>::initGeneration(unsigned int seed)
{
	srand(seed);
	if(currentGeneration != nullptr)
	{
		delete currentGeneration;
	}
	currentGeneration = new Generation(generationSize);
	currentGeneration -> init();
}

template <typename Generation>
void Genetic::Population <Generation>::genNextGeneration()
{
	currentGeneration -> genNext(newGenerationSelectionType, parentsSelectionType, recombinationType,
                              );
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

template <typename Generation>
void Genetic::Population <Generation>::setNewGenerationSelectionType( Genetic::NewGenerationSelectionType value)
{
	newGenerationSelectionType = value;
}

template <typename Generation>
 Genetic::NewGenerationSelectionType Genetic::Population <Generation>::getNewGenerationSelectionType()
{
	return newGenerationSelectionType;
}

template <typename Generation>
void Genetic::Population <Generation>::setRecombinationType( Genetic::RecombinationType value)
{
	recombinationType = value;
}

template <typename Generation>
Genetic::RecombinationType Genetic::Population <Generation>::getRecombinationType()
{
	return recombinationType;
}

template <typename Generation>
void Genetic::Population <Generation>::setRecombinationParameter(double value)
{
	recombinationParameter = value;
}

template <typename Generation>
double Genetic::Population <Generation>::getRecombinationParameter()
{
	return recombinationParameter;
}

template <typename Generation>
void Genetic::Population <Generation>::setSelectionParameter(double value)
{
	SelectionParameter = value;
}

template <typename Generation>
double Genetic::Population <Generation>::getSelectionParameter()
{
	return SelectionParameter;
}

#endif // POPULATION_H
