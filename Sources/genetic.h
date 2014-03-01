#ifndef GENETIC_H
#define GENETIC_H

namespace Genetic
{
    enum RecombinationType
    {
        DISCRETE = 0x100,
        INTERMEDIATE,
        LINE,
        CROSSOVER,
        UNIFORM_CROSSOVER,
        SHUFFLER_CROSSOVER,
        TRIADIC_CROSSOVER,
        CROSSOVER_WITH_REDUCED_SURROGATE
    };
    enum NewGenerationSelectionType
    {
        TRUNCATION_SELECTION = 0x200,
        ELITE_SELECTION,
        EXCLUSION_SELECTION,
        BOLZMAN_SELECTION
    };
    enum ParentsSelectionType
    {
        PANMIXIA = 0x300,
        INBREEDING_FENOTYPE,
        INBREEDING_GENOTYPE,
        OUTBREEDING_FENOTYPE,
        OUTBREEDING_GENOTYPE,
        TOURNAMENT,
        ROULETTE_WHEEL
    };
}

#include "genetic_settings.h"
#include "generation.h"

// Individuals
#include "individual/base_individual.h"
#include "individual/individual.h"

// New generation selection supported types
#include "new_generation_selection/new_generation_selection.h"
#include "new_generation_selection/elite.h"
#include "new_generation_selection/truncation.h"

// Parents selection supported types
#include "parents_selection/parents_selection.h"
#include "parents_selection/panmixia.h"
#include "parents_selection/inbreeding_fenotype.h"

// Recombination supported types
#include "recombination/recombination.h"
#include "recombination/discrete.h"

// Mutation supported types
#include "mutation/mutation.h"
#include "mutation/binary_dna_mutation.h"

// Supported dna types
#include "dna/dna.h"
#include "dna/base_linear_dna.h"
#include "dna/base_tree_dna.h"

#include "function_calculator.h"

#endif
