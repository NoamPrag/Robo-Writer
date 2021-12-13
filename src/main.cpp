#include <Arduino.h>
#include <Bezier.h>
#include <Vector.h>
#include <ServoUtil.h>

const Bezier paths[] = {Bezier(Vector(10, 25), Vector(10, -20), Vector(-10, 60), Vector(-10, 25))};
const float dt = 0.005;

void setup()
{
    Serial.begin(9600);
    // Reset
    attachServos();

    // Trace Bezier paths by evaluating in small steps and sending angles to servos
    for (const Bezier path : paths)
    {
        for (float t = 0; t <= 1; t += dt)
        {
            const Vector currentWantedPosition = path.evaluate(t);
            const float rightServoWantedAngle = getRightServoAngle(currentWantedPosition);
            const float leftServoWantedAngle = getLeftServoAngle(currentWantedPosition);

            rightServo.write(rightServoWantedAngle);
            leftServo.write(leftServoWantedAngle);
            Serial.print(currentWantedPosition.x);
            Serial.print(",\t");
            Serial.println(currentWantedPosition.y);

            delay(20);
        }
    }
};

void loop(){};