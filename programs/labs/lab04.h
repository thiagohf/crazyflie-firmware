#include "crazyflie.h"
#include "mbed.h"

// Define motor 1 as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor(float omega_r) {
  return a2 * omega_r * omega_r + a1 * omega_r;
}

// Main program
int main() {
  wait(5);
  // Turn on motor 1 with 1.000 rad/s for 0.5 s
  motor1 = control_motor(1000.0);
  motor2 = control_motor(2000.0);
  motor3 = control_motor(1000.0);
  motor4 = control_motor(2000.0);
  wait(1.5);
  // Turn off motor 1
  motor1 = 0.0;
  motor2 = 0.0;
  motor3 = 0.0;
  motor4 = 0.0;

  // End of program
  while (true) {
  }
}