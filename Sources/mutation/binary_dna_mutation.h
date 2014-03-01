#ifndef BINARY_DNA_MUTATION_H
#define BINARY_DNA_MUTATION_H

#include "mutation.h"

namespace Genetic
{

class BinaryDnaMutation : public Genetic::Mutation
{
public:
	BinaryDnaMutation();
	BinaryDnaMutation(unsigned int mutationsNum);
	void process(Genetic::Dna& _dna);
private:
	unsigned int mutationsNum;
};

}

#endif
