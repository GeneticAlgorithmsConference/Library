#include <iostream>
#include "individual.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void testRecombinationOne(Genetic::RecombinationType recType, bool use_constant, double recPar = 2.0)
{
    Genetic::Individual* i1;
    Genetic::Individual* i2;

    i1 = new Genetic::Individual();
    i2 = new Genetic::Individual();

    int dna_size = 8;
    vector<double> dna;
    dna.resize(dna_size);

    cout << "--- o r i g i n a l ---------------------------------------------------\n";

    cout << "DNA 1:  ";
    for(int i = 0; i < dna_size; ++i)
    {
        dna[i] = (double)(rand()%1000) / 1000.0;
        if(use_constant)
            dna[i] = 0;
        cout.width(6);
        cout << fixed << setprecision(4) << dna[i] << "  ";
    }
    cout << endl;
    i1 -> setDna(dna);

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
    i2 -> setDna(dna);

    Genetic::Individual::recombine(i1, i2, recType, recPar);

    cout << "--- r e s u l t -------------------------------------------------------\n";

    dna = i1 -> getDna();
    cout << "DNA 1:  ";
    for(int i = 0; i < dna_size; ++i)
    {
        cout.width(6);
        cout << fixed << setprecision(4) << dna[i] << "  ";
    }
    cout << endl;

    dna = i2 -> getDna();
    cout << "DNA 2:  ";
    for(int i = 0; i < dna_size; ++i)
    {
        cout.width(6);
        cout << fixed << setprecision(4) << dna[i] << "  ";
    }
    cout << endl;
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
    testRecombinationOne(q, USE_CONSTANT_DNA, 0.25);
    cout << "=======================================================================\n\n";


    cout << "============================== L I N E ================================\n";
    q = Genetic::LINE;
    testRecombinationOne(q, USE_CONSTANT_DNA, 0.25);
    cout << "=======================================================================\n\n";

}

int main()
{
    srand(time(NULL));
    testRecombination();

    return 0;
}
