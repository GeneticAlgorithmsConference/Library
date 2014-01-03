#ifndef TREEEXPRESSIONINDIVIDUAL_H
#define TREEEXPRESSIONINDIVIDUAL_H

#include "treeindividual.h"
#include "treeexpressiondna.h"

class TreeExpressionIndividual : public TreeIndividual < TreeExpressionDna >
{
public:
	TreeExpressionIndividual();
	void test();
	void mutate();
	void recombine(TreeExpressionIndividual* parentIndividual1,
	               TreeExpressionIndividual* parentIndividual2,
	               TreeExpressionIndividual* childIndividual1,
	               TreeExpressionIndividual* childIndividual2);
};

TreeExpressionIndividual::TreeExpressionIndividual()
{
	dna = new TreeExpressionDna();
}

void TreeExpressionIndividual::test()
{
	
}

void TreeExpressionIndividual::mutate()
{
	
}

void TreeExpressionIndividual::recombine(TreeExpressionIndividual* parentIndividual1,
                                         TreeExpressionIndividual* parentIndividual2,
                                         TreeExpressionIndividual* childIndividual1,
                                         TreeExpressionIndividual* childIndividual2)
{
	TreeIndividual::recombine(dynamic_cast<TreeIndividual <TreeExpressionDna>* >(parentIndividual1),
	                          dynamic_cast<TreeIndividual <TreeExpressionDna>* >(parentIndividual2),
	                          dynamic_cast<TreeIndividual <TreeExpressionDna>* >(childIndividual1),
	                          dynamic_cast<TreeIndividual <TreeExpressionDna> *>(childIndividual2));
}

#endif
