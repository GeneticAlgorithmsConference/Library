#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

// #include "individual.h"
// #include "population.h"
#include "testindividual.h"

using namespace std;

// void testRecombinationOne(Genetic::RecombinationType recType, bool use_constant,
//                           double recPar = 0.0, int crossover_points_num = 1)
// {
//     Genetic::Individual <double>* i1;
//     Genetic::Individual <double>* i2;
//     Genetic::Individual <double>* i3;
//     Genetic::Individual <double>* i4;
// 
//     i1 = new Genetic::Individual <double>();
//     i2 = new Genetic::Individual <double>();
//     i3 = new Genetic::Individual <double>();
//     i4 = new Genetic::Individual <double>();
// 
//     int dna_size = 8;
//     vector<double> dna;
//     dna.resize(dna_size);
// 
//     cout << "--- o r i g i n a l ---------------------------------------------------\n";
// 
//     cout << "DNA 1:  ";
//     for(int i = 0; i < dna_size; ++i)
//     {
//         dna[i] = (double)(rand()%1000) / 1000.0;
//         if(use_constant)
//             dna[i] = 0;
//         cout.width(6);
//         cout << fixed << setprecision(4) << dna[i] << "  ";
//     }
//     cout << endl;
//     i1 -> setDna(dna);
//     i3 -> setDna(dna);
//     i4 -> setDna(dna);
// 
//     cout << "DNA 2:  ";
//     for(int i = 0; i < dna_size; ++i)
//     {
//         dna[i] = (double)(rand()%1000) / 1000.0;
//         if(use_constant)
//             dna[i] = 1;
//         cout.width(6);
//         cout << fixed << setprecision(4) << dna[i] << "  ";
//     }
//     cout << endl;
//     i2 -> setDna(dna);
// 
//     Genetic::Individual<double>::recombine(i1, i2, i3, i4, recType, recPar, crossover_points_num);
// 
//     cout << "--- r e s u l t -------------------------------------------------------\n";
// 
//     dna = i3 -> getDna();
//     cout << "DNA 1:  ";
//     for(int i = 0; i < dna_size; ++i)
//     {
//         cout.width(6);
//         cout << fixed << setprecision(4) << dna[i] << "  ";
//     }
//     cout << endl;
// 
//     dna = i4 -> getDna();
//     cout << "DNA 2:  ";
//     for(int i = 0; i < dna_size; ++i)
//     {
//         cout.width(6);
//         cout << fixed << setprecision(4) << dna[i] << "  ";
//     }
//     cout << endl;
// 
//     delete i1;
//     delete i2;
//     delete i3;
//     delete i4;
// }
// 
// void testMutationOne(Genetic::MutationType mutType, bool use_constant,
//                      double probability, int attempts = 1, double mutPar = 5.0)
// {
//     Genetic::Individual<double>* i1 = new Genetic::Individual<double>();
// 
//     int dna_size = 8;
//     vector<double> dna;
//     dna.resize(dna_size);
// 
//     cout << "--- o r i g i n a l ---------------------------------------------------\n";
// 
//     for(int i = 0; i < dna_size; ++i)
//     {
//         dna[i] = (double)(rand()%1000) / 1000.0;
//         if(use_constant)
//             dna[i] = 0.5;
//         cout.width(6);
//         cout << fixed << setprecision(4) << dna[i] << "  ";
//     }
//     cout << endl;
//     i1 -> setDna(dna);
// 
// 
//     i1 -> mutate(mutType, probability, attempts, mutPar);
// 
//     cout << "--- r e s u l t -------------------------------------------------------\n";
// 
//     dna = i1 -> getDna();
//     for(int i = 0; i < dna_size; ++i)
//     {
//         cout.width(6);
//         cout << fixed << setprecision(4) << dna[i] << "  ";
//     }
//     cout << endl;
// 
//     delete i1;
// }
// 
// void testRecombination()
// {
//     bool USE_CONSTANT_DNA = false;
//     Genetic::RecombinationType q;
// 
//     cout << "========================== D I S C R E T E ============================\n";
//     q = Genetic::DISCRETE;
//     testRecombinationOne(q, USE_CONSTANT_DNA);
//     cout << "=======================================================================\n\n";
// 
// 
//     cout << "======================= I N T E R M I D E A T E =======================\n";
//     q = Genetic::INTERMEDIATE;
//     testRecombinationOne(q, USE_CONSTANT_DNA, 0.0);
//     cout << "=======================================================================\n\n";
// 
// 
//     cout << "============================== L I N E ================================\n";
//     q = Genetic::LINE;
//     testRecombinationOne(q, USE_CONSTANT_DNA, 0.0);
//     cout << "=======================================================================\n\n";
// 
// 
//     cout << "========================== C R O S S O V E R ==========================\n";
//     q = Genetic::CROSSOVER;
//     testRecombinationOne(q, USE_CONSTANT_DNA, 0.0, 1);
//     cout << "=======================================================================\n\n";
// 
//     cout << "================== S H U F F L E R   C R O S S O V E R ================\n";
//     q = Genetic::CROSSOVER;
//     testRecombinationOne(q, USE_CONSTANT_DNA, 0.0, 1);
//     cout << "=======================================================================\n\n";
// 
// }
// 
// void testMutation()
// {
//     bool USE_CONSTANT_DNA = false;
//     int ATTEMPTS = 1;
//     double PROBABILITY = 0.25;
//     Genetic::MutationType q;
// 
//     cout << "========================== D I S C R E T E ============================\n";
//     q = Genetic::REAL_VALUE_MUTATION;
//     testMutationOne(q, USE_CONSTANT_DNA, PROBABILITY, ATTEMPTS, 5);
//     cout << "=======================================================================\n\n";
// 
//     cout << "============================ B I N A R Y ==============================\n";
//     q = Genetic::BINARY_MUTATION;
//     testMutationOne(q, USE_CONSTANT_DNA, PROBABILITY, ATTEMPTS);
//     cout << "=======================================================================\n\n";
// 
//     cout << "============================== S W A P ================================\n";
//     q = Genetic::SWAP_MUTATION;
//     testMutationOne(q, USE_CONSTANT_DNA, PROBABILITY, ATTEMPTS);
//     cout << "=======================================================================\n\n";
// 
// }

int main()
{
//     srand(time(NULL));
// 
//     testRecombination();
//     cout << "\n\n\n\n";
//     testMutation();
//     
//     Population<Individual
	TestIndividual<int> test;
    return 0;
}
