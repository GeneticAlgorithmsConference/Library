#ifndef BASEDNA_H
#define BASEDNA_H

#include <vector>

#include "log.h"

namespace Genetic
{

	template <typename T>
	class BaseLinearDna
	{
	public:
		T& operator[](int id);
		int size() const;
		void resize(int newSize);
		virtual void mutate(double parameter = 1.0) = 0;
        void print();
	protected:
		std::vector <T> dna;
	};

}

template <typename T>
T& Genetic::BaseLinearDna <T>::operator[](int id)
{
	return dna[id];
}

template <typename T>
int Genetic::BaseLinearDna <T>::size() const
{
	return dna.size();
}

template <typename T>
void Genetic::BaseLinearDna <T>::resize(int newSize)
{
	dna.resize(newSize);
}

template <typename T>
void Genetic::BaseLinearDna <T>::print()
{
	for(int i = 0; i < dna.size(); ++i)
    {
        dnalog.width(10);
        dnalog << dna[i];
    }
    dnalog << '\n';
}

#endif
