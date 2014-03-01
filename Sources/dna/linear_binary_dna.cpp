#include "linear_binary_dna.h"

void Genetic::LinearBinaryDna::mutate(double parameter)
{
    int randomId = rand() % dna.size();
    dna[randomId] = 1 - dna[randomId];
}

void Genetic::LinearBinaryDna::generate(double parameter)
{
    dna.resize((int)(parameter + 0.1));
    for(unsigned int i = 0; i < dna.size(); ++i)
    {
        dna[i] = rand() & 1;
    }
}

double Genetic::LinearBinaryDna::getDistance(Genetic::Dna& otherDna)
{
    double distance = 0.0;
    for(unsigned int i = 0; i < dna.size(); ++i)
    {
        if(dna[i] != dynamic_cast<LinearBinaryDna&>(otherDna).dna[i])
        {
            distance += 1.0;
        }
    }
    return distance;
}

void Genetic::LinearBinaryDna::print()
{
    for(unsigned int i = 0; i < dna.size(); ++i)
    {
        dnalog << static_cast<bool>(dna[i]);
    }
    dnalog << std::endl;
}

