#ifndef BASE_INDIVIDUAL_H
#define BASE_INDIVIDUAL_H

namespace Genetic
{

class BaseIndividual
{
public:
	virtual ~BaseIndividual() {}
	virtual bool scoreLessThan(Genetic::BaseIndividual* individual) = 0;
	virtual bool dnaDistanceLessThan(Genetic::BaseIndividual* individual2,
	                                 Genetic::BaseIndividual* individual3,
	                                 Genetic::BaseIndividual* individual4) = 0;
	virtual void generate() = 0;
	virtual void test() = 0;
private:
};

}

#endif
