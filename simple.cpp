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
#include <fstream>
#include <iostream>

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

    std::ofstream outFile;

    outFile.open("~/navigator-lib/examples/cpp/SystemData.txt");

    if(!outFile){
	    std::cerr << "error opening file" << std::endl;
	    return 1;
    }
    outFile << "this is a line of text" << std::endl;
    outFile << "this is another line of text" << std::endl;

    outFile.close();

    return 0;
  }

  init();

  set_led(UserLed::Led1, true);
  time_t current_time;
 //	printf("instance, ADC1, ADC2, ADC3, ADC4, DATAadc, magX, magY, magZ, accX, accY, accZ, gyroX, gyroY, gyroZ\n");

  for(int i = 0; i < 10; i++){
  ADCData adc = read_adc_all();
 // printf(" %f, %f, %f, %f, ",
  //       adc.channel[0], adc.channel[1], adc.channel[2], adc.channel[3]);

 // printf("%f, ", read_adc(AdcChannel::Ch1));

  AxisData mag = read_mag();
//  printf("%f, %f, %f, ", mag.x, mag.y, mag.z);

  AxisData accel = read_accel();
 // printf("%f, %f, %f ", accel.x, accel.y, accel.z);

  AxisData gyro = read_gyro();
//  printf("%f, %f, %f \n", gyro.x, gyro.y, gyro.z);
  /////////////////////////////////////////////////// Calculate Current Heading///////////////////////////////////////////
  //////////////////////////////////////////////////Place into separate function and header file///////////////////////////
   	// Calculate roll and pitch components from accelerometer
  	float roll = atan2(accel.y, accel.z);		
	float pitch = atan2(-(accel.x), sqrt( (pow((accel.y),2)  + (pow((accel.z),2))) ) );  

	// Calculate tilt compensation in X and Y direction
	float Xh = (mag.x * cos(pitch) + sin(roll) * sin(pitch) + mag.z * cos(roll) *sin(pitch));  
	float Yh = (mag.y * cos(roll) - mag.z * sin(roll));

	// Calculate current heading in degrees and radians. Note: North to South clockwise is 0-180 deg
	// South to North Clockwise is -180 to 0 degrees. 
	float curr_heading = atan2(Yh, Xh);
	double curr_heading_deg = curr_heading * (180/3.14159265);

//	printf("%f, %f, %f, %f, %f, %f \n", roll, pitch, Xh, Yh, curr_heading, curr_heading_deg);
	printf("Current Heading (rad)=  %f,		 Current Heading (Deg) = %f \n", curr_heading, curr_heading_deg);



/////////////////////////////////////////////// PID LOOP ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////Place into separate funtion and header file////////////////////////////////
	
	// Set desired target heading
	float heading = 175;
	if(heading > 180){
		heading = -180 + (abs(180 - heading));
	}

	float error = 0;
	// Calculate error, or distance in degrees. Positive error means move CW, Neg error means CCW
	  if(curr_heading_deg > 0 && heading > 0){
		  	error = heading - curr_heading_deg;
	  }
	  else if(curr_heading_deg < 0 && heading < 0){
		  	error = heading - curr_heading_deg;
	  }
	  else if(curr_heading_deg >= 0 && heading <= 0){
			 error = (curr_heading_deg - heading);
		  		if(error > 180){
				       error = error - 360;
				}	       
	  }
	  else if(curr_heading_deg <= 0 && heading >= 0){
		  	error = heading - curr_heading_deg;
		  		if(error > 180){
					error = error - 360;
				}
	  }
	else{
	       	error = 0;
	}

	printf("Error: %f\n", error);
		
	

      std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  }
  //printf("Setting led off!\n");
  set_led(UserLed::Led1, false);

  return 0;
}









/*
  printf("Data ADC Channels: 1 = %f\n", read_adc(AdcChannel::Ch1));

  AxisData mag = read_mag();
  printf("Magnetic field: X = %f, Y = %f, Z = %f\n", mag.x, mag.y, mag.z);

  AxisData accel = read_accel();
  printf("Acceleration: X = %f, Y = %f, Z = %f\n", accel.x, accel.y, accel.z);

  AxisData gyro = read_gyro();
  printf("Gyroscope: X = %f, Y = %f, Z = %f\n", gyro.x, gyro.y, gyro.z);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
*/
/*
//  printf("Temperature: %f\n", read_temp());

//  printf("Pressure: %f\n", read_pressure());

//  printf("Leak sensor: %s\n", read_leak() ? "true" : "false");
*/
