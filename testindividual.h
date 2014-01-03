#ifndef TEST_INDIVIDUAL_H
#define TEST_INDIVIDUAL_H

#include <iostream>

#include "individual.h"
#include "dnatypes.h"

using namespace Genetic;

class TestIndividual : public Individual <LinearBinaryDna>
{
public:
	TestIndividual();
	void test();
	void mutate();
private:
	const int desiredValue = 123498;
};

TestIndividual::TestIndividual()
{
	dna.resize(20);

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

#endif
