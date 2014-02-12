#ifndef TEST_INDIVIDUAL_H
#define TEST_INDIVIDUAL_H

#include <iostream>

#include "individual.h"
#include "dnatypes.h"

using namespace Genetic;

class TestIndividual : public Individual <LinearBinaryDna>
{
public:
	TestIndividual(bool generateDna);
	void test();
	void mutate();
	static void recombine(Genetic::Individual <LinearBinaryDna>* parentIndividual1,
	                      Genetic::Individual <LinearBinaryDna>* parentIndividual2,
	                      Genetic::Individual <LinearBinaryDna>* childIndividual1,
	                      Genetic::Individual <LinearBinaryDna>* childIndividual2);
private:
	const int desiredValue = 13;
};

TestIndividual::TestIndividual(bool generateDna)
{
	dna.resize(10);
	for(int i = 0; i < dna.size(); ++i)
	{
		dna[i] = rand() % 2;
	}
}

void TestIndividual::test()
{
	int currentValue = 0;
	for(int i = 0; i < dna.size(); ++i)
	{
		currentValue = currentValue* 2 + static_cast<int>(dna[i]);
	}
	int delta = currentValue - desiredValue;
	if(delta < 0)
	{
		delta = -delta;
	}
	score = delta;

	// std::cout << "Individual: " << score << std::endl;
}

void TestIndividual::mutate()
{
	dna.mutate();
}

void TestIndividual::recombine(Genetic::Individual <LinearBinaryDna>* parentIndividual1,
                               Genetic::Individual <LinearBinaryDna>* parentIndividual2,
                               Genetic::Individual <LinearBinaryDna>* childIndividual1,
                               Genetic::Individual <LinearBinaryDna>* childIndividual2)
{
	Individual <LinearBinaryDna>::recombine(parentIndividual1,
	                                        parentIndividual2,
	                                        childIndividual1,
	                                        childIndividual2,
	                                        CROSSOVER, 2);
}

#endif
