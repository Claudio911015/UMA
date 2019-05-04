#include <iostream>
#include <cstdlib>
#include "Date.hpp"


void date_test_main()
{
	Date a(2,1,2015);
	Date b(2,1,2022);
	Date c = b-20;
	std::cout << "The number of days from "<<a<<" until "<<c<<" is "<<(c-a)<<"\n";
}

int main()
{
	date_test_main();
	return EXIT_SUCCESS;
}
