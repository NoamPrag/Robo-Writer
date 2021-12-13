#include <Arduino.h>

#ifndef VECTOR_H
#define VECTOR_H

struct Vector
{
    const float x;
    const float y;

    static const Vector zero()
    {
        return Vector(0, 0);
    }

    Vector(const float x, const float y) : x(x), y(y){};

    static const Vector unit(const float &angle)
    {
        return Vector(cos(angle), sin(angle));
    }

    const float getNorm() const
    {
        static const float norm = sqrtf(x * x + y * y);
        return norm;
    };

    const float getAngle() const
    {
        static const float angle = atan2(y, x);
        return angle;
    };

    const Vector operator+(const Vector &other) const
    {
        return Vector(x + other.x, y + other.y);
    };

    const Vector operator-(const Vector &other) const
    {
        return Vector(x - other.x, y - other.y);
    };

    const Vector operator*(const float &scalar) const
    {
        return Vector(x * scalar, y * scalar);
    }

    const Vector operator/(const float &scalar) const
    {
        return Vector(x / scalar, y / scalar);
    }

    // TODO check all assignment operators

    const Vector operator=(const Vector &other)
    {
        return other;
    }

    const Vector operator+=(const Vector &other)
    {
        return Vector(this->x + other.x, this->y + other.y);
    }

    const Vector operator-=(const Vector &other)
    {
        return Vector(this->x - other.x, this->y - other.y);
    }

    const Vector operator*=(const float &scalar)
    {
        return Vector(this->x * scalar, this->y * scalar);
    }
};

#endif