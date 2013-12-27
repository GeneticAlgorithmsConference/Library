
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

	template <typename Individual>
	class Population
	{
	public:

		// Constructors/Destructors
		//


		/**
		 * Empty Constructor
		 */
		Population();

		/**
		 * Empty Destructor
		 */
		virtual ~Population();

		// Static Public attributes
		//

		// Public attributes
		//


		// Public attribute accessor methods
		//


		// Public attribute accessor methods
		//



		/**
		 * @param  seed
		 */
		void init(int seed);


		/**
		 */
		void genNextGeneration();

	protected:

		// Static Protected attributes
		//

		// Protected attributes
		//

	public:


		// Protected attribute accessor methods
		//

	protected:

	public:


		// Protected attribute accessor methods
		//

	protected:


	private:

		// Static Private attributes
		//

		// Private attributes
		//

		Generation <Individual>* previousGeneration;
		Generation <Individual>* currentGeneration;
	public:


		// Private attribute accessor methods
		//

	private:

	public:


		// Private attribute accessor methods
		//


		/**
		 * Set the value of previousGeneration
		 * @param new_var the new value of previousGeneration
		 */
		void setPreviousGeneration(Generation <Individual>* value);

		/**
		 * Get the value of previousGeneration
		 * @return the value of previousGeneration
		 */
		Generation <Individual>* getPreviousGeneration();

		/**
		 * Set the value of currentGeneration
		 * @param new_var the new value of currentGeneration
		 */
		void setCurrentGeneration(Generation <Individual>* value);

		// /**
		//  * Get the value of currentGeneration
		//  * @return the value of currentGeneration
		//  */
		Generation <Individual>* getCurrentGeneration();
	private:


	};
};

template <typename Individual>
Genetic::Population <Individual>::Population()
{
	previousGeneration = nullptr;
}

template <typename Individual>
Genetic::Population <Individual>::~Population()
{
}

template <typename Individual>
void Genetic::Population <Individual>::init(int seed)
{
	if(previousGeneration != nullptr)
	{
		delete previousGeneration;
	}
	if(currentGeneration != nullptr)
	{
		delete currentGeneration;
	}
	previousGeneration = new Generation<Individual>(1);
	currentGeneration = new Generation<Individual>(1);
}

template <typename Individual>
void Genetic::Population <Individual>::genNextGeneration()
{
}

template <typename Individual>
void Genetic::Population <Individual>::setPreviousGeneration(Genetic::Generation <Individual>* value)
{
}

template <typename Individual>
Genetic::Generation <Individual>* Genetic::Population <Individual>::getPreviousGeneration()
{
}

template <typename Individual>
void Genetic::Population <Individual>::setCurrentGeneration(Genetic::Generation <Individual>* value)
{
}

template <typename Individual>
Genetic::Generation <Individual>* Genetic::Population <Individual>::getCurrentGeneration()
{
}

#endif // POPULATION_H
