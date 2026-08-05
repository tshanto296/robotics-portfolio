# Line Follower Robot

## What it does
An Arduino-based line follower robot that uses two IR sensors to detect
a line and controls two DC motors via an L298N motor driver to follow it.
Implements basic directional logic with PWM speed control.

## Concepts demonstrated
- IR sensor interfacing for line detection
- L298N motor driver control
- PWM speed control with analogWrite
- Directional logic (forward, left, right, stop)
- Real-time sensor based decision making

## How it works
- Left and right IR sensors detect the line (LOW = line detected)
- Both detect line → move forward
- Only right detects line → turn right
- Only left detects line → turn left
- Neither detects line → stop

## Hardware
- Arduino Uno
- 2x IR sensors
- L298N motor driver
- 2x DC motors

## Wiring
| Component | Pin | Arduino Pin |
|-----------|-----|-------------|
| Left IR | OUT | Pin 2 |
| Right IR | OUT | Pin 3 |
| IR sensors | VCC | 5V |
| IR sensors | GND | GND |
| L298N | IN1 | Pin 4 |
| L298N | IN2 | Pin 5 |
| L298N | IN3 | Pin 6 |
| L298N | IN4 | Pin 7 |
| L298N | ENA | Pin 9 (PWM) |
| L298N | ENB | Pin 10 (PWM) |
| Left motor | — | OUT1 & OUT2 |
| Right motor | — | OUT3 & OUT4 |

## How to run
1. Wire circuit as shown
2. Upload code to Arduino
3. Open serial monitor at 9600 baud
4. Place robot on a track with a dark line on light surface
5. Robot follows the line automatically
