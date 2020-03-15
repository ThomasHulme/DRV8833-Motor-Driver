/*================================================================================
 * 
 * DRV8833 Motor Driver - Arduino Library
 * 
 * Author: Thomas Hulme
 * Web: thomashulme.co.uk
 * 
 ================================================================================*/

#ifndef DRV8833_h
#define DRV8833_h
#pragma once // Include guard (Same as #ifndef)

#define FORWARD     1
#define BACKWARD    2
#define COAST       3
#define BRAKE       4

/*========================================
 * 
 * DC Motor
 * 
 ========================================*/

class DRV8833_DCMotor {

    public:              // Can be used outside of these classes
        DRV8833_DCMotor(int in1_pin, int in2_pin);
        void forward(int speed);
        void backward(int speed);
        void coast();
        void coast(int speed);
        void brake();
        void brake(int speed);
        //void run(int command, int motor_pwm);

    private:            // Not accessable by anyone else
        int in1_pin_;
        int in2_pin_;
        //int motor_pwm_;

};

 /*========================================
 * 
 * Stepper Motor
 * 
 ========================================*/


#endif // DRV8833_h