#ifndef parameters_h
#define parameters_h

// Physical constants
const float pi = 3.1416f;
const float g = 9.81f;              // m/s^2

// Quadcopter dimensions
const float m = 30e-3f;             // kg
const float I_xx = 16.0e-6f;        // kg.m^2
const float I_yy = 16.0e-6f;        // kg.m^2
const float I_zz = 29.0e-6f;        // kg.m^2
const float l = 33e-3f;             // m

//parâmetros de ajuste de curva
const float a2 = 9.56e-8f;
const float a1 = 7.85e-5f;

const float kl = 2.161e-8f;
const float kd = 1.56e-10f;
#endif