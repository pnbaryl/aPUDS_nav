#ifndef PID_H
#define PID_H


// PID coefficients
const double Kp = 1.0;
const double Ki = 0.0;
const double Kd = 0.0;
const double pi = 3.14159;

// PID control variables
double err_prev = 0.0;
double integral = 0.0;
const double sample_time = 0.1;

int get_error(int curr, int tar);

//double get_heading(const AxisData& mag);
//double get_heading(float Mx, float My, float Mz);

// Gets error on Z axis (yaw)
// Inputs: Target Heading (input by user) and current heading
// Purpose: Calculates error to send to PID control loop. Error indicates degrees apuds needs to turn and which direction
// 	+ error = CW  | - error = CCW
// Output: Calls pid_control_loop
//////////////////double get_error(double target_heading, double curr_heading_deg);


// PID control loop
// Input: error indicates distance and direction aPUDS needs to spin on yaw axis
// Purpose: Determines thruster output (PWM signal) and direction (FWD or RV)
// Output: Calls adjust_thrusters
// void pid_control_loop(double error);

// Send PWM signal to T1:T4 to adjust on yaw axis
// Input: Receives magnitude and direction for each thruster
// Sends PWM output
// void adjust_thrusters (int[] output);

#endif 
