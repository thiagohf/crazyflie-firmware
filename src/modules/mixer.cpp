# include " mixer .h"
// Class constructor
Mixer :: Mixer () : motor_1 ( MOTOR1 ) , motor_2 ( MOTOR2 ) , motor_3 ( MOTOR3 ) , motor_4 ( MOTOR4 )
{
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer :: actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
 {
mixer (f_t , tau_phi , tau_theta , tau_psi );
motor_1 = control_motor ( omega_r_1 );
motor_2 = control_motor ( omega_r_2 );
motor_3 = control_motor ( omega_r_3 );
motor_4 = control_motor ( omega_r_4 );

}

// Converts total trust force (N) and torques (N.m) to angular velocities (rad/s)
void Mixer :: mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
 (...)
}

// Converts desired angular velocity (rad/s) to PWM signal (%)
float Mixer :: control_motor ( float omega_r )
{
(...)
}