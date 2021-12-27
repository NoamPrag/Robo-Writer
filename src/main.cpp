#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const float dt = 0.05;

void setup()
{
    // Reset
    attachServos();
};

const Vector circleCenter = Vector(0, 20);
const float circleRadius = 5;

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