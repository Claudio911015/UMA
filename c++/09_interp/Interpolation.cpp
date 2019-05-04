#include "Interpolation.hpp"
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cmath>

Interpolation::Interpolation(const std::vector<double>& x,
			 const std::vector<double>& y)
: x_(x), y_(y){
	if (x.size() != y.size()){
		throw std::runtime_error("Interpolation: differing input sizes");
	}	
	if (x.empty()){
		throw std::runtime_error("Interpolation: no data");
	}

	double last = -std::numeric_limits<double>::infinity();
	for(double d: x_){
		if (!std::isfinite(d) || d<=last){
			throw std::runtime_error("Interpolation: x is not in order");
		}
		last = d;
	}

	for(double d: y){
		if(!std::isfinite(d)){
			throw std::runtime_error("Interpolation: bad value in y");
		}
	}

}

double Interpolation::get_simple(double new_x) const {
	if(!std::isfinite(new_x)){
		throw std::runtime_error("Interpolation: bad new_x value in get");
	}
	if (new_x<=x_.front()){
		return y_.front();
	}
	if (new_x>=x_.back()){
		return y_.back();
	}
	size_t index2=0;
	for(;index2<x_.size();++index2){
		if(new_x<x_.at(index2)){
			break;
		}
	}
	auto index1 = index2-1u;
	double fraction = (new_x-x_.at(index1))/(x_.at(index2)-x_.at(index1));
	double y = y_.at(index1) + fraction*(y_.at(index2)-y_.at(index1));
	return y;
}


//C++ has functions to find an element in a sorted vector, 
// and it is usually best to rely on them rather than to iterate manually.
//std::lower_bound returns the earliest location where new_x can
// be inserted such that the vector will remain ordered.
//It uses an algorithm like https://en.wikipedia.org/wiki/Binary_search_algorithm .
//If the vectors are very long, then this will be much quicker than get_simple.

double Interpolation::get(double new_x) const {
	if(!std::isfinite(new_x)){
		throw std::runtime_error("Interpolation: bad new_x value in get");
	}
	auto it = std::lower_bound(x_.begin(), x_.end(), new_x);
	if (it==x_.begin()){//new_x<=x[0]
		return y_.front();
	}
	if (it==x_.end()){//new_x>x.back()
		return y_.back();
	}
	auto index2 = it-x_.begin(), index1 = index2-1u;
	double fraction = (new_x-x_.at(index1))/(x_.at(index2)-x_.at(index1));
	double y = y_.at(index1) + fraction*(y_.at(index2)-y_.at(index1));
	return y;
}

std::vector<double> 
Interpolation::get_many(const std::vector<double>& new_x) const {
	std::vector<double> y;
	//Not implemented
	return y;
}

