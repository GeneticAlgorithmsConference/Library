#ifndef LINEARBINARYDNA_H
#define LINEARBINARYDNA_H

#include <stdlib.h>

#include "base_linear_dna.h"

namespace Genetic
{
	class LinearBinaryDna : public BaseLinearDna<unsigned char>
	{
	public:
		void mutate(double parameter = 0.0) override;
		void generate(double parameter) override;
		double getDistance(Genetic::Dna& dna) override;
		void print();
	};

}

#endif
