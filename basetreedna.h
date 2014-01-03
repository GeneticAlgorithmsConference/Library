#ifndef TREEDNA_H
#define TREEDNA_H

#include <vector>

namespace Genetic
{

	template <typename T>
	class BaseTreeDna
	{
	public:
		BaseTreeDna();
		virtual void operator=(BaseTreeDna <T>* dna);
		virtual void mutate() = 0;
		
		BaseTreeDna <T>* getRandom();
		BaseTreeDna <T>* getRandomWithChildren();

		int getChildrenNum() const;
		BaseTreeDna <T>* getChild(int id);
		void setChild(int id, BaseTreeDna <T> *value);
	protected:
		std::vector < BaseTreeDna <T>* > children;
		T value;
	};

}

template <typename T>
Genetic::BaseTreeDna <T>::BaseTreeDna()
{
}

template <typename T>
void Genetic::BaseTreeDna <T>::operator=(BaseTreeDna <T> *dna)
{
	value = dna -> value;
	children.resize(dna -> getChildrenNum());
	for(int i = 0; i < children.size(); ++i)
	{
		children[i] = dna -> children[i];
	}
}

template <typename T>
Genetic::BaseTreeDna <T>* Genetic::BaseTreeDna <T>::getRandom()
{
	BaseTreeDna <T>* current = this;
	int id;
	while(true)
	{
		id = rand() % (current -> getChildrenNum() + 1);
		if(id == current -> getChildrenNum())
		{
			break;
		} else {
			current = current -> getChild(id);
		}
	}
	return current;
}


template <typename T>
Genetic::BaseTreeDna <T>* Genetic::BaseTreeDna <T>::getRandomWithChildren()
{
	BaseTreeDna <T>* current = this;
	int id;
	while(current -> getChildrenNum() > 0)
	{
		id = rand() % (current -> getChildrenNum() + 1);
		if((id == current -> getChildrenNum()) || (current -> getChild(id) -> getChildrenNum() == 0))
		{
			break;
		} else {
			current = current -> getChild(id);
		}
	}
	return current;
}


template <typename T>
int Genetic::BaseTreeDna <T>::getChildrenNum() const
{
	return children.size();
}

template <typename T>
Genetic::BaseTreeDna <T>* Genetic::BaseTreeDna <T>::getChild(int id)
{
	return children[id];
}

template <typename T>
void Genetic::BaseTreeDna <T>::setChild(int id, BaseTreeDna <T>* value)
{
	children[id] = value;
}

#endif
