# Obstacle Avoidance Robot

## What it does
An Arduino-based obstacle avoidance robot that uses an HC-SR04
ultrasonic sensor mounted on a servo to detect obstacles and
autonomously navigate around them by scanning left and right
to find the clearest path.

## Concepts demonstrated
- Ultrasonic sensor distance measurement (HC-SR04)
- Servo motor control for sensor scanning
- L298N motor driver with PWM speed control
- Autonomous decision making based on sensor data
- Multi-directional scanning for path planning

## How it works
- Ultrasonic sensor continuously measures distance ahead
- If distance > 20cm → move forward
- If obstacle detected → stop, reverse, scan left and right
- Compare left and right distances
- Turn toward the clearer side and continue

## Hardware
- Arduino Uno
- HC-SR04 ultrasonic sensor
- Servo motor (for sensor rotation)
- L298N motor driver
- 2x DC motors

## Wiring
| Component | Pin | Arduino Pin |
|-----------|-----|-------------|
| HC-SR04 | TRIG | Pin 7 |
| HC-SR04 | ECHO | Pin 8 |
| HC-SR04 | VCC | 5V |
| HC-SR04 | GND | GND |
| Servo | Signal | Pin 11 |
| Servo | VCC | 5V |
| Servo | GND | GND |
| L298N | IN1 | Pin 4 |
| L298N | IN2 | Pin 5 |
| L298N | IN3 | Pin 6 |
| L298N | IN4 | Pin 3 |
| L298N | ENA | Pin 9 (PWM) |
| L298N | ENB | Pin 10 (PWM) |
| Left motor | — | OUT1 & OUT2 |
| Right motor | — | OUT3 & OUT4 |

## How to run
1. Wire circuit as shown
2. Upload code to Arduino
3. Open serial monitor at 9600 baud
4. Place obstacles in front of robot
5. Robot detects and navigates around them autonomously
