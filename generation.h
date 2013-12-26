
#ifndef GENERATION_H
#define GENERATION_H

#include <string>
#include <vector>
#include "individual.h"

class Individual;

namespace Genetic {


/**
 * class Generation
 *
 */

	template <typename Individual, typename DNAtype>
	class Generation
	{
	public:
		// Constructors/Destructors
		//


		/**
		 * Empty Constructor
		 */
		Generation(int _individuals_num);

		/**
		 * Empty Destructor
		 */
		virtual ~Generation();

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
		virtual void test ( )
			{
			}


		/**
		 * @param  seed
		 */
		void init (unsigned int seed )
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
		void setIndividuals(std::vector <Individual*> new_var);

		/**
		 * Get the value of individuals
		 * @return the value of individuals
		 */
		std::vector <Individual*> getIndividuals();

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

		/**
		 * Set the value of crossoverPointsNum
		 * @param new_var the new value of crossoverPointsNum
		 */
		void setCrossoverPointsNum(int value);

		/**
		 * Get the value of crossoverPointsNum
		 * @return the value of crossoverPointsNum
		 */
		int getCrossoverPointsNum();
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
