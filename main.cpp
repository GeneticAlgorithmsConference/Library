#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "log.h"
#include "dnatypes.h"
#include "individual.h"
#include "generation.h"
#include "population.h"

//#include "treeindividual.h"
//#include "testindividual.h"
//#include "treeexpressionindividual.h"
#include "minsearchindividual.h"

using namespace std;
using namespace Genetic;

#ifdef ENABLE_TESTS

void testRecombinationOne(Genetic::RecombinationType rec_type, bool use_constant,
                          double rec_par = 0.0, int crossover_points_num = 1)
{
	Genetic::Individual <double>* i1;
	Genetic::Individual <double>* i2;
	Genetic::Individual <double>* i3;
	Genetic::Individual <double>* i4;

	i1 = new Genetic::Individual <double>();
	i2 = new Genetic::Individual <double>();
	i3 = new Genetic::Individual <double>();
	i4 = new Genetic::Individual <double>();

	int dna_size = 8;
	vector<double> dna;
	dna.resize(dna_size);

	cout << "--- o r i g i n a l ---------------------------------------------------\n";

	cout << "DNA 1:  ";
	for(int i = 0; i < dna_size; ++i)
	{
		dna[i] = (double)(rand()%1000) / 1000.0;
		if(use_constant)
		{
			dna[i] = 0;
		}
		cout.width(6);
		cout << fixed << setprecision(4) << dna[i] << "  ";
	}
	cout << endl;
	i1 -> setDNA(dna);
	i3 -> setDNA(dna);
	i4 -> setDNA(dna);

	cout << "DNA 2:  ";
	for(int i = 0; i < dna_size; ++i)
	{
		dna[i] = (double)(rand()%1000) / 1000.0;
		if(use_constant)
			dna[i] = 1;
		cout.width(6);
		cout << fixed << setprecision(4) << dna[i] << "  ";
	}
	cout << endl;
	i2 -> setDNA(dna);

	Genetic::Individual<double>::recombine(i1, i2, i3, i4, rec_type, rec_par, crossover_points_num);

	cout << "--- r e s u l t -------------------------------------------------------\n";

	dna = i3 -> getDNA();
	cout << "DNA 1:  ";
	for(int i = 0; i < dna_size; ++i)
	{
		cout.width(6);
		cout << fixed << setprecision(4) << dna[i] << "  ";
	}
	cout << endl;

	dna = i4 -> getDNA();
	cout << "DNA 2:  ";
	for(int i = 0; i < dna_size; ++i)
	{
		cout.width(6);
		cout << fixed << setprecision(4) << dna[i] << "  ";
	}
	cout << endl;

	delete i1;
	delete i2;
	delete i3;
	delete i4;
}

void testMutationOne(Genetic::MutationType mut_type, bool use_constant,
                     double probability, int attempts = 1, double mut_par = 5.0)
{
	Genetic::Individual<double>* i1 = new Genetic::Individual<double>();

	int dna_size = 8;
	vector<double> dna;
	dna.resize(dna_size);

	cout << "--- o r i g i n a l ---------------------------------------------------\n";

	for(int i = 0; i < dna_size; ++i)
	{
		dna[i] = (double)(rand()%1000) / 1000.0;
		if(use_constant)
			dna[i] = 0.5;
		cout.width(6);
		cout << fixed << setprecision(4) << dna[i] << "  ";
	}
	cout << endl;
	i1 -> setDNA(dna);


	i1 -> mutate(mut_type, probability, attempts, mut_par);

	cout << "--- r e s u l t -------------------------------------------------------\n";

	dna = i1 -> getDNA();
	for(int i = 0; i < dna_size; ++i)
	{
		cout.width(6);
		cout << fixed << setprecision(4) << dna[i] << "  ";
	}
	cout << endl;

	delete i1;
}

void testRecombination()
{
	bool USE_CONSTANT_DNA = false;
	Genetic::RecombinationType q;

	cout << "========================== D I S C R E T E ============================\n";
	q = Genetic::DISCRETE;
	testRecombinationOne(q, USE_CONSTANT_DNA);
	cout << "=======================================================================\n\n";


	cout << "======================= I N T E R M I D E A T E =======================\n";
	q = Genetic::INTERMEDIATE;
	testRecombinationOne(q, USE_CONSTANT_DNA, 0.0);
	cout << "=======================================================================\n\n";


	cout << "============================== L I N E ================================\n";
	q = Genetic::LINE;
	testRecombinationOne(q, USE_CONSTANT_DNA, 0.0);
	cout << "=======================================================================\n\n";


	cout << "========================== C R O S S O V E R ==========================\n";
	q = Genetic::CROSSOVER;
	testRecombinationOne(q, USE_CONSTANT_DNA, 0.0, 1);
	cout << "=======================================================================\n\n";

	cout << "================== S H U F F L E R   C R O S S O V E R ================\n";
	q = Genetic::CROSSOVER;
	testRecombinationOne(q, USE_CONSTANT_DNA, 0.0, 1);
	cout << "=======================================================================\n\n";

}

void testMutation()
{
	bool USE_CONSTANT_DNA = false;
	int ATTEMPTS = 1;
	double PROBABILITY = 0.25;
	Genetic::MutationType q;

	cout << "========================== D I S C R E T E ============================\n";
	q = Genetic::REAL_VALUE_MUTATION;
	testMutationOne(q, USE_CONSTANT_DNA, PROBABILITY, ATTEMPTS, 5);
	cout << "=======================================================================\n\n";

	cout << "============================ B I N A R Y ==============================\n";
	q = Genetic::BINARY_MUTATION;
	testMutationOne(q, USE_CONSTANT_DNA, PROBABILITY, ATTEMPTS);
	cout << "=======================================================================\n\n";

	cout << "============================== S W A P ================================\n";
	q = Genetic::SWAP_MUTATION;
	testMutationOne(q, USE_CONSTANT_DNA, PROBABILITY, ATTEMPTS);
	cout << "=======================================================================\n\n";

}

#endif

class MyTargetFunction
{
public:
    static double getResult(LinearDoubleDna &arguments)
    {
        double x = arguments[0];
//        double y = arguments[1];
//        double z = arguments[2];
//        return fabs(x * y - y * z + z * x) / (z + x + y);
        return 2*x*x+8*x-16;
    }
};

int main()
{
	// srand(time(NULL));

#ifdef ENABLE_TESTS

	testRecombination();
	cout << "\n\n\n\n";
	testMutation();

#endif

	// Population < Generation < TestIndividual > > test(10, ELITE_SELECTION);
	// test.init(time(NULL));

	// for(int i = 0; i < 1000; ++i)
	// {
	// 	test.genNextGeneration();
	// }

	Population < Generation < MinSearchIndividual <MyTargetFunction> > > test(100, ELITE_SELECTION, CROSSOVER, 1, 1, 100, 17);
	test.initGeneration(time(NULL), 3);
//	test.

	for(int i = 0; i < 10000; ++i)
	{
		dnalog << "Step: " << i << endl;
		test.genNextGeneration();
	}

	return 0;
}

