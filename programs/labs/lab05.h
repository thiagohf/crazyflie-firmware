#include "crazyflie.h"
#include "mbed.h"

// Define motor 1 as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

//Define angular velocities (rad/s)
float w1;
float w2;
float w3;
float w4;

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor(float omega_r) {
  return a2 * omega_r * omega_r + a1 * omega_r;
}

// Converte a força total (N) e os torques (N.m) para velocidades angulares (rad/s)
void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    float w1squared = (1/(4*kl))*f_t - (1/(4*kl*l))* tau_phi - (1/(4*kl*l))* tau_theta - (1/(4*kd))* tau_psi;
    float w2squared = (1/(4*kl))*f_t - (1/(4*kl*l))* tau_phi + (1/(4*kl*l))* tau_theta + (1/(4*kd))* tau_psi;
    float w3squared = (1/(4*kl))*f_t + (1/(4*kl*l))* tau_phi + (1/(4*kl*l))* tau_theta - (1/(4*kd))* tau_psi;
    float w4squared = (1/(4*kl))*f_t + (1/(4*kl*l))* tau_phi - (1/(4*kl*l))* tau_theta + (1/(4*kd))* tau_psi;

    if(w1squared <= 0)
    {
        w1 = 0;
    }
    else 
    {
        w1 = sqrt(w1squared);
    }
        if(w2squared <= 0)
    {
        w2 = 0;
    }
    else 
    {
        w2 = sqrt(w2squared);
    }
        if(w3squared <= 0)
    {
        w3 = 0;
    }
    else 
    {
        w3 = sqrt(w3squared);
    }
        if(w4squared <= 0)
    {
        w4 = 0;
    }
    else 
    {
        w4 = sqrt(w4squared);
    }
}


// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor1 = control_motor(w1);
    motor2 = control_motor(w2);
    motor3 = control_motor(w3);
    motor4 = control_motor(w4);
}
// Main program
int main() 
{
    // Actuate motor with 70% mg total thrust force (N) and zero torques
    wait(3);
    actuate (0,0,0,-0.0017);
    wait(5);
    // Turn off all motors
    actuate(0,0,0,0);
//End of program
  while (true) 
  {
  }
}