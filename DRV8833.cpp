
#include "Arduino.h"
#include "DRV8833.h"

DRV8833_DCMotor::DRV8833_DCMotor(int in1_pin, int in2_pin){
    // Do all this on initialization

    // Set pins as private variables to disable changing them during runtime.
    in1_pin_ = in1_pin;
    in2_pin_ = in2_pin;

    // PinMode's
    pinMode(in1_pin_, OUTPUT);
    pinMode(in2_pin_, OUTPUT);

    // Stop motor
    run(BRAKE, 0);
}

void DRV8833_DCMotor::run(int command, int motor_pwm){

    motor_pwm_ = motor_pwm;

    // If PWM value is higher than the max allowable PWM setting (255 for Uno) then set it as the highest.
    if(motor_pwm > max_pwm){
        motor_pwm = max_pwm;
    }

    switch (command) {
        case FORWARD:
            analogWrite(in1_pin_, motor_pwm_);
            digitalWrite(in2_pin_, LOW);
            break;
        case BACKWARD:
            analogWrite(in2_pin_, motor_pwm_);
            digitalWrite(in1_pin_, LOW);
            break;
        case COAST:
            // Can PWM in this setting to adjust deceleration, see datasheet
            digitalWrite(in1_pin_, LOW);
            digitalWrite(in2_pin_, LOW);
            break;
        case BRAKE:
            // Can PWM in this setting to adjust deceleration, see datasheet
            digitalWrite(in1_pin_, HIGH);
            digitalWrite(in2_pin_, HIGH);
            break;
        default:
            // If command does match any of above then stop the motor.
            run(BRAKE, 0);
            break;
    }
}
