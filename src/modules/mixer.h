# ifndef mixer_h
2 # define mixer_h
3
# include " mbed .h"
# include " src / utils / pin_names .h"
# include " src / utils / parameters .h"

// Mixer class
class Mixer
{
public :
// Class constructor
Mixer () ;
// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi ) ;
private :
// Motors PWM outputs
PwmOut motor_1 , motor_2 , motor_3 , motor_4 ;
// Angular velocities ( rad /s)
float omega_r_1 , omega_r_2 , omega_r_3 , omega_r_4 ;
// Converts total trust force (N) and torques (N.m) to angular velocities (rad/s)
void mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi );
// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor ( float omega_r );
 };

# endif
