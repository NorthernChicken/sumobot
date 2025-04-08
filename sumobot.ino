// Built from Motor Test Code for Single L298N Driver (Motor A Only) by Prahas D: https://github.com/Raptorly1

#include <Servo.h>   //Servo motor library. This is standard library
#include <NewPing.h> //Ultrasonic sensor function library. You must install this library

// Motor A (Left and Right)
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

    // Initialize motor control pins for Motor A
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

    Serial.println("Starting motor test...");
}

void loop()
{
    MoveBackward(1000);
    delay(400);
    TurnLeft(1000);
    delay(400);
    TurnRight(1000);
    delay(400);
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
    // Move both motors forward
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);

    // Wait for the specified duration
    delay(duration);

    // Stop both motors
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}

void TurnLeft(int duration)
{
    // Move right motor forward
    digitalWrite(RightMotorForward, HIGH);

    // Wait for the specified duration
    delay(duration);

    // Stop motor
    digitalWrite(RightMotorForward, LOW);
}

void TurnRight(int duration)
{
    // Move right motor forward
    digitalWrite(LeftMotorForward, HIGH);

    // Wait for the specified duration
    delay(duration);

    // Stop motor
    digitalWrite(LeftMotorForward, LOW);
}