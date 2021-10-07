#include <Arduino.h>

struct Vector
{
public:
    const float x;
    const float y;

    Vector(const float x, const float y) : x(x), y(y){};

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

    const Vector operator+(const Vector other) const
    {
        return Vector(x + other.x, y + other.y);
    };

    const Vector operator-(const Vector other) const
    {
        return Vector(x - other.x, y - other.y);
    };

    const Vector operator*(const float scalar) const
    {
        return Vector(x * scalar, y * scalar);
    }

    const Vector operator/(const float scalar) const
    {
        return Vector(x / scalar, y / scalar);
    }
};
