#include "linearrealdna.h"

void Genetic::LinearRealDna::mutate(double param)
{
    int attemptsNum = static_cast<int>(param);
    double dlt = 0.0;
    for(int i = 0; i < attemptsNum; ++i)
    {
        if(static_cast<double>(rand() % 10000) / 10000.0 <= 1.0 / static_cast<double>(attemptsNum))
        {
            dlt += pow(2.0, -i);
        }
    }

    if(rand() & 1)
    {
        dlt = -dlt;
    }

    dlt *= 0.5;
    int a = rand() % dna.size();

    dna[a] += dlt;
}

void Genetic::LinearRealDna::generate(double param)
{
    dna.resize((int)(param + 0.1));
    for(int i = 0; i < dna.size(); ++i)
    {
        dna[i] = ((double)(rand() % 1000000)) / 1000.0;
    }
}

double Genetic::LinearRealDna::getDistance(Genetic::Dna& other)
{
    double distance = 0.0;
    double delta;
    for(int i = 0; i < dna.size(); ++i)
    {
        delta = (dna[i] - dynamic_cast<LinearRealDna&>(other).dna[i]);
        distance += delta * delta;
    }
    distance = sqrt(distance);
    return distance;
}

