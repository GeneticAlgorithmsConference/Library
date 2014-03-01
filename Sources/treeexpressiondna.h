#ifndef TREEEXPRESSIONDNA_H
#define TREEEXPRESSIONDNA_H

#include <iostream>
#include <math.h>

#include "genetic.h"
#include "log.h"

using std::endl;

namespace Genetic
{

	class TreeExpressionDna : public BaseTreeDna <unsigned int>
	{
	public:
		TreeExpressionDna();
		TreeExpressionDna(int currentDepth);

		void mutate(double parameter);
		void generate(double parameter);

        TreeExpressionDna& operator=(TreeExpressionDna& dna);
        std::string print();
		double getValue(double x) const;

	private:
		int range;
		static const int maxDepth;
	};
}

#endif
