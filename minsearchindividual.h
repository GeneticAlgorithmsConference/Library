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
        MinSearchIndividual(bool generateDna = true);
        void test();
        void mutate();
    private:
        std::function<double()> _f;
    };
}

template <class F>
Genetic::MinSearchIndividual <F>::MinSearchIndividual(bool generateDna)
{
    if(generateDna)
	{
        dna.resize(20);
        for(int i = 0; i < dna.size(); ++i)
        {
            dna[i] = ((double)(rand() % 1000000)) / 1000.0;
        }
	} else {
		dna.resize(0);
	}
}

template <class F>
void Genetic::MinSearchIndividual <F>::test()
{
    score = (F::getResult(dna));
}

template <class F>
void Genetic::MinSearchIndividual <F>::mutate()
{
	dna.mutate(3);
}

#endif // MINSEARCHINDIVIDUAL_H
