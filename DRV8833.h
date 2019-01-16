/*================================================================================
 * 
 * DRV8833 Motor Driver - Arduino Library
 * 
 * Author: Thomas Hulme
 * Web: thomashulme.co.uk
 * 
 ================================================================================*/

#ifndef DRV8833
#define DRV8833

#include "Arduino.h"

// Uncomment the next line to enable serial debug.
// #define DEBUG

#define FORWARD 1
#define BACKWARD 2
#define COAST 3
#define BRAKE 4

/*========================================
 * 
 * Default Values (Can be changed via functions)
 * 
 ========================================*/
int max_pwm = 65535;

/*========================================
 * 
 * DC Motor
 * 
 ========================================*/
class DRV8833_DCMotor{
    public:
        DRV8833_DCMotor(int in1_pin, int in2_pin);
        void max_pwm(max_pwm);
        void run(int command, int motor_pwm);
    private:
        int in1_pin_;
        int in2_pin_;
        int max_pwm_;
        int motor_pwm_;
};

 /*========================================
 * 
 * Stepper Motor
 * 
 ========================================*/


#endif