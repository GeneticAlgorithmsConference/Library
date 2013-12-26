#include "population.h"
#include "generation.h"

using namespace Genetic;

// Constructors/Destructors
//  

template <typename Individual, typename DNAtype>
Population <Individual, DNAtype>::Population()
{
	previous_generation = new Generation<Individual, DNAtype>();
}

template <typename Individual, typename DNAtype>
Population <Individual, DNAtype>::~Population()
{
}

//  
// Methods
//  


// Accessor methods
//  

template <typename Individual, typename DNAtype>
void Population <Individual, DNAtype>::setPreviousGeneration(Generation <Individual, DNAtype>* value)
{
	previous_generation = value;
}

// template <typename Individual, typename DNAtype>
// Generation* Population <Individual, DNAtype>::getPreviousGeneration()
// {
// 	return previousGeneration;
// }

// void setCurrentGeneration(Generation* new_var)
// {
// 	currentGeneration = new_var;
// }

// Generation* getCurrentGeneration()
// {
// 	return currentGeneration;
// }

// Other methods
//  

