#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  d_Kp = 1;
  d_Ki = 1;
  d_Kd = 1;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  prev_cte = 0;
  total_cte = 0;
}

void PID::UpdateError(double cte) {
  total_cte += cte;
  p_error = - Kp * cte;
  i_error = - Ki * total_cte;
  d_error = - Kd * (cte - prev_cte);
  prev_cte = cte;
}

double PID::TotalError() {
  return p_error + i_error + d_error;
}
