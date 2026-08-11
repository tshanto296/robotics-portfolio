#include <Servo.h>

Servo BASE;
Servo SHOULDER;
Servo ELBOW;

const int BASE_PIN     = 9;
const int SHOULDER_PIN = 10;
const int ELBOW_PIN    = 11;

// Current positions
int BASE_POS     = 90;
int SHOULDER_POS = 90;
int ELBOW_POS    = 90;

const int STEP = 10;  // degrees per command

void setup() {
  Serial.begin(9600);

  BASE.attach(BASE_PIN);
  SHOULDER.attach(SHOULDER_PIN);
  ELBOW.attach(ELBOW_PIN);

  // Move to home position
  BASE.write(BASE_POS);
  SHOULDER.write(SHOULDER_POS);
  ELBOW.write(ELBOW_POS);

  Serial.println("Robotic Arm Controller Ready");
  Serial.println("Commands:");
  Serial.println("  a/d — base left/right");
  Serial.println("  w/s — shoulder up/down");
  Serial.println("  q/e — elbow up/down");
  Serial.println("  h   — home position");
}

int clamp(int val, int minVal, int maxVal) {
  if (val < minVal) return minVal;
  if (val > maxVal) return maxVal;
  return val;
}

void printStatus() {
  Serial.print("[ARM] Base: ");
  Serial.print(BASE_POS);
  Serial.print("  Shoulder: ");
  Serial.print(SHOULDER_POS);
  Serial.print("  Elbow: ");
  Serial.println(ELBOW_POS);
}

void loop() {
  if (Serial.available()) {
    char CMD = Serial.read();

    switch (CMD) {
      case 'a':
        BASE_POS = clamp(BASE_POS - STEP, 0, 180);
        BASE.write(BASE_POS);
        Serial.println("[BASE] Left");
        break;

      case 'd':
        BASE_POS = clamp(BASE_POS + STEP, 0, 180);
        BASE.write(BASE_POS);
        Serial.println("[BASE] Right");
        break;

      case 'w':
        SHOULDER_POS = clamp(SHOULDER_POS + STEP, 0, 180);
        SHOULDER.write(SHOULDER_POS);
        Serial.println("[SHOULDER] Up");
        break;

      case 's':
        SHOULDER_POS = clamp(SHOULDER_POS - STEP, 0, 180);
        SHOULDER.write(SHOULDER_POS);
        Serial.println("[SHOULDER] Down");
        break;

      case 'q':
        ELBOW_POS = clamp(ELBOW_POS + STEP, 0, 180);
        ELBOW.write(ELBOW_POS);
        Serial.println("[ELBOW] Up");
        break;

      case 'e':
        ELBOW_POS = clamp(ELBOW_POS - STEP, 0, 180);
        ELBOW.write(ELBOW_POS);
        Serial.println("[ELBOW] Down");
        break;

      case 'h':
        BASE_POS = SHOULDER_POS = ELBOW_POS = 90;
        BASE.write(90);
        SHOULDER.write(90);
        ELBOW.write(90);
        Serial.println("[HOME] All joints reset to 90°");
        break;
    }

    printStatus();
  }
}
