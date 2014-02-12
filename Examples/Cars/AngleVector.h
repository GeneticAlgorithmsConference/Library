#ifndef ANGLEVECTOR_H
#define ANGLEVECTOR_H

struct AngleVector
{
    double angle, length;
    unsigned char r, g, b;
    bool wheel;

    // Wheel properties
    double radius, motorSpeed;
    double x();
    double y();
};

#endif // ANGLEVECTOR_H
