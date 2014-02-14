#ifndef GENETICSETTINGS_H_INCLUDED
#define GENETICSETTINGS_H_INCLUDED

#include <string>
#include <vector>

#include "genetic.h"

namespace Genetic {


/**
 * @class GeneticSettings
 * @brief Class 'GeneticSettings' contains all gentic settings used by evolution prcess.
 */


	class GeneticSettings
	{
	public:

        /// @name Constructor/destructor
        /// @{

		/**@brief
		 * Constructor. If no arguments are given, all genetic settings will be set to their defaults.
		 * The meaning of all parameters can be easily found in description of class attributes
		 */
		GeneticSettings(int _generationSize = 10, NewGenerationSelectionType _newGenerationSelectionType = ELITE_SELECTION,
             ParentsSelectionType _parentsSelectionType = PANMIXIA, RecombinationType _recombinationType = CROSSOVER);

		///@brief Destructor.
		~GeneticSettings();

        /// @}

    protected:

        /// @name New generation selection settings
        /// @{

        /// @brief
        /// Type of selection of individual for new generation that will be used in generating a new generation
		NewGenerationSelectionType newGenerationSelectionType;

        /// @brief
		/// A parameter which will be transmitted to the 'genNext' method of generation.
		/// Sence of this parameter depends on a used new generation selection type.
		double newGenerationSelectionParameter;

        /// @}
        /// @name Recombination settings
        /// @{

        /// @brief
        /// Type of parents selection that will be used
		ParentsSelectionType parentsSelectionType;

        /// @brief
        /// Type of recombination that will be used
		RecombinationType recombinationType;

        /// @brief
		/// A parameter which will be transmitted to the 'recombine' method.
		/// Sence of this parameter depends on a selected recombination method.
		double recombinationParameter;

        /// @}
        /// @name Mutation settings
        /// @{

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
		 * Set the value of newGenerationSelectionParameter
		 * @param value the new value of newGenerationSelectionParameter
		 */
		void setGenerationSelectionParameter(double value);

		/**@brief
		 * Get the value of newGenerationSelectionParameter
		 * @return the value of newGenerationSelectionParameter
		 */
		double getGenerationSelectionParameter();

		/**@brief
		 * Set the value of parentsSelectionType
		 * @param value the new value of parentsSelectionType
		 */
		void setParentsSelectionType(ParentsSelectionType value);

		/**@brief
		 * Get the value of parentsSelectionType
		 * @return the value of parentsSelectionType
		 */
		ParentsSelectionType getParentsSelectionType();

        /// @}
	};
};

Genetic::GeneticSettings::GeneticSettings(int _generationSize, NewGenerationSelectionType _newGenerationSelectionType,
                                             ParentsSelectionType _parentsSelectionType, RecombinationType _recombinationType)
{
    parentsSelectionType = _parentsSelectionType;
    newGenerationSelectionType = _newGenerationSelectionType;
    recombinationType = _recombinationType;

    newGenerationSelectionParameter = 1.0;
    recombinationParameter = 1.0;
    mutationProbability = 0.25;
    mutationParameter = 1.0;
    mutationAttempts = 1;
}

Genetic::GeneticSettings::~GeneticSettings()
{

}

void Genetic::GeneticSettings::setMutationProbability(double value)
{
	mutationProbability = value;
}

double Genetic::GeneticSettings::getMutationProbability()
{
	return mutationProbability;
}

void Genetic::GeneticSettings::setMutationAttempts(int value)
{
	mutationAttempts = value;
}

int Genetic::GeneticSettings::getMutationAttempts()
{
	return mutationAttempts;
}

void Genetic::GeneticSettings::setMutationParameter(double value)
{
	mutationParameter = value;
}

double Genetic::GeneticSettings::getMutationParameter()
{
	return mutationParameter;
}

void Genetic::GeneticSettings::setNewGenerationSelectionType( Genetic::NewGenerationSelectionType value)
{
	newGenerationSelectionType = value;
}

Genetic::NewGenerationSelectionType Genetic::GeneticSettings::getNewGenerationSelectionType()
{
	return newGenerationSelectionType;
}

void Genetic::GeneticSettings::setRecombinationType( Genetic::RecombinationType value)
{
	recombinationType = value;
}

Genetic::RecombinationType Genetic::GeneticSettings::getRecombinationType()
{
	return recombinationType;
}

void Genetic::GeneticSettings::setRecombinationParameter(double value)
{
	recombinationParameter = value;
}

double Genetic::GeneticSettings::getRecombinationParameter()
{
	return recombinationParameter;
}

void Genetic::GeneticSettings::setGenerationSelectionParameter(double value)
{
	newGenerationSelectionParameter = value;
}

double Genetic::GeneticSettings::getGenerationSelectionParameter()
{
	return newGenerationSelectionParameter;
}

void Genetic::GeneticSettings::setParentsSelectionType(ParentsSelectionType value)
{
	parentsSelectionType = value;
}

Genetic::ParentsSelectionType Genetic::GeneticSettings::getParentsSelectionType()
{
	return parentsSelectionType;
}

#endif // GENETICSETTINGS_H_INCLUDED
