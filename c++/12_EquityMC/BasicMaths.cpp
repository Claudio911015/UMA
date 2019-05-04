#include "BasicMaths.h"
#include <cmath>


//standard normal CDF
double Ncdf(double x){
	return 0.5+0.5*erf(x/sqrt(2));
}

//standard normal PDF
double Npdf(double x){
	return exp(-0.5*x*x)/sqrt(8*atan(1));
}
