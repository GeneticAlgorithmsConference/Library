#ifndef TREEEXPRESSIONINDIVIDUAL_H
#define TREEEXPRESSIONINDIVIDUAL_H

#include <vector>
#include <fstream>

#include "treeindividual.h"
#include "treeexpressiondna.h"
#include "log.h"

std::vector <std::pair <double, double> > loadTests(const char* fileName)
{
	std::ifstream inputData(fileName);
	std::vector <std::pair <double, double> > tests;
	int testsNum;
	inputData>> testsNum;
	tests.resize(testsNum);
	for(int i = 0; i < testsNum; ++i)
	{
		inputData >> tests[i].first >> tests[i].second;
	}
	return tests;
}

class TreeExpressionIndividual : public TreeIndividual < TreeExpressionDna >
{
public:
	TreeExpressionIndividual(bool generateDna);
	void test();
	void mutate();
	static void recombine(TreeExpressionIndividual* parentIndividual1,
	                      TreeExpressionIndividual* parentIndividual2,
	                      TreeExpressionIndividual* childIndividual1,
	                      TreeExpressionIndividual* childIndividual2);
private:
	static std::vector <std::pair <double, double> > tests;
};

std::vector <std::pair <double, double> > TreeExpressionIndividual::tests = loadTests("tests.txt");

TreeExpressionIndividual::TreeExpressionIndividual(bool generateDna)
{
	if(generateDna)
	{
		dna = new TreeExpressionDna(1);
	} else {
		dna = new TreeExpressionDna();
	}
	// dna -> print();
	// std::cout << std::endl;
}

void TreeExpressionIndividual::test()
{
	double currentSum = 0.0;
	for(int i = 0; i < tests.size(); ++i)
	{
		currentSum += fabs(tests[i].second - dna -> getValue(tests[i].first));
	}
	currentSum /= tests.size();
	score = currentSum;
	if(isnan(score))
	{
		score = 100000.0;
	}
}

void TreeExpressionIndividual::mutate()
{
	dna -> getRandom() -> mutate();
}

void TreeExpressionIndividual::recombine(TreeExpressionIndividual* parentIndividual1,
                                         TreeExpressionIndividual* parentIndividual2,
                                         TreeExpressionIndividual* childIndividual1,
                                         TreeExpressionIndividual* childIndividual2)
{
	// TreeIndividual::recombine(dynamic_cast<TreeIndividual <TreeExpressionDna>* >(parentIndividual1),
	//                           dynamic_cast<TreeIndividual <TreeExpressionDna>* >(parentIndividual2),
	//                           dynamic_cast<TreeIndividual <TreeExpressionDna>* >(childIndividual1),
	//                           dynamic_cast<TreeIndividual <TreeExpressionDna> *>(childIndividual2));
	TreeIndividual::recombine((parentIndividual1),
	                          (parentIndividual2),
	                          (childIndividual1),
	                          (childIndividual2));
}

#endif
