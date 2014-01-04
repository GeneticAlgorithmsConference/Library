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
		~BaseTreeDna();
		// virtual void operator=(BaseTreeDna <T>& dna) = 0;
		virtual void mutate() = 0;

		static void swapRandomChildren(BaseTreeDna <T>* dna1,
		                               BaseTreeDna <T>* dna2);
		static void swapChildren(BaseTreeDna <T>* dna1, int id1,
		                         BaseTreeDna <T>* dna2, int id2);
		
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
Genetic::BaseTreeDna <T>::~BaseTreeDna()
{
	for(int i = 0; i < children.size(); ++i)
	{
		delete children[i];
	}
}

template <typename T>
void Genetic::BaseTreeDna <T>::swapChildren(BaseTreeDna <T>* dna1, int id1,
                                            BaseTreeDna <T>* dna2, int id2)
{
	BaseTreeDna <T>* tmp = dna1 -> getChild(id1);
	dna1 -> setChild(id1, dna2 -> getChild(id2));
	dna2 -> setChild(id2, tmp);
}

template <typename T>
void Genetic::BaseTreeDna <T>::swapRandomChildren(BaseTreeDna <T>* dna1,
                                                  BaseTreeDna <T>* dna2)
{
	int id1 = rand() % dna1 -> getChildrenNum();
	int id2 = rand() % dna2 -> getChildrenNum();
	BaseTreeDna <T>* tmp = dna1 -> getChild(id1);
	dna1 -> setChild(id1, dna2 -> getChild(id2));
	dna2 -> setChild(id2, tmp);
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