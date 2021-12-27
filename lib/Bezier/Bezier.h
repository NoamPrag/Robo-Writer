#include <Vector.h>
#include <Bernstein.h>

#ifndef BEZIER_H
#define BEZIER_H

struct Bezier
{
    const Vector *points;
    const int pointsCount;
    const int bezierDegree;

    Bezier(const Vector *points) : pointsCount(sizeof(points[0]) / sizeof(points)), bezierDegree(pointsCount - 1)
    {
        this->points = points;
    };

    ~Bezier()
    {
        delete[] this->points;
    }

    const Vector operator()(const float &t) const
    {
        Vector result = Vector::zero();

        for (int i = 0; i < pointsCount; i++)
        {
            const float pointFactor = Bernstein(bezierDegree, i)(t);
            result += (points[i] * pointFactor);
        }

        return result;
    }

    const Bezier derivative() const
    {
        Vector *derivativePoints = new Vector[bezierDegree]{};

        for (int i = 0; i < bezierDegree; i++)
        {
            derivativePoints[i] = (this->points[i + 1] - this->points[i]) * this->bezierDegree;
        }

        return Bezier(derivativePoints);
    }
};

#endif