#include <qmath.h>

#include "AngleVector.h"

double AngleVector::x()
{
    return qCos(angle) * length;
}

double AngleVector::y()
{
    return qSin(angle) * length;
}
