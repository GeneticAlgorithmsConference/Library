#ifndef LINEARLinearIndividual_H_INCLUDED
#define LINEARLinearIndividual_H_INCLUDED

#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <assert.h>

#include "genetic.h"
#include "geneticsettings.h"

#include "individual.h"

namespace Genetic
{
    template <typename D, typename S>
    class LinearIndividual: public Individual<D, S>
    {
	public:
		void mutate(Genetic::GeneticSettings* geneticSettings);

		static void recombine(Genetic::LinearIndividual <D, S>* parent_Individual1,
		                      Genetic::LinearIndividual <D, S>* parent_Individual2,
		                      Genetic::LinearIndividual <D, S>* child_Individual1,
		                      Genetic::LinearIndividual <D, S>* child_Individual2,
		                      Genetic::GeneticSettings* geneticSettings);
    };
};

template <typename D, typename S>
void Genetic::LinearIndividual <D, S>::mutate(Genetic::GeneticSettings* geneticSettings)
{
    int attempts = geneticSettings -> getMutationAttempts();
    double probability = geneticSettings -> getMutationProbability();
    double parameter = geneticSettings -> getMutationParameter();

	for(int attemptNo = 0; attemptNo < attempts; ++attemptNo)
	{
	    double rndVal = static_cast<double>(rand() % 10000) / 10000.0;
		if(rndVal <= probability)
        {
		    this -> dna.mutate(parameter);
		}
	}
}

template <typename D, typename S>
void Genetic::LinearIndividual <D, S>::recombine(Genetic::LinearIndividual <D, S>* parent_Individual1,
                                        Genetic::LinearIndividual <D, S>* parent_Individual2,
                                        Genetic::LinearIndividual <D, S>* child_Individual1,
                                        Genetic::LinearIndividual <D, S>* child_Individual2,
                                        Genetic::GeneticSettings* geneticSettings)
{
    assert(parent_Individual1 -> dna.size() == parent_Individual2 -> dna.size());
    child_Individual1 -> dna.resize(parent_Individual1 -> dna.size());
    child_Individual2 -> dna.resize(parent_Individual1 -> dna.size());

    double recombine_param = geneticSettings -> getRecombinationParameter();
	switch(geneticSettings -> getRecombinationType())
	{
        case DISCRETE:
        {
            for(int i = 0; i < parent_Individual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    child_Individual1 -> dna[i] = parent_Individual1 -> dna[i];
                } else {
                    child_Individual1 -> dna[i] = parent_Individual2 -> dna[i];
                }
                if(rand() & 1)
                {
                    child_Individual2 -> dna[i] = parent_Individual1 -> dna[i];
                } else {
                    child_Individual2 -> dna[i] = parent_Individual2 -> dna[i];
                }
            }
            break;
        }
        case INTERMEDIATE:
        {
            for(int i = 0; i < parent_Individual1 -> dna.size(); ++i)
            {
                double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
                double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
                double v[2];
                v[0] = parent_Individual1 -> dna[i] + alpha1 * (parent_Individual2 -> dna[i] - parent_Individual1 -> dna[i]);
                v[1] = parent_Individual1 -> dna[i] + alpha2 * (parent_Individual2 -> dna[i] - parent_Individual1 -> dna[i]);
                child_Individual1 -> dna[i] = v[0];
                child_Individual2 -> dna[i] = v[1];
            }
            break;
        }
        case LINE:
        {
            double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
            double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
            for(int i = 0; i < parent_Individual1 -> dna.size(); ++i)
            {
                double v[2];
                v[0] = parent_Individual1 -> dna[i] + alpha1 * (parent_Individual2 -> dna[i] - parent_Individual1 -> dna[i]);
                v[1] = parent_Individual1 -> dna[i] + alpha2 * (parent_Individual2 -> dna[i] - parent_Individual1 -> dna[i]);
                child_Individual1 -> dna[i] = v[0];
                child_Individual2 -> dna[i] = v[1];
            }
            break;
        }
        case CROSSOVER:
        {
            int crossover_points_num = recombine_param;
            assert(parent_Individual1 -> dna.size() > 1);
            assert(parent_Individual1 -> dna.size() >= crossover_points_num);
            assert(crossover_points_num > 0);

            // Setting dividing points
            std::vector <int> free_points(parent_Individual1 -> dna.size());
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
               != parent_Individual1 -> dna.size() - 1)
            {
                crossover_points.push_back(parent_Individual1 -> dna.size() - 1);
            }

            int last_crossover_point = 0;
            int next_crossover_point;
            bool current_inverse = false;

            for(int i = 0; i < crossover_points.size(); ++i)
            {
                int crossover_point = crossover_points[i];
                next_crossover_point = (i < crossover_points_num - 1) ?
                    crossover_points[i + 1] :
                    parent_Individual1 -> dna.size();


                if(current_inverse)
                {
                    for(int j = last_crossover_point; j <= crossover_point; ++j)
                    {
                        child_Individual1 -> dna[j] = parent_Individual2 -> dna[j];
                        child_Individual2 -> dna[j] = parent_Individual1 -> dna[j];
                    }
                } else {
                    for(int j = last_crossover_point; j <= crossover_point; ++j)
                    {
                        child_Individual1 -> dna[j] = parent_Individual1 -> dna[j];
                        child_Individual2 -> dna[j] = parent_Individual2 -> dna[j];
                    }
                }

                last_crossover_point = crossover_point;
                current_inverse = !current_inverse;
            }
            break;
        }
        case UNIFORM_CROSSOVER:
        {
            for(int i = 0; i < parent_Individual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    child_Individual1 -> dna[i] = parent_Individual1 -> dna[i];
                    child_Individual2 -> dna[i] = parent_Individual2 -> dna[i];
                } else {
                    child_Individual1 -> dna[i] = parent_Individual2 -> dna[i];
                    child_Individual2 -> dna[i] = parent_Individual1 -> dna[i];
                }
            }
            break;
        }
        case SHUFFLER_CROSSOVER:
        {
            for(int i = 0; i < parent_Individual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    std::swap(parent_Individual1 -> dna[i], parent_Individual2 -> dna[i]);
                }
            }
            GeneticSettings ts = *geneticSettings;
            ts.setRecombinationType(CROSSOVER);
            recombine(parent_Individual1, parent_Individual2,
                      child_Individual1, child_Individual2, &ts);
            for(int i = 0; i < parent_Individual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    std::swap(child_Individual1 -> dna[i], child_Individual2 -> dna[i]);
                }
            }
            break;
        }
        case TRIADIC_CROSSOVER:

            break;
        case CROSSOVER_WITH_REDUCED_SURROGATE:

            break;
    }
}

#endif // LINEARLinearIndividual_H_INCLUDED
