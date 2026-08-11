#include <Servo.h>

// Ultrasonic sensor pins
const int TRIG = 7;
const int ECHO = 8;

// Motor driver pins
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 3;
const int ENA = 9;
const int ENB = 10;

// Servo
const int SERVO_PIN = 11;
Servo RADAR;

const int BASE_SPEED = 150;
const int SAFE_DISTANCE = 20;  // cm

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  RADAR.attach(SERVO_PIN);
  RADAR.write(90);  // center position
  delay(500);

  Serial.println("Obstacle Avoidance Robot Ready");
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long DURATION = pulseIn(ECHO, HIGH);
  long DISTANCE = DURATION * 0.034 / 2;
  return DISTANCE;
}

void moveForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
  Serial.println("[FORWARD]");
}

void moveBackward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
  Serial.println("[BACKWARD]");
}

void turnLeft() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
  Serial.println("[LEFT]");
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
  Serial.println("[RIGHT]");
}

void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  Serial.println("[STOP]");
}

int scanDirection(int angle) {
  RADAR.write(angle);
  delay(300);
  return getDistance();
}

void loop() {
  long DIST = getDistance();
  Serial.print("Distance: ");
  Serial.print(DIST);
  Serial.println(" cm");

  if (DIST > SAFE_DISTANCE) {
    moveForward();
  } else {
    stopMotors();
    delay(300);
    moveBackward();
    delay(400);
    stopMotors();

    // Scan left and right to find clear path
    int LEFT_DIST  = scanDirection(150);
    int RIGHT_DIST = scanDirection(30);

    // Return servo to center
    RADAR.write(90);
    delay(300);

    if (LEFT_DIST > RIGHT_DIST) {
      turnLeft();
      Serial.println("[AVOIDING] Turning left");
    } else {
      turnRight();
      Serial.println("[AVOIDING] Turning right");
    }
    delay(400);
    stopMotors();
  }

  delay(100);
}
