#include "geneticSettings.h"

Genetic::GeneticSettings::GeneticSettings(int _generationSize, NewGenerationSelectionType _newGenerationSelectionType,
                                             ParentsSelectionType _parentsSelectionType, RecombinationType _recombinationType)
{
    parentsSelectionType = _parentsSelectionType;
    newGenerationSelectionType = _newGenerationSelectionType;
    recombinationType = _recombinationType;

    newGenerationSelectionParameter = 1.0;
    recombinationParameter = 1.0;
    mutationProbability = 0.25;
    mutationParameter = 1.0;
    mutationAttempts = 1;
}

Genetic::GeneticSettings::~GeneticSettings()
{

}

void Genetic::GeneticSettings::setMutationProbability(double value)
{
    mutationProbability = value;
}

double Genetic::GeneticSettings::getMutationProbability()
{
    return mutationProbability;
}

void Genetic::GeneticSettings::setMutationAttempts(int value)
{
    mutationAttempts = value;
}

int Genetic::GeneticSettings::getMutationAttempts()
{
    return mutationAttempts;
}

void Genetic::GeneticSettings::setMutationParameter(double value)
{
    mutationParameter = value;
}

double Genetic::GeneticSettings::getMutationParameter()
{
    return mutationParameter;
}

void Genetic::GeneticSettings::setNewGenerationSelectionType( Genetic::NewGenerationSelectionType value)
{
    newGenerationSelectionType = value;
}

Genetic::NewGenerationSelectionType Genetic::GeneticSettings::getNewGenerationSelectionType()
{
    return newGenerationSelectionType;
}

void Genetic::GeneticSettings::setRecombinationType( Genetic::RecombinationType value)
{
    recombinationType = value;
}

Genetic::RecombinationType Genetic::GeneticSettings::getRecombinationType()
{
    return recombinationType;
}

void Genetic::GeneticSettings::setRecombinationParameter(double value)
{
    recombinationParameter = value;
}

double Genetic::GeneticSettings::getRecombinationParameter()
{
    return recombinationParameter;
}

void Genetic::GeneticSettings::setGenerationSelectionParameter(double value)
{
    newGenerationSelectionParameter = value;
}

double Genetic::GeneticSettings::getGenerationSelectionParameter()
{
    return newGenerationSelectionParameter;
}

void Genetic::GeneticSettings::setParentsSelectionType(ParentsSelectionType value)
{
    parentsSelectionType = value;
}

Genetic::ParentsSelectionType Genetic::GeneticSettings::getParentsSelectionType()
{
    return parentsSelectionType;
}
