/*================================================================================
 * 
 * DRV8833 Motor Driver - Arduino Library
 * 
 * Author: Thomas Hulme
 * Web: thomashulme.co.uk
 * 
 * TODO:
 * Add acceleration rate
 * 
 ================================================================================*/

#ifndef DRV8833
#define DRV8833

#include "Arduino.h"

#define FORWARD 1
#define BACKWARD 2
#define COAST 3
#define BRAKE 4

/*========================================
 * 
 * DC Motor
 * 
 ========================================*/

class DRV8833_DCMotor {
    public:         // Can be used outside of these classes
        DRV8833_DCMotor(int in1_pin, int in2_pin);
        void run(int command, int motor_pwm);
        int max_pwm = 255;          // Default to Arduino Uno
    private:            // Not accessable by anyone else
        int in1_pin_;
        int in2_pin_;
        int motor_pwm_;
};

 /*========================================
 * 
 * Stepper Motor
 * 
 ========================================*/


#endif