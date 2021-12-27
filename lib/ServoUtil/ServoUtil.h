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

const int rightServoPin = 9;
const int leftServoPin = 10;

const void attachServos()
{
    rightServo.attach(rightServoPin);
    leftServo.attach(leftServoPin);
}

const int rightServoMin = 117;
const int rightServoMax = -2;

const int leftServoMin = 63;
const int leftServoMax = 181;

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

const float elbowDistance = 18;
const float forearmDistance = 24;

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

const void setPosition(const Vector &position)
{
    setRightServo(getRightServoAngle(position));
    setLeftServo(getLeftServoAngle(position));
}