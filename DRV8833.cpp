/*================================================================================
 * 
 * DRV8833 Motor Driver - Arduino Library
 * 
 * Author: Thomas Hulme
 * Web: thomashulme.co.uk
 * 
 ================================================================================*/
 
#include "Arduino.h"
#include "DRV8833.h"

/*========================================
 * 
 * DC Motor
 * 
 ========================================*/

DRV8833_DCMotor::DRV8833_DCMotor(int in1_pin, int in2_pin){
    // Do all this on initialization

    // Set pins as private variables to disable changing them during runtime.
    in1_pin_ = in1_pin;
    in2_pin_ = in2_pin;

    // PinMode's
    pinMode(in1_pin_, OUTPUT);
    pinMode(in2_pin_, OUTPUT);

    // Stop motor
    brake();
}

void DRV8833_DCMotor::forward(int speed){
    analogWrite(in1_pin_, speed);
    digitalWrite(in2_pin_, LOW);
}

void DRV8833_DCMotor::backward(int speed){
    analogWrite(in2_pin_, speed);
    digitalWrite(in1_pin_, LOW);
}

void DRV8833_DCMotor::coast(){
    // Can PWM in this setting to adjust deceleration, see datasheet
    digitalWrite(in1_pin_, LOW);
    digitalWrite(in2_pin_, LOW);
}
void DRV8833_DCMotor::coast(int speed){
    // Can PWM in this setting to adjust deceleration, see datasheet
    analogWrite(in1_pin_, speed);
    analogWrite(in2_pin_, speed);
}

void DRV8833_DCMotor::brake(){
    // Can PWM in this setting to adjust deceleration, see datasheet
    digitalWrite(in1_pin_, HIGH);
    digitalWrite(in2_pin_, HIGH);
}
void DRV8833_DCMotor::brake(int speed){
    // Can PWM in this setting to adjust deceleration, see datasheet
    analogWrite(in1_pin_, speed);
    analogWrite(in2_pin_, speed);
}

/*========================================
 * 
 * Stepper Motor
 * 
 ========================================*/

