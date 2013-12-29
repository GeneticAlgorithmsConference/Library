#ifndef BASEDNA_H
#define BASEDNA_H

#include <vector>

namespace Genetic
{

	template <typename T>
	class BaseLinearDna
	{
	public:
		T& operator[](int id);
		int size();
		void resize(int newSize);
		virtual void mutate() = 0;
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
int Genetic::BaseLinearDna <T>::size()
{
	return dna.size();
}

template <typename T>
void Genetic::BaseLinearDna <T>::resize(int newSize)
{
	dna.resize(newSize);
}

#endif
