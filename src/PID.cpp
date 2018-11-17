#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	// initializing coefficients
	PID::Kp = Kp;
  	PID::Ki = Ki;
  	PID::Kd = Kd;
  	// initializing errors
  	p_error = 0;
  	i_error = 0;
  	d_error = 0;

}

void PID::UpdateError(double cte) {
	// updating differential term first because p_error will be overwritten
	d_error = (cte - p_error);
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	// pid control 
	return(-Kp * p_error - Kd * d_error - Ki * i_error);
}

