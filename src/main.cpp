#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const Vector rightServoPosition = Vector(7.25, 0);
const Vector leftServoPosition = Vector(-7.25, 0);

const float elbowDistance = 18;
const float forearmDistance = 24;

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
    Serial.println(distanceBetweenServoAndPen * distanceBetweenServoAndPen + elbowDistance * elbowDistance - forearmDistance * forearmDistance / (2 * distanceBetweenServoAndPen * elbowDistance));
    return servoToPen.getAngle() + angleBetweenArmAndPenPosition;
};

const Bezier paths[] = {};
const float dt = 0.05;

void setup()
{
    Serial.begin(9600);

    // Reset
    // attachServos();

    const Vector position = Vector(0, 24);

    const float rightAngle = getServoAngle(position, rightServoPosition);
    // const float leftAngle = getServoAngle(position, leftServoPosition);

    // Serial.println(rightAngle);
    // Serial.println(leftAngle);

    // setRightServo(rightAngle);
    // setLeftServo(leftAngle);

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

void loop(){};