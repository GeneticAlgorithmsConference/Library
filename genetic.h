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
    enum NewPopulationSelectionType
    {
        TRUNCATION_SELECTION = 0x200,
        ELITE_SELECTION,
        EXCLUSION_SELECTION,
        BOLZMAN_SELECTION
    };
    enum ParentsChooseType
    {
        PANMIXIA = 0x300,
        INBREEDING_FENOTYPE,
        INBREEDING_GENOTYPE,
        OUTBREEDING_FENOTYPE,
        OUTBREEDING_GENOTYPE
    };
    enum ParentsSelectionType
    {
        TOURNAMENT = 0x400,
        ROULETTE_WHEEL
    };
    enum MutationType
    {
        REAL_VALUE_MUTATION = 0x500,
        BINARY_MUTATION,
        DENSITY_MUTATION,
        SWAP_MUTATION
    };
}
