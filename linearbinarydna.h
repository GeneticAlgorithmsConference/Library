#ifndef LINEARBINARYDNA_H
#define LINEARBINARYDNA_H

#include "baselineardna.h"

namespace Genetic
{

	class LinearBinaryDna : public BaseLinearDna<unsigned char>
	{
	public:
		void mutate(double parameter = 0.0) override;
		void generate(double dnaSize) override;
		double getDistance(BaseLinearDna <unsigned char>* dna) override;
		void print();
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

double Genetic::LinearBinaryDna::getDistance(BaseLinearDna <unsigned char>* otherDna)
{
	double distance = 0.0;
	for(int i = 0; i < dna.size(); ++i)
	{
		// if(dna[i] != otherDna -> dna[i])
		// {
		// 	distance += 1.0;
		// }
	}
	return distance;
}

void Genetic::LinearBinaryDna::print()
{
	for(int i = 0; i < dna.size(); ++i)
	{
		dnalog << static_cast<bool>(dna[i]);
	}
	dnalog << std::endl;
}

#endif
