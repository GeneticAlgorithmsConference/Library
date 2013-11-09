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


// Accessor methods
//  


// Other methods
//  

void Individual::initAttributes ( ) {
  score = 0;
}

