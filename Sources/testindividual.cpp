#include "testindividual.h"


TestIndividual::TestIndividual()
{

}

void TestIndividual::generate()
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
