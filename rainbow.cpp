#include "bindings.h"
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>

void color_from_sine(float percentage, uint8_t (&ledValues)[3]) {
  float pi = M_PI;
  float red = std::sin(percentage * 2.0 * pi) * 0.5 + 0.5;
  float green = std::sin((percentage + 0.33) * 2.0 * pi) * 0.5 + 0.5;
  float blue = std::sin((percentage + 0.67) * 2.0 * pi) * 0.5 + 0.5;
  ledValues[0] = static_cast<uint8_t>(red * 255.0);
  ledValues[1] = static_cast<uint8_t>(green * 255.0);
  ledValues[2] = static_cast<uint8_t>(blue * 255.0);
}



int main() {
  std::cout << "Creating rainbow effect!" << std::endl;
  uint8_t rgb_array[3];
  for (int i = 0; i < 1; i++){
    int steps = 1000;
    for (int i = 0; i <= steps; i++) {
      float ratio = static_cast<float>(i) / static_cast<float>(steps);
      color_from_sine(ratio, rgb_array);
      set_neopixel(&rgb_array, 1);
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  }
  rgb_array[0] = static_cast<uint8_t>(0);
  rgb_array[1] = static_cast<uint8_t>(0);
  rgb_array[2] = static_cast<uint8_t>(0);
      set_neopixel(&rgb_array, 1);


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

  printf("Initiating navigator module.\n");
  init();
	
  
  printf("Setting led on!\n");
  set_led(UserLed::Led1, true);
  set_led(UserLed::Led2, true);
  set_led(UserLed::Led3, true);
  
  printf("Temperature: %f\n", read_temp());

  printf("Pressure: %f\n", read_pressure());

  printf("Leak sensor: %s\n", read_leak() ? "true" : "false");
  
  ADCData adc = read_adc_all();
  printf("Reading ADC Channels: 1 = %f, 2 = %f, 3 = %f, 4 = %f\n",
         adc.channel[0], adc.channel[1], adc.channel[2], adc.channel[3]);

  printf("Data ADC Channels: 1 = %f\n", read_adc(AdcChannel::Ch1));

  AxisData mag = read_mag();
  printf("Magnetic field: X = %f, Y = %f, Z = %f\n", mag.x, mag.y, mag.z);

  AxisData accel = read_accel();
  printf("Acceleration: X = %f, Y = %f, Z = %f\n", accel.x, accel.y, accel.z);

  AxisData gyro = read_gyro();
  printf("Gyroscope: X = %f, Y = %f, Z = %f\n", gyro.x, gyro.y, gyro.z);

  
  printf("Setting led off!\n");
  //set_led_all(false);
  set_led(UserLed::Led1, false);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  set_led(UserLed::Led2, false);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  set_led(UserLed::Led3, false);

	  return 0;
}

/*
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



  for(int i= 0; i < 3; i++){
	 AxisData  mag = nav.read_mag();
	  printf("mag values: X=%f, Y=%f, Z=%f\n", mag.x, mag.y, mag.z);
  	  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  
  uint8_t mutable leds = [[0,0,255], [0,255,0], [255,0,0]];
  nav.set_neopixel(&mutable leds);

*/
