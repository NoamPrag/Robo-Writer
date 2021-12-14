#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const Bezier paths[] = {
    Bezier(new Vector[4]{Vector(10, 25), Vector(10, -20), Vector(-10, 60), Vector(-10, 25)}),
    Bezier(new Vector[4]{Vector(-10, 25), Vector(-10, 60), Vector(10, -20), Vector(10, 25)}),
};

const float dx = 0.04; // cm

void setup()
{
    // Reset
    attachServos();

    // Trace Bezier paths by evaluating in small steps and sending angles to servos
    for (const Bezier path : paths)
    {
        const Bezier pathDerivative = path.derivative();

        float dt;

        for (float t = 0; t <= 1; t += dt)
        {
            const Vector currentWantedPosition = path(t);

            const float rightServoWantedAngle = getRightServoAngle(currentWantedPosition);
            const float leftServoWantedAngle = getLeftServoAngle(currentWantedPosition);

            setRightServo(rightServoWantedAngle);
            setLeftServo(leftServoWantedAngle);

            dt = dx / pathDerivative(t).getNorm();
        }
    }
};

void loop(){};