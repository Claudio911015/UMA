#include "ComputeMovingAverage.hpp"

std::vector<double> ComputeMovingAverage (const std::vector<double> & Values, std::vector<double>::size_type p)
{
	/////////////////////////////////////////////////////////////////////
	/// Your implementation for question 5
	std::vector<double>::size_type N = Values.size();
	
	// optimisation in case p == 1u
	if (p == 1u)
	{
		return Values;
	}
	
	// local variable to store the values, a copy of which gets returned
	std::vector<double> RunningMeanP;
	
	if ((p > N) || (N == 0u) || (p == 0u))
	{
		// there is nothing to compute. return empty vector
		// ideally, p == 0u should throw an exception, but we don't know about those yet...
		return RunningMeanP;
	}
	
	const std::vector<double>::size_type num_elements_moving_average = N - p + 1u;
	
	RunningMeanP.resize(num_elements_moving_average);
	
	// calculate RunningMeanP.at(0u) first
	for (std::vector<double>::size_type i = 0u; i != p; ++i)
	{
		RunningMeanP.at(0u) += Values.at(i) / p;
	}
	
	// then calculate the remaining elements
	// here, we use an optimisation to avoid needing nested loops
	// but this comes at the potential cost of losing accuracy
	//
	// A suitable alternative is to use nested loops!
	for (std::vector<double>::size_type i = 1u; i != num_elements_moving_average; ++i)
	{
		RunningMeanP.at(i) = RunningMeanP.at(i - 1u) - Values.at(i - 1u) / p + Values.at(i + p - 1u) / p;
	}
	
	return RunningMeanP;
	/////////////////////////////////////////////////////////////////////
}

