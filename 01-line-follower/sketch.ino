const int LEFT_IR = 2;
const int RIGHT_IR = 3;

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
const int ENA = 9;
const int ENB = 10;

const int BASE_SPEED = 150;
const int TURN_SPEED = 100;

void setup() {
  Serial.begin(9600);
  
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  Serial.println("Line Follower Ready");
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, BASE_SPEED);
  Serial.println("[FORWARD]");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, BASE_SPEED);
  Serial.println("[LEFT]");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, TURN_SPEED);
  Serial.println("[RIGHT]");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("[STOP]");
}

void loop() {
  int LEFT_VAL = digitalRead(LEFT_IR);
  int RIGHT_VAL = digitalRead(RIGHT_IR);

  // IR sensors return LOW when detecting line (dark surface)
  if (LEFT_VAL == LOW && RIGHT_VAL == LOW) {
    moveForward();
  } else if (LEFT_VAL == HIGH && RIGHT_VAL == LOW) {
    turnRight();
  } else if (LEFT_VAL == LOW && RIGHT_VAL == HIGH) {
    turnLeft();
  } else {
    stopMotors();
  }
  
  delay(10);
}
