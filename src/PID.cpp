#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

}

void PID::UpdateError(double cte) {

  d_error =  cte - p_error; // Currently p_error contains cte from last cycle.
  i_error += cte; 
  p_error = cte;

}

double PID::TotalError() {

  double steer_value = -Kp*p_error - Kd*d_error - Ki*i_error;

  // Perform sanity check
  if (steer_value > 1)
      steer_value = 1;
  else if  (steer_value < -1)
      steer_value = -1;

  return steer_value;

}
