// My University number is: *** to be filled in ***

#include <iostream>
#include <cstdlib>
#include "TimeSeries.hpp"
#include "ComputeMovingAverage.hpp"
#include "LoadIBMData.hpp"

void time_series_test_main()
{
	TimeSeries TS;
	std::cout << "Loading and setting data...";
	TS.setValues(LoadIBMData());
	std::cout << " Done." << std::endl;
	std::cout << std::endl;
	
	//Output the values of the time series object...
	// Actually, don't (unless you need to test)! There are 400 of them!
	//std::cout << "The values of the TS object are:" << std::endl;
	//TS.output();
	//std::cout << "END of values." << std::endl;
	
	//Calculate and output some of the properties of the object TS
	std::cout << "The range of your values is: " << TS.getRange() << std::endl;
	std::cout << "The mean of your values is: " << TS.getMean() << std::endl;
	std::cout << "The variance of your values is: " << TS.getVariance() << std::endl;
	
	std::cout << std::endl;
	
	
	// Calculate and output the moving average
	// Choose p quite large, so that we don't need to display too many values
	// as they won't easily fit on the screen.
	std::vector<double>::size_type p = 280u; // moving average window size
	
	// or if you'd rather
	//std::cout << "Please enter a value for p, the moving average window length: ";
	//std::cin >> p;
	
	TimeSeries MA;
	std::cout << "Calculating the moving average...";
	MA.setValues(ComputeMovingAverage(TS.getValues(), p));
	std::cout << " Done." << std::endl;
	
	std::cout << "The values of the moving-average of window length " << p << " are:" << std::endl;
	MA.output();
	std::cout << "END of values." << std::endl;
	MA.getValuesBackwards(); //perhaps test the function which isn't tested yet.
}

int main()
{
	time_series_test_main();
	return EXIT_SUCCESS;
}

