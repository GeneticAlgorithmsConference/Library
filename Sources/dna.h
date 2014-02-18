#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED

namespace Genetic
{
//    template <class D>
    class Dna
    {
    public:
		virtual void mutate(double parameter) = 0;
		virtual void generate(double parameter) = 0;
		virtual double getDistance(Genetic::Dna& dna) = 0;
    };
}

#endif // DNA_H_INCLUDED
