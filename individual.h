
#ifndef INDIVIDUAL_H
//#define INDIVIDUAL_H

#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>

#include "genetic.h"

namespace Genetic {


/**
 * class Individual
 *
 */

	template <typename DNAtype>
	class Individual
	{
	public:

		// Constructors/Destructors
		//


		/**
		 * Empty Constructor
		 */
		Individual();

		/**
		 * Empty Destructor
		 */
		virtual ~Individual();

		// Static Public attributes
		//

		// Public attributes
		//


		// Public attribute accessor methods
		//
	

		// Public attribute accessor methods
		//



		/**
		 * @param  individual1
		 * @param  individual2
		 * @param  recombinationType
		 * @param  crossoverPointsNum
		 */
		static void recombine(Genetic::Individual <DNAtype>* parent_individual1,
		                      Genetic::Individual <DNAtype>* parent_individual2,
		                      Genetic::Individual <DNAtype>* child_individual1,
		                      Genetic::Individual <DNAtype>* child_individual2,
		                      Genetic::RecombinationType rec_type,
		                      double recombine_param = 1.0,
		                      int crossover_points_num = 1);

		/**
		 * @param  probability
		 */
		void mutate(MutationType mut_type, double probability, int attempts,
		            double parameter);

		/**
		 */
		virtual void generate();


		/**
		 */
		virtual void updateParameters ( )
			{
			}

	protected:

		// Static Protected attributes
		//

		// Protected attributes
		//

		int score;
		std::vector <DNAtype> dna;
	public:


		// Protected attribute accessor methods
		//

	protected:

	public:


		// Protected attribute accessor methods
		//


		/**
		 * Set the value of score
		 * @param new_var the new value of score
		 */
		void setScore ( int new_var )   {
			score = new_var;
		}

		/**
		 * Get the value of score
		 * @return the value of score
		 */
		int getScore ( )   {
			return score;
		}

		/**
		 * Set the value of dna
		 * @param new_var the new value of dna
		 */
		void setDna ( std::vector <double> new_var )   {
			dna = new_var;
		}

