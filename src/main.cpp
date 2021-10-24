#include <Arduino.h>
#include <Servo.h>
#include <Vector.h>
#include <Bezier.h>

const int rightServoPin = 9;
const int leftServoPin = 10;

const Vector rightServoPosition = Vector(0, 0);
const Vector leftServoPosition = Vector(0, 0);

const float elbowDistance = 0;
const float forearmDistance = 0;

Servo right;
Servo left;

const Vector getPosition(const int &rightAngle, const int &leftAngle)
{
    const Vector rightElbowPosition = Vector::unit(rightAngle) * elbowDistance + rightServoPosition;
    const Vector leftElbowPosition = Vector::unit(leftAngle) * elbowDistance + leftServoPosition;

    const Vector medianOfTwoElbows = (rightElbowPosition + leftElbowPosition) / 2;

    // This is equivalent to the distance between the left elbow and the median as well
    const float distanceFromElbowToMedian = (rightElbowPosition - medianOfTwoElbows).getNorm();

    // Inverse pythagoras
    const float medianToFinalPositionDistance =
        sqrtf(abs(forearmDistance * forearmDistance - distanceFromElbowToMedian * distanceFromElbowToMedian));

    const float angleOfLineBetweenElbows = (rightElbowPosition - leftElbowPosition).getAngle();

    // The median is perpendicular to the line between elbows, due to the formed isosceles triangle
    const Vector medianToFinalPosition = Vector::unit(angleOfLineBetweenElbows + HALF_PI) * medianToFinalPositionDistance;

    return medianOfTwoElbows + medianToFinalPosition;
};

// Returns an array with two elements - right is first
const int getServoAngle(const Vector &position, const Vector &servoPosition)
{
    const Vector servoToPen = position - servoPosition;
    const float distanceBetweenServoAndPen = servoToPen.getNorm();
    // Cosine law
    const float angleBetweenArmAndPenPosition = acos(distanceBetweenServoAndPen * distanceBetweenServoAndPen + elbowDistance * elbowDistance - forearmDistance * forearmDistance / 2 * distanceBetweenServoAndPen * elbowDistance);
    return servoToPen.getAngle() + angleBetweenArmAndPenPosition;
};

void setup()
{
    right.attach(rightServoPin);
    left.attach(leftServoPin);
};

void loop(){};