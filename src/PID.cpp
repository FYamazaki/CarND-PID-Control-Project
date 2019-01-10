#include <iostream>
#include "PID.h"
#include "math.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  fstart = false;
  p_error = i_error = d_error = 0;
  prev_cte = total_error = 0;
  count = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  def_throttle = 0.5;
  Kt = 0.99 * def_throttle;
  fstart = false;
  p_error = i_error = d_error = 0;
  p_error = prev_cte = total_error = 0;
  count = 0;
}

void PID::UpdateError(double err) {
  count++;
  i_error += err;
  if (!fstart) {
    prev_cte = err;
    fstart = true;
  }
  d_error = err - prev_cte;
  prev_cte = err;
  p_error = err;
  total_error += err*err;
}

double PID::TotalError() {
  return total_error;
}

double PID::GetSteering() {
  std::cout << "PID: " << p_error << " " << d_error << " " << i_error << std::endl;
  double steer = -p_error*Kp - d_error*Kd - i_error*Ki;
  if (steer > 1)
    return 1;
  else if (steer < -1)
    return -1;
  else
    return steer;
}

double PID::GetThrottle() {
  //double throttle = 10.0 - Kt * fabs(d_error);
  //double throttle = 0.8;
  double throttle = def_throttle - Kt * fabs(GetSteering());
  return throttle;
}
