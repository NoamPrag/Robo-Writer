#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>
// #include <Duck.h>
#include <Drawing.h>
#include <Mustache.h>

constexpr int buttonPin = 2;

constexpr float dt = 0.1;

void goToFirstPos(const Drawing &drawing)
{
    // const Vector firstPosition = drawing.curves[0](0) * drawing.scaleFactor + drawing.offset;
    setPosition(drawing.curves[0](0) * drawing.scaleFactor + drawing.offset);
}

void waitForButton()
{
    while (digitalRead(buttonPin))
    {
    };
}

// void draw(const Drawing &drawing)
// {
//     // Trace Bezier paths by evaluating in small steps and sending angles to servos
//     for (int i = 0; i < drawing.numberOfCurves; i++)
//     {
//         const Bezier path = drawing.curves[i];
//         for (float t = 0; t <= 1; t += dt)
//         {
//             const Vector currentWantedPosition = path(t) * drawing.scaleFactor + drawing.offset;

//             setPosition(currentWantedPosition);
//             Serial.println("Hamachzik shel hamelech!");
//         }
//     }
// }

void setup()
{
    Serial.begin(9600);
    attachServos();
    pinMode(buttonPin, INPUT_PULLUP);

    const Drawing drawing = mustacheDrawing;

    goToFirstPos(drawing);
    delay(1000);
    waitForButton();
    // draw(drawing);

    Serial.println("Button pressed");

    Serial.println(drawing.numberOfCurves);

    // Trace Bezier paths by evaluating in small steps and sending angles to servos
    for (int i = 0; i < drawing.numberOfCurves; i++)
    {
        Serial.println(i);
        const Bezier path = drawing.curves[i];
        for (float t = 0; t <= 1; t += dt)
        {
            const Vector currentWantedPosition = path(t) * drawing.scaleFactor + drawing.offset;

            Serial.print("t: ");
            Serial.print(t);
            Serial.print(" x: ");
            Serial.print(currentWantedPosition.x);
            Serial.print(" y: ");
            Serial.println(currentWantedPosition.y);

            if (isnan(currentWantedPosition.x) || isnan(currentWantedPosition.y))
            {
                continue;
            }

            setPosition(currentWantedPosition);
        }
    }
};

void loop(){};