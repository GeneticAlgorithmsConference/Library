#ifndef MINSEARCHINDIVIDUAL_H
#define MINSEARCHINDIVIDUAL_H

#include "log.h"
#include "genetic.h"
#include "geneticsettings.h"

#include "dnatypes.h"
#include "linearindividual.h"

namespace Genetic
{
	template <class F>
	class MinSearchIndividual : public Genetic::LinearIndividual <LinearRealDna, double>
	{
	public:
		void test();
	};
}

template <class F>
void Genetic::MinSearchIndividual <F>::test()
{
	score = (F::getResult(dna));
}

#endif // MINSEARCHINDIVIDUAL_H
