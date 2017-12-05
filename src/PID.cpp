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
	prev_time = clock()/CLOCKS_PER_SEC;
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
	
	//curr_time = clock();
        //delta_time = (curr_time - prev_time)/CLOCKS_PER_SEC;
	d_error = (cte - prev_cte);///delta_time;
	//prev_time = curr_time; 
 	prev_cte = cte;

	std::cout << "p_error: " << p_error << "i_error: " << i_error << "d_error: " << d_error << "delta: " << delta_time << "prev_cte: " << prev_cte << std::endl;

}

double PID::TotalError() {
	double total_err = 0;
	total_err = -(Kp*p_error) -(Ki*i_error) -(Kd*d_error);
	return total_err;
}
