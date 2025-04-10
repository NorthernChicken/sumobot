// Built from Motor Test Code for Single L298N Driver (Motor A Only) by Prahas D: https://github.com/Raptorly1

#include <Servo.h>

// Motor A and B (Left and Right)
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

// Enable Pin for Motor A and B
const int ENA = 9;
const int ENB = 8;

void setup()
{
    // Initialize serial communication first
    Serial.begin(9600);

    // Initialize motor control pins for Motor A and B
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorBackward, OUTPUT);
    pinMode(RightMotorForward, OUTPUT);
    pinMode(RightMotorBackward, OUTPUT);

    // Enable Motor A
    pinMode(ENA, OUTPUT);
    digitalWrite(ENA, HIGH);

    // Enable Motor B
    pinMode(ENB, OUTPUT);
    digitalWrite(ENB, HIGH);

    // Begin Sequence
    delay(5000);
    TurnRight(200);
    MoveBackward(100);
    TurnLeft(400);
    MoveBackward(1000);
    while (true)
    {
      TurnRight(1000);
      delay(500);
      TurnLeft(1000);
      delay(500);
      MoveBackward(100);
      delay(100);
    }

}

void MoveForward(int duration)
{
    // Move both motors forward
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    // Wait for the specified duration
    delay(duration);

    // Stop both motors
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, LOW);
}

void MoveBackward(int duration)
{
    // Move both motors backward
    analogWrite(LeftMotorBackward, 255);
    analogWrite(RightMotorBackward, 255);

    // Wait for the specified duration
    delay(duration);

    // Stop both motors
    analogWrite(LeftMotorBackward, 0);
    analogWrite(RightMotorBackward, 0);
}

void TurnLeft(int duration)
{
    // Move right motor forward
    digitalWrite(RightMotorBackward, HIGH);

    // Wait for the specified duration
    delay(duration);

    // Stop motor
    digitalWrite(RightMotorBackward, LOW);
}

void TurnRight(int duration)
{
    // Move left motor forward
    digitalWrite(LeftMotorBackward, HIGH);

    // Wait for the specified duration
    delay(duration);

    // Stop motor
    digitalWrite(LeftMotorBackward, LOW);
}