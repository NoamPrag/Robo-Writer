#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>
#include <Duck.h>

// const Bezier paths[] = {
//     Bezier(new Vector[4]{Vector(-10, 0), Vector(30, 20), Vector(-30, 20), Vector(10, 0)}),
//     Bezier(new Vector[4]{Vector(10, 0), Vector(30, 20), Vector(-30, 20), Vector(-10, 0)}),
// };

constexpr int buttonPin = 2;

constexpr float dt = 0.005;

const Vector drawingOffset = Vector(10, 25);
const float drawingScaleFactor = 0.004;

void setup()
{
    // Reset
    attachServos();
    pinMode(buttonPin, INPUT_PULLUP);

    setPosition(duckDrawing[0](0) * drawingScaleFactor + drawingOffset);
    delay(1000);
    while (digitalRead(buttonPin))
    {
        // Wating for button
    };

    // Trace Bezier paths by evaluating in small steps and sending angles to servos
    for (const Bezier path : duckDrawing)
    {
        for (float t = 0; t <= 1; t += dt)
        {
            const Vector currentWantedPosition = path(t) * drawingScaleFactor + drawingOffset;

            setPosition(currentWantedPosition);
        }
    }
};

void loop(){};