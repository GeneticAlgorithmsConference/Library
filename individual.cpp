#include "individual.h"

using namespace Genetic;

// Constructors/Destructors
//

Individual::Individual ( ) {
initAttributes();
}

Individual::~Individual ( ) { }

//
// Methods
//

void Individual::recombine(Genetic::Individual* individual1,
                           Genetic::Individual* individual2,
                           Genetic::RecombinationType recType,
                           double recombineParam)
{
  switch(recType)
  {
    case DISCRETE:
        for(int i = 0; i < individual1 -> dna.size(); ++i)
        {
            double v[2];
            v[0] = individual1 -> dna[i];
            v[1] = individual2 -> dna[i];
            individual1 -> dna[i] = v[rand() % 2];
            individual2 -> dna[i] = v[rand() % 2];
        }
        break;
    case INTERMEDIATE:
        {
            for(int i = 0; i < individual1 -> dna.size(); ++i)
            {
                double alpha1 = (double)(rand()%(unsigned int)(recombineParam*20000)-recombineParam*10000) / 10000.0;
                double alpha2 = (double)(rand()%(unsigned int)(recombineParam*20000)-recombineParam*10000) / 10000.0;
                double v[2];
                v[0] = individual1 -> dna[i] + alpha1 * (individual1 -> dna[i] - individual2 -> dna[i]);
                v[1] = individual2 -> dna[i] + alpha2 * (individual1 -> dna[i] - individual2 -> dna[i]);
                v[0] = std::min(1.0, std::max(0.0, v[0]));
                v[1] = std::min(1.0, std::max(0.0, v[1]));
                individual1 -> dna[i] = v[0];
                individual2 -> dna[i] = v[1];
            }
        }
        break;
    case LINE:
        {
            double alpha1 = (double)(rand()%(unsigned int)(recombineParam*20000)-recombineParam*10000) / 10000.0;
            double alpha2 = (double)(rand()%(unsigned int)(recombineParam*20000)-recombineParam*10000) / 10000.0;
            for(int i = 0; i < individual1 -> dna.size(); ++i)
            {
                double v[2];
                v[0] = individual1 -> dna[i] + alpha1 * (individual1 -> dna[i] - individual2 -> dna[i]);
                v[1] = individual2 -> dna[i] + alpha2 * (individual1 -> dna[i] - individual2 -> dna[i]);
                v[0] = std::min(1.0, std::max(0.0, v[0]));
                v[1] = std::min(1.0, std::max(0.0, v[1]));
                individual1 -> dna[i] = v[0];
                individual2 -> dna[i] = v[1];
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

