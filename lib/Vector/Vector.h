#include <Arduino.h>

#ifndef VECTOR_H
#define VECTOR_H

struct Vector
{
    float x;
    float y;

    static const Vector zero()
    {
        return Vector(0, 0);
    }

    Vector(const float x, const float y) : x(x), y(y){};

    Vector() : x(0), y(0){};

    static const Vector unit(const float &angle)
    {
        return Vector(cos(angle), sin(angle));
    }

    const float getNorm() const
    {
        const float norm = sqrtf(x * x + y * y);
        return norm;
    };

    const float getAngle() const
    {
        const float angle = atan2(y, x);
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

    const void operator=(const Vector &other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    const void operator+=(const Vector &other)
    {
        this->x += other.x;
        this->y += other.y;
    }

    const void print() const
    {
        Serial.print(x);
        Serial.print(", \t");
        Serial.println(y);
    }
};

#endif