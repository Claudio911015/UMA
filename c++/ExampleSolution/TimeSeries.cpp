#include <iostream>
#include "TimeSeries.hpp"

void TimeSeries::setValues(std::vector<double> newValues)
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 1a
	Values_ = newValues;
	/////////////////////////////////////////////////////////////////////
}

std::vector<double> TimeSeries::getValues() const
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 1b
	return Values_;
	/////////////////////////////////////////////////////////////////////
}

std::vector<double> TimeSeries::getValuesBackwards() const
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 1c
	std::vector<double> backwards = Values_;
	for(std::vector<double>::size_type i = 0u; i != Values_.size(); ++i)
	{
		backwards.at(i) = Values_.at(Values_.size()-1u-i);
	}
	return backwards;
	/////////////////////////////////////////////////////////////////////
}

void TimeSeries::output() const
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 1d
	for (double v :  Values_)
	{
		std::cout << v << "\n";
	}
	/////////////////////////////////////////////////////////////////////
}

double TimeSeries::getRange() const
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 2
	if (Values_.size() == 0u)
	{
		return 0.0;
	}
	
	double min = Values_.at(0u);
	double max = Values_.at(0u);
	for (double v :  Values_)
	{
		min = v < min ? v : min;
		max = v > max ? v : max;
	}
	const double range = max - min;
	
	return range;
	/////////////////////////////////////////////////////////////////////
}

double TimeSeries::getMean() const
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 3
	if (Values_.size() == 0u)
	{
		std::cerr << "Can't calculate mean of empty vector!" << std::endl;
		return 0.0; // chosen not to terminate the whole program in this instance
		// but instead to return a vaguely sensible value
		// In reality, would be better to throw an exception!
	}
	
	// note: without the validation of the empty vector case
	// this would return 0.0 if Values_.size() == 0u
	// no division by zero can occur with this placement of the division
	// But, the placement of the division has implications for performance and accuracy
	double mean = 0.0;
	for (double v :  Values_)
	{
		mean += v / Values_.size();
	}
	
	return mean;
	/////////////////////////////////////////////////////////////////////
}

double TimeSeries::getVariance() const
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 4
	if (Values_.size() <= 1u)
	{
		return 0.0; // avoid division by zero
	}
	
	double mean = getMean(); // calculate this once outside the loop, instead of repeatedly
	double variance = 0.0;
	for (double v :  Values_)
	{
		double residual = v - mean;
		variance += residual * residual;
	}
	variance /= (Values_.size() - 1u);
	// variance /= Values_.size(); // or other variants are also acceptable
	
	return variance;
	/////////////////////////////////////////////////////////////////////
}

