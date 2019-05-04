#ifndef ComputeMovingAverage_HPP
#define ComputeMovingAverage_HPP

#include <vector>


// ------------------
// computeMovingAverage
// Implements the free function that computes the moving average.
//
// Pre-condition
//     Values: The time series data.
//     p: The width of the window.
//
// Post-condition
//     If one or more moving averages is computed, the results are stored in the returned vector.
//    
//     If no moving averages are computed, e.g. the input is invalid,
//     then an empty vector should be returned.
std::vector<double> ComputeMovingAverage (const std::vector<double> & Values, std::vector<double>::size_type p);
// ------------------



#endif // ComputeMovingAverage_HPP

