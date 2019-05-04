#include "Interpolation.hpp"
#include <iostream>

void demo(const Interpolation& in, double x){
	std::cout<<in.get(x)<<" "<<in.get_simple(x)<<"\n";
}

int main(){
	Interpolation in({2,4,6},{1,190.15,-1427});
	demo(in,5);
	demo(in,4);
	demo(in,3.999);
	demo(in,-324893);
	demo(in,2410);
}
