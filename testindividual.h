#ifndef TEST_INDIVIDUAL_H
#define TEST_INDIVIDUAL_H

#include "individual.h"

using namespace Genetic;

class Test1234
{
public:
	int a;
};

template <class T>
class TestIndividual : public Individual <T>
{
public:
	TestIndividual();
};

template <class T>
TestIndividual <T>::TestIndividual()
{
	Individual<T>::dna.resize(10);
}

#endif
