#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const float dx = 0.005; // cm

const float maxXPosition = 12;

const float f(const float &x)
{
    return 7 * sin(x);
}

void setup()
{
    // Reset
    attachServos();

    for (float x = -maxXPosition; x <= maxXPosition; x += dx)
    {
        const Vector currentPosition = Vector(x, f(x) + 20);

        setPosition(currentPosition);
    }
};

void loop(){};