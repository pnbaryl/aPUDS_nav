#include "bindings.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <ctime>
#include <time.h>
#include <thread>
#include <cmath>

int main() {

  struct utsname uts;
  uname(&uts);
  printf("Navigator C test, system details:\n");
  printf("System is %s on %s hardware\n", uts.sysname, uts.machine);
  printf("OS Release is %s\n", uts.release);
  printf("OS Version is %s\n", uts.version);

  const char *ci_env = std::getenv("CI");
  if (ci_env && std::string(ci_env) == "true") {
    printf("Running from CI\n");
    printf("Not possible to test navigator sensors yet.\n");

    return 0;
  }

  // Initialize Variables
  double curr_heading = 0;     // In Radians
  double curr_heading_deg = 0; // In Degrees
  double target_heading = 10;
  double error = 0; 	       // Distance between current heading and target heading

  // Initialize Navigator Board
  init();

  // Set LED on
  set_led(UserLed::Led1, true);

  for(int i = 0; i < 10; i++){
  ADCData adc = read_adc_all();
  // printf(" %f, %f, %f, %f, ", adc.channel[0], adc.channel[1], adc.channel[2], adc.channel[3]);
  // printf("%f, ", read_adc(AdcChannel::Ch1));

  AxisData mag = read_mag();
  //  printf("%f, %f, %f, ", mag.x, mag.y, mag.z);

  AxisData accel = read_accel();
  // printf("%f, %f, %f ", accel.x, accel.y, accel.z);

  AxisData gyro = read_gyro();
  //  printf("%f, %f, %f \n", gyro.x, gyro.y, gyro.z);
  
//..............................FUNCTION: get_heading.....................................
// Read Magnetometer, transform X, Y, and Z vectors into a heading of 0 to +/- 180 degrees.
// 0 = North, 90 = East, -90 = West +/-180 = South
// Note: calculations must be done here, weird dependency issues with Makefile, unable to call functions
// outside of bindings.h, will break apart code once I can figure out how Makefile can be modified

	//Calculate roll and pitch components from accelerometer
	float roll = atan2(accel.y, accel.z);
	float pitch = atan2(-(accel.x), sqrt( (pow((accel.y),2) + (pow((accel.z),2)))));

	// Calculate tilt compensation in X and Y direction
	float Xh = (mag.x * cos(pitch) + sin(roll) * sin(pitch) + mag.z * cos(roll) * sin(pitch));
	float Yh = (mag.y * cos(roll) - mag.z * sin(roll));

	// Calculate current heading in degrees and radians
		// Note: North to South clockwise is 0-180 degrees
		// South to North clockwise is -180 to 0 degrees
	curr_heading = atan2(Yh, Xh);
	curr_heading_deg = curr_heading * (180 / 3.14159);
	

//.............................FUNCTION: get_error...........................................
// Calculates direction and degrees of rotation to target heading
// Positive error means move CW, Neg error means CCW
	
	// Set desired target heading
	if(target_heading > 180){
		target_heading = -180 + (abs(180 - target_heading));
	}

	float error = 0;
	// Calculate error, or distance in degrees. Positive error means move CW, Neg error means CCW
	  if(curr_heading_deg > 0 && target_heading > 0){
		  	error = target_heading - curr_heading_deg;
	  }
	  else if(curr_heading_deg < 0 && target_heading < 0){
		  	error = target_heading - curr_heading_deg;
	  }
	  else if(curr_heading_deg >= 0 && target_heading <= 0){
			 error = (curr_heading_deg - target_heading);
		  		if(error > 180){
				       error = error - 360;
				}	       
	  }
	  else if(curr_heading_deg <= 0 && target_heading >= 0){
		  	error = target_heading - curr_heading_deg;
		  		if(error > 180){
					error = error - 360;
				}
	  }
	else{
	       	error = 0;
	}

  	printf("Target Heading = %f,  Current Heading (Deg) = %f, Error (deg) = %f\n", target_heading , curr_heading_deg, error);

/////////////////////////////////////////////// PID LOOP ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////Place into separate funtion and header file////////////////////////////////

// PID coefficients
const double Kp = 1.0;
const double Ki = 1.0;
const double Kd = 1.0;
const double pi = 3.14159;

// PID control variables
double err_prev = 0.0;
double integral = 0.0;
const double sample_time = 0.1;

// Error Calculation
	integral += error * sample_time;
	double derivative = (error - err_prev) / sample_time;
	double output = Kp * error + Ki * integral + Kd * derivative;
	err_prev = error;

	//printf("Output to Thrusters: %f, Derivative: %f, Integral: %f\n\n", output, derivative, integral);
      
	
	
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

}

  //printf("Setting led off!\n");
  set_led(UserLed::Led1, false);

  return 0;
}





