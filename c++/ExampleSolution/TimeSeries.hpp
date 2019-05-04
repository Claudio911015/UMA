// My University number is: *** to be filled in ***

#ifndef TIME_SERIES_HPP
#define TIME_SERIES_HPP

#include <vector>


class TimeSeries
{

	private :
		
		std::vector<double> Values_; // Values of the timeseries

	public :
		// ------------------
		// setValues
		// Implements the member function that sets the Values_ member.
		//
		// Pre-condition
		//    newValues is a vector of doubles.
		//
		// Post-condition
		//    Updates the Values_ member to be a copy of newValues.
		// ------------------
		void setValues(std::vector<double> newValues);

		// ------------------
		// getValues
		// Implements the member function that gets the Values_ member.
		//
		// Pre-condition
		//    
		//
		// Post-condition
		//    Returns a copy of the Values_ member.
		// ------------------
		std::vector<double> getValues() const;

		// ------------------
		// getValues
		// Member function that gets the Values_ member, reversed.
		//
		// Pre-condition
		//    
		//
		// Post-condition
		//    Returns a copy of the Values_ member, backwards.
		// ------------------
		std::vector<double> getValuesBackwards() const;
		
		// ------------------
		// getRange
		// Implements the member function that gets the range.
		//
		// Pre-condition
		//     
		//
		// Post-condition
		//     Return (max - min) of the data stored within the Values_ member.
		double getRange() const;
		// ------------------

		// ------------------
		// getMean
		// Implements the member function that gets the empirical mean.
		//
		// Pre-condition
		//     
		//
		// Post-condition
		//     Return the average of the data stored within the Values_ member.
		double getMean() const;
		// ------------------

		// ------------------
		// getVariance
		// Implements the member function that gets the empirical variance.
		//
		// Pre-condition
		//    
		//
		// Post-condition
		//     Return the empirical variance of the data stored within the Values_
		//     member of the class.
		double getVariance() const;
		// ------------------


		// ------------------
		// output
		// Implements the member function that outputs the time series data in Values_
		// to the console.
		//
		// Pre-condition
		//     
		//
		// Post-condition
		//     After calling this member function, the contents of the Values_ vector
		//     is written to standard output.
		// ------------------
		void output() const;
		
		

}; // class TimeSeries






#endif // TIME_SERIES_HPP
