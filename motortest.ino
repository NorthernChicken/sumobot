// Motor Test Code for Single L298N Driver (Motor A Only)

// Motor A (Left and Right)
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

// Enable Pin for Motor A
const int ENA = 9;

// Enable Pin for Motor B
const int ENB = 8;

void setup() {
  // Initialize serial communication first
  Serial.begin(9600);
  Serial.println("Arduino starting");

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

void loop() {
  Serial.println("Left Motor A Forward");
  digitalWrite(LeftMotorForward, HIGH);
  delay(1000);
  digitalWrite(LeftMotorForward, LOW);
  delay(500);

  Serial.println("Left Motor A Backward");
  digitalWrite(LeftMotorBackward, HIGH);
  delay(1000);
  digitalWrite(LeftMotorBackward, LOW);
  delay(500);

  Serial.println("Right Motor A Forward");
  digitalWrite(RightMotorForward, HIGH);
  delay(1000);
  digitalWrite(RightMotorForward, LOW);
  delay(500);

  Serial.println("Right Motor A Backward");
  digitalWrite(RightMotorBackward, HIGH);
  delay(1000);
  digitalWrite(RightMotorBackward, LOW);
  delay(500);

  Serial.println("Motor test complete. Restarting...");
  delay(2000);
}