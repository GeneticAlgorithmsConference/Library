#include "individual.h"
#include <iostream>

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
                           double recombine_param)
{
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Не изменять индивидов, а создавать новых!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    switch(rec_type)
    {
    case DISCRETE:
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
    case INTERMEDIATE:
        {
            for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
            {
                double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
                double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
//                std::cout << "alpha1: " << alpha1 << " alpha2" << std::endl;
//                double alpha1 = (double)(rand()%(unsigned int)(recombine_param*20000)-recombine_param*10000) / 10000.0;
//                double alpha2 = (double)(rand()%(unsigned int)(recombine_param*20000)-recombine_param*10000) / 10000.0;
                double v[2];
                v[0] = parent_individual1 -> dna[i] + alpha1 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
                v[1] = parent_individual1 -> dna[i] + alpha2 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
//                v[0] = std::min(1.0, std::max(0.0, v[0]));
//                v[1] = std::min(1.0, std::max(0.0, v[1]));
                child_individual1 -> dna[i] = v[0];
                child_individual2 -> dna[i] = v[1];
            }
        }
        break;
    case LINE:
        {
            double alpha1 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
            double alpha2 = static_cast<double>(rand() % 1000) / 1000.0 * (1.0 + 2.0 * recombine_param) - recombine_param;
            for(int i = 0; i < parent_individual1 -> dna.size(); ++i)
            {
                double v[2];
                v[0] = parent_individual1 -> dna[i] + alpha1 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
                v[1] = parent_individual1 -> dna[i] + alpha2 * (parent_individual2 -> dna[i] - parent_individual1 -> dna[i]);
//                v[0] = std::min(1.0, std::max(0.0, v[0]));
//                v[1] = std::min(1.0, std::max(0.0, v[1]));
                child_individual1 -> dna[i] = v[0];
                child_individual2 -> dna[i] = v[1];
            }
        }
        break;
    case CROSSOVER:

        break;
    case UNIFORM_CROSSOVER:

        break;
    case TRIADIC_CROSSOVER:

        break;
    case SHUFFLER_CROSSOVER:

        break;
    case CROSSOVER_WITH_REDUCED_SURROGATE:

        break;
    }
}

// Accessor methods
//


// Other methods
//

void Individual::initAttributes ( ) {
  score = 0;
}

