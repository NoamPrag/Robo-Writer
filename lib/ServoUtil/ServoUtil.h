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

const int rightServoMin = 112;
const int rightServoMax = 5;

const int leftServoMin = 72;
const int leftServoMax = 177;

const int getRightServoAngle()
{
    return convertAngleFromServo(rightServo.read(), rightServoMin, rightServoMax);
}

const int getLeftServoAngle()
{
    return convertAngleFromServo(leftServo.read(), leftServoMin, leftServoMax);
}

const void setRightServo(const int &angle)
{
    rightServo.write(convertAngleToServo(angle, rightServoMin, rightServoMax));
}

const void setLeftServo(const int &angle)
{
    leftServo.write(convertAngleToServo(angle, leftServoMin, leftServoMax));
}
