#ifndef GENETIC_SETTINGS_H
#define GENETIC_SETTINGS_H

#include <string>
#include <vector>

#include "new_generation_selection/new_generation_selection.h"
#include "parents_selection/parents_selection.h"
#include "recombination/recombination.h"
#include "mutation/mutation.h"
#include "function_calculator.h"

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
	GeneticSettings();

	/**@brief
	 * Constructor. If no arguments are given, all genetic settings will be set to their defaults.
	 * The meaning of all parameters can be easily found in description of class attributes
	 */
	GeneticSettings(int _generationSize);

	///@brief Destructor.
	~GeneticSettings();

	/// @}

protected:
	int generationSize;

	/// @name Recombination settings
	/// @{

	/// @brief
	/// Type of parents selection that will be used
	Genetic::ParentsSelection* parentsSelection;

	/// @brief
	/// Type of recombination that will be used
	Genetic::Recombination* recombination;

	/// @}

	Genetic::Mutation* mutation;

	Genetic::FunctionCalculator* functionCalculator;

	/// @name New generation selection settings
	/// @{

	/// @brief
	/// Type of selection of individual for new generation that will be used in generating a new generation
	Genetic::NewGenerationSelection* newGenerationSelection;

	/// @}

public:

	/// @name Setiing/getting genetic settings
	/// @{

	/**@brief
	 * Set the value of newGenerationSelectionType
	 * @param value the new value of newGenerationSelectionType
	 */
	void setNewGenerationSelection(Genetic::NewGenerationSelection* value);

	/**@brief
	 * Get the value of newGenerationSelectionType
	 * @return the value of newGenerationSelectionType
	 */
	Genetic::NewGenerationSelection* getNewGenerationSelection();

	/**@brief
	 * Set the value of recombinationType
	 * @param value the new value of recombinationType
	 */
	void setRecombination(Genetic::Recombination* value);

	/**@brief
	 * Get the value of recombinationType
	 * @return the value of recombinationType
	 */
	Genetic::Recombination* getRecombination();

	/**@brief
	 * Set the value of parentsSelectionType
	 * @param value the new value of parentsSelectionType
	 */
	void setParentsSelection(Genetic::ParentsSelection* value);

	/**@brief
	 * Get the value of parentsSelectionType
	 * @return the value of parentsSelectionType
	 */
	Genetic::ParentsSelection* getParentsSelection();

	void setMutation(Genetic::Mutation* value);
	Genetic::Mutation* getMutation();

	void setFunctionCalculator(Genetic::FunctionCalculator* value);
	Genetic::FunctionCalculator* getFunctionCalculator();

	/// @}
};

}

#endif // GENETICSETTINGS_H_INCLUDED
