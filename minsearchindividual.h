#ifndef MINSEARCHINDIVIDUAL_H
#define MINSEARCHINDIVIDUAL_H

#include <iostream>

#include "individual.h"
#include "dnatypes.h"

namespace Genetic
{
    template <class F>
    class MinSearchIndividual : public Genetic::Individual <LinearDoubleDna>
    {
    public:
        MinSearchIndividual(bool generateDna = false, double dnaGenerateParameter = 2.0);

        void test();
    };
}

template <class F>
Genetic::MinSearchIndividual <F>::MinSearchIndividual(bool generateDna, double dnaGenerateParameter)
{
    if(generateDna)
	{
        dna.generate(dnaGenerateParameter);
	}
}

template <class F>
void Genetic::MinSearchIndividual <F>::test()
{
    score = (F::getResult(dna));
}

#endif // MINSEARCHINDIVIDUAL_H
