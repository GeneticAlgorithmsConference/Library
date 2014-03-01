#include "treeexpressionindividual.h"

std::vector <std::pair <double, double> > TreeExpressionIndividual::tests;

TreeExpressionIndividual::TreeExpressionIndividual()
       : Genetic::TreeIndividual < Genetic::TreeExpressionDna , double> ()
{

}

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

void TreeExpressionIndividual::setTests(std::vector<std::pair<double, double> > &new_tests)
{
    tests = new_tests;
}

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
