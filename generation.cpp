#include "generation.h"
#include "individual.h"

using namespace Genetic;

// Constructors/Destructors
//  

template <typename Individual, typename DNAtype>
Generation <Individual, DNAtype>::Generation(int _individuals_num)
{
	individuals_num = _individuals_num;

	Individual* tmp_individual;

	for(int i = 0; i < individuals_num; ++i)
	{
		tmp_individual = new Genetic::Individual<DNAtype>();
		individuals.push_back(tmp_individual);
	}
}

template <typename Individual, typename DNAtype>
Generation <Individual, DNAtype>::~Generation()
{
}

//  
// Methods
//  


// Accessor methods
//  
template <typename Individual, typename DNAtype>
void Generation<Individual, DNAtype>::setIndividuals(std::vector <Individual*> value)
{
	individuals = value;
}

template <typename Individual, typename DNAtype>
std::vector <Individual*> Generation<Individual, DNAtype>::getIndividuals()
{
	return individuals;
}

template <typename Individual, typename DNAtype>
void Generation<Individual, DNAtype>::setIndividualsNum(int value)
{
	individuals_num = value;
}

template <typename Individual, typename DNAtype>
int Generation<Individual, DNAtype>::getIndividualsNum()
{
	return individuals_num;
}

template <typename Individual, typename DNAtype>
void Generation<Individual, DNAtype>::setMutationProbability(double value)
{
	mutation_probability = value;
}

template <typename Individual, typename DNAtype>
double Generation<Individual, DNAtype>::getMutationProbability()
{
	return mutation_probability;
}

template <typename Individual, typename DNAtype>
void Generation<Individual, DNAtype>::setMutationAttempts(int value)
{
	mutation_attempts = value;
}

template <typename Individual, typename DNAtype>
int Generation<Individual, DNAtype>::getMutationAttempts()
{
	return mutation_attempts;
}

template <typename Individual, typename DNAtype>
void Generation<Individual, DNAtype>::setCrossoverPointsNum(int value)
{
	crossover_points_num = value;
}

template <typename Individual, typename DNAtype>
int Generation<Individual, DNAtype>::getCrossoverPointsNum()
{
	return crossover_points_num;
}

// Other methods
//  
