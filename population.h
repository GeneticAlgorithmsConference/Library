
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

	template <typename Individual, typename DNAtype>
	class Population
	{
	public:

		// Constructors/Destructors
		//


		/**
		 * Empty Constructor
		 */
		Population()
		{
			previous_generation = nullptr;
		}

		/**
		 * Empty Destructor
		 */
		virtual ~Population()
		{
		}

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
		void init(int seed)
		{
			if(previous_generation != nullptr)
			{
				delete previous_generation;
			}
			if(current_generation != nullptr)
			{
				delete current_generation;
			}
			previous_generation = new Generation<Individual, DNAtype>(1);
			current_generation = new Generation<Individual, DNAtype>(1);
		}


		/**
		 */
		void nextGeneration()
		{
		}

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

		Generation <Individual, DNAtype>* previous_generation;
		Generation <Individual, DNAtype>* current_generation;
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
		void setPreviousGeneration(Generation <Individual, DNAtype>* value)
		{
			previous_generation = value;
		}

		/**
		 * Get the value of previousGeneration
		 * @return the value of previousGeneration
		 */
		// Generation* getPreviousGeneration();

		/**
		 * Set the value of currentGeneration
		 * @param new_var the new value of currentGeneration
		 */
		// void setCurrentGeneration(Generation* value);

		// /**
		//  * Get the value of currentGeneration
		//  * @return the value of currentGeneration
		//  */
		// Generation* getCurrentGeneration();
	private:


	};
};

#endif // POPULATION_H
