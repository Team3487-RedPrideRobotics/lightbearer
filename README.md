<h1 align="center"> lightbearer</h1>
<p align="center">LED Controller for FRC robots, powered by Arduino</p>

## Table of Contents
* What Is This?
* Getting Started?
* Usage
* Pattern Table
* Contributing

## What Is This?
Lightbearer is an LED control system that runs primarily on an Arduino. In its current state, LED patterns and colors are defined in the Arduino's source code. The RIO can then change between these modes by sending a byte corresponding to the pattern over the USB port.

Currently, Lightbearer includes an idle pattern (slow rainbow), full red, full blue, full purple, full yellow, and celebration pattern (fast rainbow).

## Getting Started
First, wire your LED strip to power, ground, and a data pin on the arduino. The, open the "1_Lightbearer.ino" file in the arduino IDE and change ```RGB_PIN```, ```RGB_LED_NUM```, ```BRIGHTNESS```, ```CHIP_SET```, and ```COLOR_CODE``` to match your setup. After this, plug the Arduino into a USB port on the rio. 

## Usage
An example for rio code control is included in this repository as a subsystem that should be plug-and-play with most command-based Java code bases. Essentially, the rio's code should set up a serial connection over the USB the arduino is connected on with a baud of 9600. Then, when the rio needs to change the LED pattern, it should write a byte array to the serial port corresponding to the pattern desired by the user

## Pattern Table
This is also defined in a region of the example rio subsystem
| **Byte** | **Pattern** |
|----------|-------------|
| 0x49     | Idle        |
| 0x52     | Red         |
| 0x42     | Blue        |
| 0x59     | Yellow      |
| 0x50     | Purple      |
| 0x43     | Celebration |
| 0x53     | Clear       |

## Contributing
The main things that still need to be worked on are more patterns, the ability to control parameters such as pattern color through the rio, and a better control loop on the arduino. All are free to contribute changes to the code
