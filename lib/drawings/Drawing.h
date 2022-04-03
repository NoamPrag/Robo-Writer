#ifndef DRAWING_H
#define DRAWING_H

#include <Bezier.h>

struct Drawing
{
    const Bezier *curves;
    const float scaleFactor;
    const Vector offset;

    const int numberOfCurves;

    Drawing(const Bezier *curves, const float &scaleFactor, const Vector &offset)
        : curves(curves),
          scaleFactor(scaleFactor),
          offset(offset),
          numberOfCurves(sizeof(curves[0]) / sizeof(curves))
    {
    }

    ~Drawing()
    {
        delete[] curves;
    };
};

#endif