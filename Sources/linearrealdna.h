#ifndef LINEARDOUBLEDNA_H
#define LINEARDOUBLEDNA_H

#include <math.h>
#include <stdlib.h>

#include "log.h"
#include "baselineardna.h"

namespace Genetic
{
	class LinearRealDna : public BaseLinearDna<double>
	{
	public:
		void mutate(double param);
		void generate(double param);
		double getDistance(Genetic::Dna& dna);
	};

}

#endif // LINEARDOUBLEDNA_H
