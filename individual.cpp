#include "individual.h"
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace Genetic;

// Constructors/Destructors
//

Individual::Individual ( )
{
    initAttributes();
}

Individual::~Individual ( ) { }

//
// Methods
//

void Individual::recombine(Genetic::Individual* parent_individual1,
                           Genetic::Individual* parent_individual2,
                           Genetic::Individual* child_individual1,
                           Genetic::Individual* child_individual2,
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

void Individual::mutate(MutationType mut_type, double probability, int attempts, double parameter)
{
    for(int attemptNo = 0; attemptNo < attempts; ++attemptNo)
        if(((double)(rand()%10000))/10000.0 <= probability)
            switch(mut_type)
            {
                case REAL_VALUE:
                {
                    double dlt = 0;
                    for(double i = 1.0; i < parameter; ++i)
                        if(((double)(rand()%10000))/10000.0 <= 1.0 / parameter)
                            dlt += pow(2.0, -i);

                    if(rand()&1)
                        dlt *= -1.0;

                    dlt *= 0.5;
                    int a = rand()%(dna.size());

                    dna[a] += dlt;
                    break;
                }
                case BINARY:
                {
                    int a = rand()%(dna.size());
                    dna[a] = (int)dna[a] ^ 1;
                    break;
                }
                case DENSITY:
                {
                    break;
                }
                case SWAP:
                {
                    int a = rand()%(dna.size());
                    int b = rand()%(dna.size()-1);
                    if(b >= a)
                        ++b;
                    std::swap(dna[a], dna[b]);
                    break;
                }
            }
}

// Accessor methods
//


// Other methods
//

void Individual::initAttributes ( ) {
  score = 0;
}

