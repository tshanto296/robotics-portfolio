# Robotic Arm Controller

## What it does
A 3-DOF robotic arm controlled over UART from a laptop serial monitor.
Send single character commands to move the base, shoulder, and elbow
joints independently. Directly inspired by robotic arm work at Purdue
MARS Lab.

## Concepts demonstrated
- Servo motor control for multi-joint robotic arm
- UART serial communication for real-time command input
- Joint angle tracking with software position limits
- Clamp function to prevent mechanical overextension
- State machine style command parsing

## How it works
- Arduino listens for single character commands over UART
- Each command moves a specific joint by 10 degrees
- Position is clamped between 0-180° to protect servos
- Current joint positions printed after every command
- 'h' command returns all joints to home position (90°)

## Commands
| Key | Action |
|-----|--------|
| a | Base rotate left |
| d | Base rotate right |
| w | Shoulder up |
| s | Shoulder down |
| q | Elbow up |
| e | Elbow down |
| h | Home position |

## Hardware
- Arduino Uno
- 3x Servo motors (base, shoulder, elbow)

## Wiring
| Component | Pin | Arduino Pin |
|-----------|-----|-------------|
| Base servo | Signal | Pin 9 |
| Shoulder servo | Signal | Pin 10 |
| Elbow servo | Signal | Pin 11 |
| All servos | VCC | 5V |
| All servos | GND | GND |

## How to run
1. Wire circuit as shown
2. Upload code to Arduino
3. Open serial monitor at 9600 baud
4. Type commands to control each joint
5. Type 'h' to return to home position
