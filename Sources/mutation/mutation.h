#ifndef MUTATION_H
#define MUTATION_H

#include "../dna/dna.h"

namespace Genetic
{

class Mutation
{
public:
	virtual ~Mutation() {}
	virtual void process(Genetic::Dna& dna) = 0;
private:
};

}

#endif
