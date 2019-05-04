#include <iostream>
#include <cstdlib>
#include "Date.hpp"


void date_test_main()
{
	Date test(15, 12, 2015);
	test.output_shortform();
	Date(9, 12, 2014).output_shortform();
	Date today(30, 11, 2015);
		
	std::cout << "The year of the test is " << test.get_year() << std::endl;
	
	//std::cout << test.day_ << std::endl;
	//std::cout << Date::get_day() << std::endl;
	//Date::output_shortform();
	
	//std::cout << (Date(35, 12, 2014)).is_valid_date(1, 1, 2014) << std::endl;
	
	test.set_year(2015); // you wish
	test.output_shortform();
	
	// Uncomment this for a crash. We will see how to handle this better soon.
	//Date baddate(31, 11, 2014);
	
}

int main()
{
	date_test_main();
	return EXIT_SUCCESS;
}
