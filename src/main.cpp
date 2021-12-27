#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const Bezier paths[] = {
    Bezier(new Vector[4]{Vector(-10, 0), Vector(30, 20), Vector(-30, 20), Vector(10, 0)}),
    Bezier(new Vector[4]{Vector(10, 0), Vector(30, 20), Vector(-30, 20), Vector(-10, 0)}),
};

constexpr int buttonPin = 2;

constexpr float dt = 0.001;

const Vector drawingOffset = Vector(0, 10);

void setup()
{
    // Reset
    attachServos();
    pinMode(buttonPin, INPUT_PULLUP);

    setPosition(paths[0](0) + drawingOffset);
    delay(1000);
    while (digitalRead(buttonPin))
    {
        // Wating for button
    };

    // Trace Bezier paths by evaluating in small steps and sending angles to servos
    for (const Bezier path : paths)
    {
        const Bezier pathDerivative = path.derivative();

        for (float t = 0; t <= 1; t += dt)
        {
            const Vector currentWantedPosition = path(t) + drawingOffset;

            setPosition(currentWantedPosition);
        }
    }
};

void loop(){};