		/**
		 * Get the value of dna
		 * @return the value of dna
		 */
		std::vector <double> getDna ( )   {
			return dna;
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

template <typename DNAtype>
Genetic::Individual <DNAtype>::Individual()
{
}

template <typename DNAtype>
Genetic::Individual <DNAtype>::~Individual()
{
}

template <typename DNAtype>
void Genetic::Individual <DNAtype>::recombine(Genetic::Individual <DNAtype>* parent_individual1,
                                              Genetic::Individual <DNAtype>* parent_individual2,
                                              Genetic::Individual <DNAtype>* child_individual1,
                                              Genetic::Individual <DNAtype>* child_individual2,
                                              Genetic::RecombinationType rec_type,
                                              double recombine_param,
                                              int crossover_points_num)
{
	switch(rec_type)
	{
	case DISCRETE:
	{
		for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
		{
			if(rand() & 1)
			{
				child_individual1 -> dna[i] = parent_individual1 -> dna[i];
			} else {
				child_individual1 -> dna[i] = parent_individual2 -> dna[i];
			}
			if(rand() & 1)
			{
				child_individual2 -> dna[i] = parent_individual1 -> dna[i];
			} else {
				child_individual2 -> dna[i] = parent_individual2 -> dna[i];
			}
		}
		break;
	}
	case INTERMEDIATE:
	{
		for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
		{
			double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
			double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
			double v[2];
			v[0] = parent_individual1 -> dna[i] + alpha1 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
			v[1] = parent_individual1 -> dna[i] + alpha2 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
			child_individual1 -> dna[i] = v[0];
			child_individual2 -> dna[i] = v[1];
		}
		break;
	}
	case LINE:
	{
		double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
		double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
		for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
		{
			double v[2];
			v[0] = parent_individual1 -> dna[i] + alpha1 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
			v[1] = parent_individual1 -> dna[i] + alpha2 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
			child_individual1 -> dna[i] = v[0];
			child_individual2 -> dna[i] = v[1];
		}
		break;
	}
	case CROSSOVER:
	{
		assert(parent_individual1 -> dna.size() == parent_individual2 -> dna.size());
		assert(parent_individual1 -> dna.size() > 1);
		assert(parent_individual1 -> dna.size() >= crossover_points_num);
		assert(crossover_points_num > 0);

		// Setting dividing points
		std::vector <int> free_points(parent_individual1 -> dna.size());
		std::vector <int> crossover_points(crossover_points_num);
		for(int i = 0; i < free_points.size(); ++i)
		{
			free_points[i] = i;
		}
		for(int i = 0; i < crossover_points_num; ++i)
		{
			int choosed_point_id = rand() % free_points.size();
			int choosed_point = free_points[choosed_point_id];
			free_points.erase(free_points.begin() + choosed_point_id);
			crossover_points[i] = choosed_point;
		}

		std::sort(crossover_points.begin(), crossover_points.end());
		if(crossover_points[crossover_points.size() - 1]
		   != parent_individual1 -> dna.size() - 1)
		{
			crossover_points.push_back(parent_individual1 -> dna.size() - 1);
		}

		int last_crossover_point = 0;
		int next_crossover_point;
		bool current_inverse = false;

		for(int i = 0; i < crossover_points.size(); ++i)
		{
			int crossover_point = crossover_points[i];
			next_crossover_point = (i < crossover_points_num - 1) ?
				crossover_points[i + 1] :
				parent_individual1 -> dna.size();


			if(current_inverse)
			{
				for(int j = last_crossover_point; j <= crossover_point; ++j)
				{
					child_individual1 -> dna[j] = parent_individual2 -> dna[j];
					child_individual2 -> dna[j] = parent_individual1 -> dna[j];
				}
			} else {
				for(int j = last_crossover_point; j <= crossover_point; ++j)
				{
					child_individual1 -> dna[j] = parent_individual1 -> dna[j];
					child_individual2 -> dna[j] = parent_individual2 -> dna[j];
				}
			}

			last_crossover_point = crossover_point;
			current_inverse = !current_inverse;
		}
		break;
	}
	case UNIFORM_CROSSOVER:
	{
		for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
		{
			if(rand() & 1)
			{
				child_individual1 -> dna[i] = parent_individual1 -> dna[i];
				child_individual2 -> dna[i] = parent_individual2 -> dna[i];
			} else {
				child_individual1 -> dna[i] = parent_individual2 -> dna[i];
				child_individual2 -> dna[i] = parent_individual1 -> dna[i];
			}
		}
		break;
	}
	case TRIADIC_CROSSOVER:

		break;
	case SHUFFLER_CROSSOVER:
	{
		for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
		{
			if(rand() & 1)
			{
				std::swap(parent_individual1 -> dna[i], parent_individual2 -> dna[i]);
			}
		}
		recombine(parent_individual1, parent_individual2,
		          child_individual1, child_individual2,
		          CROSSOVER, recombine_param, crossover_points_num);
		for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
		{
			if(rand() & 1)
			{
				std::swap(child_individual1 -> dna[i], child_individual2 -> dna[i]);
			}
		}
		break;
	}
	case CROSSOVER_WITH_REDUCED_SURROGATE:

		break;
	}
}

template <typename DNAtype>        
void Genetic::Individual <DNAtype>::mutate(MutationType mut_type,
                                           double probability, int attempts,
                                           double parameter)
{
	for(int attemptNo = 0; attemptNo < attempts; ++attemptNo)
	{
		if(((double)(rand()%10000))/10000.0 <= probability)
		{
			switch(mut_type)
			{
			case REAL_VALUE_MUTATION:
			{
				double dlt = 0;
				for(double i = 1.0; i < parameter; ++i)
				{
					if(((double)(rand()%10000))/10000.0 <= 1.0 / parameter)
					{
						dlt += pow(2.0, -i);
					}
				}

				if(rand() & 1)
				{
					dlt *= -1.0;
				}

				dlt *= 0.5;
				int a = rand() % dna.size();

				dna[a] += dlt;
				break;
			}
			case BINARY_MUTATION:
			{
				int a = rand() % dna.size();
				dna[a] = (int)dna[a] ^ 1;
				break;
			}
			case DENSITY_MUTATION:
			{
				break;
			}
			case SWAP_MUTATION:
			{
				// WTF is it?
				int a = rand() % (dna.size());
				int b = rand() % (dna.size() - 1);
				if(b >= a)
				{
					++b;
				}
				std::swap(dna[a], dna[b]);
				break;
			}
			}
		}
	}
}

template <typename DNAtype>
void Genetic::Individual <DNAtype>::generate()
{
}

#endif // INDIVIDUAL_H
