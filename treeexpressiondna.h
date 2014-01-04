#ifndef TREEEXPRESSIONDNA_H
#define TREEEXPRESSIONDNA_H

#include <iostream>

#include "basetreedna.h"

namespace Genetic
{

	class TreeExpressionDna : public BaseTreeDna <unsigned int>
	{
	public:
		TreeExpressionDna();
		TreeExpressionDna(int currentDepth);
		void operator=(TreeExpressionDna& dna);
		void mutate();
		void print();
	private:
		int range;
		static const int maxDepth;
	};

	const int TreeExpressionDna::maxDepth = 6;

}

Genetic::TreeExpressionDna::TreeExpressionDna()
{
	
}

Genetic::TreeExpressionDna::TreeExpressionDna(int currentDepth)
{
	range = 10000;
	value = rand() % 3;
	if(currentDepth == maxDepth)
	{
		value = 2;
	}

	if(value == 0)
	{
		value = rand() % 5;
		children.resize(1);
		children[0] = new Genetic::TreeExpressionDna(currentDepth + 1);
	} else if(value == 1)
	{
		value = rand() % 5 + 5;
		children.resize(2);
		children[0] = new Genetic::TreeExpressionDna(currentDepth + 1);
		children[1] = new Genetic::TreeExpressionDna(currentDepth + 1);
	} else {
		value = rand() % (2 * range + 1) + 10;
	}
}

void Genetic::TreeExpressionDna::operator=(TreeExpressionDna& dna)
{
	value = dna.value;
	children.resize(dna.getChildrenNum());
	for(int i = 0; i < children.size(); ++i)
	{
		children[i] = new TreeExpressionDna;
		*children[i] = *(dna.children[i]);
	}
}

void Genetic::TreeExpressionDna::mutate()
{
	// 0 - abs
	// 1 - sin
	// 2 - cos
	// 3 - tan
	// 4 - ctg

	// 5 - +
	// 6 - -
	// 7 - *
	// 8 - /
	// 9 - ^

	if(value <= 4)
	{
		value = rand() % 5;
	} else if(value <= 9)
	{
		value = rand() % 5 + 5;
	} else {
		value = rand() % (2 * range + 1) + 10;
	}
}

void Genetic::TreeExpressionDna::print()
{
	static const char* s[] = {
		"abs",
		"sin",
		"cos",
		"tan",
		"ctg",
		"+",
		"-",
		"*",
		"/",
		"^",
		"x"
	};
	if(value <= 10)
	{
		std::cout << s[value] << "( ";
		for(int i = 0; i < static_cast<int>(children.size()) - 1; ++i)
		{
			dynamic_cast<TreeExpressionDna*>(children[i]) -> print();
			std::cout << ", ";
		}
		if(children.size() > 0)
		{
			dynamic_cast<TreeExpressionDna*>(children[children.size() - 1]) -> print();
		}
		std::cout << " )";
	} else {
		std::cout << value;
	}
}

#endif
