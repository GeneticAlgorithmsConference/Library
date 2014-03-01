#ifndef TREEEXPRESSIONINDIVIDUAL_H
#define TREEEXPRESSIONINDIVIDUAL_H

#include <vector>
#include <fstream>
#include <cmath>

#include "treeindividual.h"
#include "treeexpressiondna.h"
#include "log.h"

std::vector <std::pair <double, double> > loadTests(const char* fileName);

class TreeExpressionIndividual : public Genetic::TreeIndividual < Genetic::TreeExpressionDna , double>
{
public:
    TreeExpressionIndividual();

	TreeExpressionIndividual(bool generateDna);
    static void setTests(std::vector <std::pair <double, double> >& new_tests);
	void test();

private:
	static std::vector <std::pair <double, double> > tests;
};

#endif
