#include "PID.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
	prev_cte = 0;
	p_error = 0;
	i_error = 0;
	d_error = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	
	p_error = cte;
	i_error += cte;
	

	d_error = (cte - prev_cte);
 	prev_cte = cte;


}

double PID::TotalError() {
	double total_err = 0;
	total_err = -(Kp*p_error) -(Ki*i_error) -(Kd*d_error);
	return total_err;
}
