#include "PID.h"
/*
double get_heading(const AxisData& mag){

	return 20;
}
double get_heading(float Mx, float My, float Mz){
return 20;
}

double get_error(double target_heading, double curr_heading_deg){
	return 5.0;
}

*/
int get_error(int curr_heading, int target_heading){
	int num = curr_heading + target_heading;
	return num;
}
