#include "binary_dna_mutation.h"
#include "../log.h"

#include "../dna/linear_binary_dna.h"

Genetic::BinaryDnaMutation::BinaryDnaMutation() :
	mutationsNum(1)
{
}

Genetic::BinaryDnaMutation::BinaryDnaMutation(unsigned int _mutationsNum) :
	mutationsNum(_mutationsNum)
{
}

void Genetic::BinaryDnaMutation::process(Genetic::Dna& _dna)
{
	Genetic::LinearBinaryDna& dna = dynamic_cast<Genetic::LinearBinaryDna&>(_dna);
	for(unsigned int i = 0; i < mutationsNum; ++i)
	{
		unsigned int randomId = rand() % dna.size();
		dna[randomId] = 1 - dna[randomId];
	}
}
