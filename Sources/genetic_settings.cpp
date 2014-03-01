#include "genetic_settings.h"

Genetic::GeneticSettings::GeneticSettings() :
	generationSize(0),
	parentsSelection(NULL),
	recombination(NULL),
	mutation(NULL),
	newGenerationSelection(NULL)
{

}

Genetic::GeneticSettings::GeneticSettings(int _generationSize) :
	generationSize(_generationSize),
	parentsSelection(NULL),
	recombination(NULL),
	mutation(NULL),
	newGenerationSelection(NULL)
{

}

Genetic::GeneticSettings::~GeneticSettings()
{

}

void Genetic::GeneticSettings::setNewGenerationSelection(Genetic::NewGenerationSelection* value)
{
    newGenerationSelection = value;
}

Genetic::NewGenerationSelection* Genetic::GeneticSettings::getNewGenerationSelection()
{
    return newGenerationSelection;
}

void Genetic::GeneticSettings::setRecombination(Genetic::Recombination* value)
{
    recombination = value;
}

Genetic::Recombination* Genetic::GeneticSettings::getRecombination()
{
    return recombination;
}

void Genetic::GeneticSettings::setParentsSelection(ParentsSelection* value)
{
    parentsSelection = value;
}

Genetic::ParentsSelection* Genetic::GeneticSettings::getParentsSelection()
{
    return parentsSelection;
}

void Genetic::GeneticSettings::setMutation(Genetic::Mutation* value)
{
	mutation = value;
}

Genetic::Mutation* Genetic::GeneticSettings::getMutation()
{
	return mutation;
}

void Genetic::GeneticSettings::setFunctionCalculator(Genetic::FunctionCalculator* value)
{
	functionCalculator = value;
}

Genetic::FunctionCalculator* Genetic::GeneticSettings::getFunctionCalculator()
{
	return functionCalculator;
}
