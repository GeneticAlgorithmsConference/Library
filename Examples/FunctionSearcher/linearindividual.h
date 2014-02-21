#ifndef LINEARLinearIndividual_H_INCLUDED
#define LINEARLinearIndividual_H_INCLUDED

#include "genetic.h"
#include "geneticsettings.h"

#include "individual.h"

namespace Genetic
{
    template <typename D>
    class LinearIndividual: public Individual<D>
    {
	public:

        LinearIndividual(): Individual<D>() { };

		void test() {};

		/// Recombine method.
		static void recombine(Genetic::LinearIndividual <D>* parent_LinearIndividual1,
		                      Genetic::LinearIndividual <D>* parent_LinearIndividual2,
		                      Genetic::LinearIndividual <D>* child_LinearIndividual1,
		                      Genetic::LinearIndividual <D>* child_LinearIndividual2,
		                      Genetic::GeneticSettings* geneticSettings);

        void generate(double dnaGenerationParameter);
    };
};

template <typename D>
void Genetic::LinearIndividual <D>::generate(double dnaGenerationParameter)
{
    (this -> dna).generate(dnaGenerationParameter);
}

template <typename D>
void Genetic::LinearIndividual <D>::recombine(Genetic::LinearIndividual <D>* parent_LinearIndividual1,
                                        Genetic::LinearIndividual <D>* parent_LinearIndividual2,
                                        Genetic::LinearIndividual <D>* child_LinearIndividual1,
                                        Genetic::LinearIndividual <D>* child_LinearIndividual2,
                                        Genetic::GeneticSettings* geneticSettings)
{
    assert(parent_LinearIndividual1 -> dna.size() == parent_LinearIndividual2 -> dna.size());
    child_LinearIndividual1 -> dna.resize(parent_LinearIndividual1 -> dna.size());
    child_LinearIndividual2 -> dna.resize(parent_LinearIndividual1 -> dna.size());

    double recombine_param = geneticSettings -> getRecombinationParameter();
	switch(geneticSettings -> getRecombinationType())
	{
        case DISCRETE:
        {
            for(int i = 0; i < parent_LinearIndividual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    child_LinearIndividual1 -> dna[i] = parent_LinearIndividual1 -> dna[i];
                } else {
                    child_LinearIndividual1 -> dna[i] = parent_LinearIndividual2 -> dna[i];
                }
                if(rand() & 1)
                {
                    child_LinearIndividual2 -> dna[i] = parent_LinearIndividual1 -> dna[i];
                } else {
                    child_LinearIndividual2 -> dna[i] = parent_LinearIndividual2 -> dna[i];
                }
            }
            break;
        }
        case INTERMEDIATE:
        {
            for(int i = 0; i < parent_LinearIndividual1 -> dna.size(); ++i)
            {
                double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
                double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
                double v[2];
                v[0] = parent_LinearIndividual1 -> dna[i] + alpha1 * (parent_LinearIndividual2 -> dna[i] - parent_LinearIndividual1 -> dna[i]);
                v[1] = parent_LinearIndividual1 -> dna[i] + alpha2 * (parent_LinearIndividual2 -> dna[i] - parent_LinearIndividual1 -> dna[i]);
                child_LinearIndividual1 -> dna[i] = v[0];
                child_LinearIndividual2 -> dna[i] = v[1];
            }
            break;
        }
        case LINE:
        {
            double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
            double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
            for(int i = 0; i < parent_LinearIndividual1 -> dna.size(); ++i)
            {
                double v[2];
                v[0] = parent_LinearIndividual1 -> dna[i] + alpha1 * (parent_LinearIndividual2 -> dna[i] - parent_LinearIndividual1 -> dna[i]);
                v[1] = parent_LinearIndividual1 -> dna[i] + alpha2 * (parent_LinearIndividual2 -> dna[i] - parent_LinearIndividual1 -> dna[i]);
                child_LinearIndividual1 -> dna[i] = v[0];
                child_LinearIndividual2 -> dna[i] = v[1];
            }
            break;
        }
        case CROSSOVER:
        {
            int crossover_points_num = recombine_param;
            assert(parent_LinearIndividual1 -> dna.size() > 1);
            assert(parent_LinearIndividual1 -> dna.size() >= crossover_points_num);
            assert(crossover_points_num > 0);

            // Setting dividing points
            std::vector <int> free_points(parent_LinearIndividual1 -> dna.size());
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
               != parent_LinearIndividual1 -> dna.size() - 1)
            {
                crossover_points.push_back(parent_LinearIndividual1 -> dna.size() - 1);
            }

            int last_crossover_point = 0;
            int next_crossover_point;
            bool current_inverse = false;

            for(int i = 0; i < crossover_points.size(); ++i)
            {
                int crossover_point = crossover_points[i];
                next_crossover_point = (i < crossover_points_num - 1) ?
                    crossover_points[i + 1] :
                    parent_LinearIndividual1 -> dna.size();


                if(current_inverse)
                {
                    for(int j = last_crossover_point; j <= crossover_point; ++j)
                    {
                        child_LinearIndividual1 -> dna[j] = parent_LinearIndividual2 -> dna[j];
                        child_LinearIndividual2 -> dna[j] = parent_LinearIndividual1 -> dna[j];
                    }
                } else {
                    for(int j = last_crossover_point; j <= crossover_point; ++j)
                    {
                        child_LinearIndividual1 -> dna[j] = parent_LinearIndividual1 -> dna[j];
                        child_LinearIndividual2 -> dna[j] = parent_LinearIndividual2 -> dna[j];
                    }
                }

                last_crossover_point = crossover_point;
                current_inverse = !current_inverse;
            }
            break;
        }
        case UNIFORM_CROSSOVER:
        {
            for(int i = 0; i < parent_LinearIndividual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    child_LinearIndividual1 -> dna[i] = parent_LinearIndividual1 -> dna[i];
                    child_LinearIndividual2 -> dna[i] = parent_LinearIndividual2 -> dna[i];
                } else {
                    child_LinearIndividual1 -> dna[i] = parent_LinearIndividual2 -> dna[i];
                    child_LinearIndividual2 -> dna[i] = parent_LinearIndividual1 -> dna[i];
                }
            }
            break;
        }
        case TRIADIC_CROSSOVER:

            break;
        case SHUFFLER_CROSSOVER:
        {
            for(int i = 0; i < parent_LinearIndividual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    std::swap(parent_LinearIndividual1 -> dna[i], parent_LinearIndividual2 -> dna[i]);
                }
            }
            GeneticSettings ts = *geneticSettings;
            ts.setRecombinationType(CROSSOVER);
            recombine(parent_LinearIndividual1, parent_LinearIndividual2,
                      child_LinearIndividual1, child_LinearIndividual2, &ts);
            for(int i = 0; i < parent_LinearIndividual1 -> dna.size(); ++i)
            {
                if(rand() & 1)
                {
                    std::swap(child_LinearIndividual1 -> dna[i], child_LinearIndividual2 -> dna[i]);
                }
            }
            break;
        }
        case CROSSOVER_WITH_REDUCED_SURROGATE:

            break;
    }
}

#endif // LINEARLinearIndividual_H_INCLUDED
