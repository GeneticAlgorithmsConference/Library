
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
		void init(unsigned int seed);


		/**
		 */
		void genNextGeneration();

	protected:

		Generation* currentGeneration;
		int generationSize;
		NewPopulationSelectionType selectionType;

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
	private:


	};
};

template <typename Generation>
Genetic::Population <Generation>::Population()
{
	currentGeneration = nullptr;
	generationSize = 10;
	selectionType = ELITE_SELECTION;
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
void Genetic::Population <Generation>::init(unsigned int seed)
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
	currentGeneration -> genNext();
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

#endif // POPULATION_H
