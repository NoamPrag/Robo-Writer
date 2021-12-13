#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const Bezier paths[] = {};
const float dt = 0.05;

const Vector positions[] = {Vector(10, 20), Vector(10, 30), Vector(-10, 30), Vector(-10, 20), Vector(10, 20)};

void setup()
{
    // Reset
    attachServos();

    // Trace Bezier paths by evaluating in small steps and sending angles to servos
    // for (const Bezier path : paths)
    // {
    //     for (float t = 0; t <= 1; t += dt)
    //     {
    //         const Vector currentWantedPosition = path.evaluate(t);
    //         const float rightServoWantedAngle = getServoAngle(currentWantedPosition, rightServoPosition);
    //         const float leftServoWantedAngle = getServoAngle(currentWantedPosition, leftServoPosition);

    //         rightServo.write(rightServoWantedAngle);
    //         leftServo.write(leftServoWantedAngle);
    //     }
    // }
};

const Vector circleCenter = Vector(15, 15);
const float circleRadius = 8;

void loop()
{
    for (float angle = 0; angle < TWO_PI; angle += 0.005)
    {
        const Vector position = Vector::unit(angle) * circleRadius + circleCenter;

        const float rightAngle = getRightServoAngle(position);
        const float leftAngle = getLeftServoAngle(position);

        setRightServo(rightAngle);
        setLeftServo(leftAngle);
    }
};