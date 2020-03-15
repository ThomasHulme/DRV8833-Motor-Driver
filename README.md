# DRV8833 Motor Driver

Arduino library to drive an DRV8833 IC.

## Library features
* Control forward and backward movements
* PWM speed control in both directions
* Custom brake and coast deceleration rates

## DRV8833 features
[Datasheet](https://www.ti.com/lit/ds/symlink/drv8833.pdf)
* Drive two DC motors or one stepper motor
* 1.5A per H-Bridge (2A peak)
* 2.7V - 10.8V Input voltage

## Dependencies
* Arduino

## How to install
[Install library from .ZIP](https://www.arduino.cc/en/guide/libraries#toc4)

## Example
```cpp
#include <Arduino.h>
#include "DRV8833.h"

const int motorA_in1 = 10;
const int motorA_in2 = 11;

DRV8833_DCMotor motorA(motorA_in1, motorA_in2);

int motor_speed = 255;

void setup() {

  // Stop the motor
  motorA.brake();
  
}

void loop() {

  motorA.forward(motor_speed);
  delay(3000);
  motorA.backward(motor_speed);
  delay(3000);
  motorA.coast();
  delay(5000);

}
```