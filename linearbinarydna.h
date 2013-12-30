#ifndef LINEARBINARYDNA_H
#define LINEARBINARYDNA_H

#include "baselineardna.h"

namespace Genetic
{

	class LinearBinaryDna : public BaseLinearDna<unsigned char>
	{
		void mutate();
	};

}

void Genetic::LinearBinaryDna::mutate()
{
}

#endif
