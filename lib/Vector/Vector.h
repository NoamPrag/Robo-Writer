#include <Arduino.h>

struct Vector
{
    float x;
    float y;

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
};
