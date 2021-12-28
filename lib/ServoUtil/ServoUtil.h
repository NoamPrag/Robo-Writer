#include <Arduino.h>
#include <Servo.h>

const int convertAngleToServo(const int &angle, const int &servoMin, const int &servoMax)
{
    return map(angle, 0, 180, servoMin, servoMax);
}

const int convertAngleFromServo(const int &angle, const int &servoMin, const int &servoMax)
{
    return map(angle, servoMin, servoMax, 0, 180);
}

Servo rightServo;
Servo leftServo;

constexpr int rightServoPin = 9;
constexpr int leftServoPin = 10;

const void attachServos()
{
    rightServo.attach(rightServoPin);
    leftServo.attach(leftServoPin);
}

constexpr int rightServoMin = 117;
constexpr int rightServoMax = -2;

constexpr int leftServoMin = 63;
constexpr int leftServoMax = 181;

const void setRightServo(const int &angle)
{
    rightServo.write(convertAngleToServo(angle, rightServoMin, rightServoMax));
}

const void setLeftServo(const int &angle)
{
    leftServo.write(convertAngleToServo(angle, leftServoMin, leftServoMax));
}

const Vector rightServoPosition = Vector(7.25, 0);
const Vector leftServoPosition = Vector(-7.25, 0);

constexpr float elbowDistance = 18;
constexpr float forearmDistance = 24;
constexpr float totalArmLength = elbowDistance + forearmDistance;

const float getAngleInTriangle(const float &near1, const float &near2, const float &opposite)
{
    const float near1Squared = near1 * near1;
    const float near2Squared = near2 * near2;
    const float oppositeSquared = opposite * opposite;

    return acos((near1Squared + near2Squared - oppositeSquared) / (2.0 * near1 * near2));
}

const int getRightServoAngle(const Vector &position)
{
    const Vector servoToPen = position - rightServoPosition;
    const float distanceBetweenServoAndPen = servoToPen.getNorm();

    // Cosine law
    const float angleBetweenArmAndPen = getAngleInTriangle(elbowDistance, distanceBetweenServoAndPen, forearmDistance);
    return degrees(servoToPen.getAngle() - angleBetweenArmAndPen);
};

const int getLeftServoAngle(const Vector &position)
{
    const Vector servoToPen = position - leftServoPosition;
    const float distanceBetweenServoAndPen = servoToPen.getNorm();

    // Cosine law
    const float angleBetweenArmAndPen = getAngleInTriangle(elbowDistance, distanceBetweenServoAndPen, forearmDistance);
    return 180 - degrees(servoToPen.getAngle() + angleBetweenArmAndPen);
};

// * ass triangle = angle-side-side (where the angle is the largest in the triangle)
const float getSideInAssTriangle(const float &largeSide, const float &otherSide, const float &angle)
{
    // * largeSide ^ 2 = side ^ 2 + otherSide ^ 2 - 2*side*otherSide*cos(angle)
    const float angleInRadians = radians(angle);
    return otherSide * cos(angleInRadians) + sqrt(pow(largeSide, 2) - pow(otherSide * sin(angleInRadians), 2));
}

// * Returns the max distance from the origin available for a given direction.
const float getMaxDistance(const int &angle)
{
    const float originToServoDistance = angle > 90 ? rightServoPosition.getNorm() : leftServoPosition.getNorm();
    return getSideInAssTriangle(totalArmLength, originToServoDistance, angle);
}

// * Returns true if the mechanism is physically capable of reaching the given position.
const bool positionValid(const Vector &position)
{
    return (position - rightServoPosition).getNorm() <= totalArmLength && (position - leftServoPosition).getNorm() <= totalArmLength;
}

const void setPosition(const Vector &position)
{
    const float rightServoAngle = getRightServoAngle(position);
    const float leftServoAngle = getLeftServoAngle(position);

    setRightServo(rightServoAngle);
    setLeftServo(leftServoAngle);
}