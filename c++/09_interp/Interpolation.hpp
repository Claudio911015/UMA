#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP
#include <vector>

//An example of an immutable class.
//This represents a function which takes the points of x
// to the corresponding points of y.
//x must be in ascending order.
//Returns values linearly interpolated between the points, 
// and flat extrapolated.

class Interpolation{
public:
	Interpolation(const std::vector<double>& x,
		const std::vector<double>& y);
	
	//Return a value of the function, i.e. the y corresponding to some x
	double get_simple(double new_x) const;
	
	//This is like get_simple but implemented in a more complicated way,
	//which you need not worry about.
	double get(double new_x) const;
	
	//This function is not implemented, but it is intended to return
	//the value of the function for each element of the vector x, which
	//is assumed to be in ascending order.
	//This is often needed in practice, where new_x might be about the same length
	//and order of magnitude as x_, and can be implemented quicker than
	//multiple calls to get() or get_simple().
	std::vector<double> get_many(const std::vector<double>& new_x) const; 
private:
	const std::vector<double> x_, y_;
};

#endif
