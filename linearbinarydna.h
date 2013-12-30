#ifndef LINEARBINARYDNA_H
#define LINEARBINARYDNA_H

#include "baselineardna.h"

namespace Genetic
{

	class LinearBinaryDna : public BaseLinearDna<unsigned char>
	{
	public:
		void mutate();
	};

}

void Genetic::LinearBinaryDna::mutate()
{
	int randomId = rand() % dna.size();
	dna[randomId] = 1 - dna[randomId];
}

#endif
