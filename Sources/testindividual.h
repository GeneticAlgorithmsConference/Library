#ifndef TEST_INDIVIDUAL_H
#define TEST_INDIVIDUAL_H

#include <iostream>

#include "individual/individual.h"
#include "dna/linear_binary_dna.h"

using namespace Genetic;

class TestIndividual : public Individual <LinearBinaryDna, int>
{
public:
	TestIndividual();
	void test();
	void generate();
	void mutate();
	static void recombine(Genetic::Individual <LinearBinaryDna, int>* parentIndividual1,
	                      Genetic::Individual <LinearBinaryDna, int>* parentIndividual2,
	                      Genetic::Individual <LinearBinaryDna, int>* childIndividual1,
	                      Genetic::Individual <LinearBinaryDna, int>* childIndividual2);
private:
	const int desiredValue = 13989;
};

#endif
