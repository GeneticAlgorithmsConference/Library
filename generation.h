
#ifndef GENERATION_H
#define GENERATION_H

#include <string>
#include <vector>
#include "individual.h"

namespace Genetic {


/**
 * class Generation
 *
 */

	template <typename Individual>
	class Generation
	{
	public:
		// Constructors/Destructors
		//


		/**
		 * Empty Constructor
		 */
		Generation(int _individuals_num)
		{
			individuals_num = _individuals_num;

			Individual* tmp_individual;

			for(int i = 0; i < individuals_num; ++i)
			{
				tmp_individual = new Individual();
				individuals.push_back(tmp_individual);
			}
		}

		/**
		 * Empty Destructor
		 */
		virtual ~Generation()
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
		 */
		virtual void test()
		{
		}


		/**
		 * @param  seed
		 */
		void init(unsigned int seed)
		{
		}

	protected:

		// Static Protected attributes
		//

		// Protected attributes
		//

		std::vector <Individual*> individuals;
		int individuals_num;
		double mutation_probability;
		int mutation_attempts;
		int crossover_points_num;
	public:


		// Protected attribute accessor methods
		//

	protected:

	public:


		// Protected attribute accessor methods
		//


		/**
		 * Set the value of individuals
		 * @param new_var the new value of individuals
		 */
		void setIndividuals(std::vector <Individual*> value)
		{
			individuals = value;
		}

		/**
		 * Get the value of individuals
		 * @return the value of individuals
		 */
		std::vector <Individual*> getIndividuals()
		{
			return individuals;
		}

		/**
		 * Set the value of individualsNum
		 * @param new_var the new value of individualsNum
		 */
		void setIndividualsNum(int value)
		{
			individuals_num = value;
		}

		/**
		 * Get the value of individualsNum
		 * @return the value of individualsNum
		 */
		int getIndividualsNum()
		{
			return individuals_num;
		}

		/**
		 * Set the value of mutationProbability
		 * @param new_var the new value of mutationProbability
		 */
		void setMutationProbability(double value)
		{
			mutation_probability = value;
		}

		/**
		 * Get the value of mutationProbability
		 * @return the value of mutationProbability
		 */
		double getMutationProbability()
		{
			return mutation_probability;
		}

		/**
		 * Set the value of mutationAttempts
		 * @param new_var the new value of mutationAttempts
		 */
		void setMutationAttempts(int value)
		{
			mutation_attempts = value;
		}

		/**
		 * Get the value of mutationAttempts
		 * @return the value of mutationAttempts
		 */
		int getMutationAttempts()
		{
			return mutation_attempts;
		}

		/**
		 * Set the value of crossoverPointsNum
		 * @param new_var the new value of crossoverPointsNum
		 */
		void setCrossoverPointsNum(int value)
		{
			crossover_points_num = value;
		}

		/**
		 * Get the value of crossoverPointsNum
		 * @return the value of crossoverPointsNum
		 */
		int getCrossoverPointsNum()
		{
			return crossover_points_num;
		}
	protected:


	private:

		// Static Private attributes
		//

		// Private attributes
		//

	public:


		// Private attribute accessor methods
		//

	private:

	public:


		// Private attribute accessor methods
		//

	private:

	};
}; // end of package namespace

#endif // GENERATION_H
