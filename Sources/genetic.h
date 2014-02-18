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
        TRIADIC_CROSSOVER,
        SHUFFLER_CROSSOVER,
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

#endif
