
#ifndef POPULATION_H
#define POPULATION_H

#include <string>
#include <vector>


#include "generation.h"

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

		Generation* previousGeneration;
		Generation* currentGeneration;

	public:


		// Private attribute accessor methods
		//


		/**
		 * Set the value of previousGeneration
		 * @param new_var the new value of previousGeneration
		 */
		void setPreviousGeneration(Generation* value);

		/**
		 * Get the value of previousGeneration
		 * @return the value of previousGeneration
		 */
		Generation* getPreviousGeneration();

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
	previousGeneration = nullptr;
	currentGeneration = nullptr;
}

template <typename Generation>
Genetic::Population <Generation>::~Population()
{
	delete previousGeneration;
	delete currentGeneration;
}

template <typename Generation>
void Genetic::Population <Generation>::init(unsigned int seed)
{
	srand(seed);
	if(previousGeneration != nullptr)
	{
		delete previousGeneration;
	}
	if(currentGeneration != nullptr)
	{
		delete currentGeneration;
	}
	previousGeneration = new Generation(1);
	currentGeneration = new Generation(1);
}

template <typename Generation>
void Genetic::Population <Generation>::genNextGeneration()
{
}

template <typename Generation>
void Genetic::Population <Generation>::setPreviousGeneration(Generation* value)
{
	previousGeneration = value;
}

template <typename Generation>
Generation* Genetic::Population <Generation>::getPreviousGeneration()
{
	return previousGeneration;
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
