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

