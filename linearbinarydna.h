#ifndef LINEARBINARYDNA_H
#define LINEARBINARYDNA_H

#include "baselineardna.h"

namespace Genetic
{

	class LinearBinaryDna : public BaseLinearDna<unsigned char>
	{
	public:
		void mutate(double parameter = 0.0);
		void generate(double dnaSize);
	};

}

void Genetic::LinearBinaryDna::mutate(double parameter)
{
	int randomId = rand() % dna.size();
	dna[randomId] = 1 - dna[randomId];
}

void Genetic::LinearBinaryDna::generate(double dnaSize)
{
	dna.resize(dnaSize);
    for(int i = 0; i < dna.size(); ++i)
    {
        dna[i] = rand() & 1;
    }
}

#endif
