#ifndef LINEARDOUBLEDNA_H
#define LINEARDOUBLEDNA_H

#include <math.h>
#include "baselineardna.h"

namespace Genetic
{
	class LinearDoubleDna : public BaseLinearDna<double>
	{
	public:
		void mutate(double parameter);
		void generate(double parameter);
	};

}

void Genetic::LinearDoubleDna::mutate(double parameter)
{
    double dlt = 0.0;
    for(double i = 1.0; i < parameter; ++i)
    {
        if(static_cast<double>(rand()%10000) / 10000.0 <= 1.0 / parameter)
        {
            dlt += pow(2.0, -i);
        }
    }

    if(rand() & 1)
    {
        dlt = -dlt;
    }

    dlt *= 0.5;
    int a = rand() % dna.size();

    dna[a] += dlt;
}

void Genetic::LinearDoubleDna::generate(double parameter)
{
    dna.resize(parameter);
    for(int i = 0; i < dna.size(); ++i)
    {
        dna[i] = ((double)(rand() % 1000000)) / 1000.0;
    }
}

#endif // LINEARDOUBLEDNA_H
