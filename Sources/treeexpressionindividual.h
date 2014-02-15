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

class TreeExpressionIndividual : public Genetic::TreeIndividual < Genetic::TreeExpressionDna , double>
{
public:
    TreeExpressionIndividual(): Genetic::TreeIndividual < Genetic::TreeExpressionDna , double> () { };

	TreeExpressionIndividual(bool generateDna);
	void test();

private:
	static std::vector <std::pair <double, double> > tests;
};

std::vector <std::pair <double, double> > TreeExpressionIndividual::tests = loadTests("tests.txt");

void TreeExpressionIndividual::test()
{
	double currentSum = 0.0;
	for(int i = 0; i < tests.size(); ++i)
	{
		currentSum += fabs(tests[i].second - dna.getValue(tests[i].first));
	}
	score = currentSum;
	if(std::isnan(score))
	{
		score = 1.0e20;
	}
}

#endif
