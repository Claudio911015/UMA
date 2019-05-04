#include <iostream>
#include <stdexcept> // for std::runtime_error
#include "Date.hpp"

// Constructor.
// Can throw. Provides strong exception guarantee.
Date::Date(int day, int month, int year)
	: day_(day), month_(month), year_(year)
{
	check_valid_date(day, month, year);
}

// Helper function.
// Can throw. Provides strong exception guarantee.
void Date::check_valid_date(int day, int month, int year)
{
	if (!is_valid_date(day, month, year))
	{
		throw std::runtime_error("Invalid date"); // exception
		// This is an error handling construct
		// that can be used to abort a constructor.
		// More on this in Term 2.
	}
}

// Helper function, also exposed publicly.
// This function is static.
// Will not throw (except possibly in exceptional situations).
bool Date::is_valid_date(int day, int month, int year)
{
	if (year < 1 || month < 1 || day < 1 || month > 12)
		return false;
	return day <= month_length(month, year);
}

// Helper function, also exposed publicly.
// This function is static.
// Will not throw (except possibly in exceptional situations).
int Date::month_length(int month, int year)
{
	if (month == 2)
		return is_leap_year(year) ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	// not a valid month!
	return 0;
}

// Helper function, also exposed publicly.
// This function is static.
// Will not throw (except possibly in exceptional situations).
bool Date::is_leap_year(int year)
{
	return year % 4 == 0 && (year % 400 == 0 || year % 100 != 0);
}

// Accessor functions. Will not throw (except possibly in exceptional situations).
int Date::get_day() const
{
	return day_;
}

int Date::get_month() const
{
	return month_;
}

int Date::get_year() const
{
	return year_;
}

// Mutator functions. May throw. Provide the strong exception guarantee.
void Date::set_date(int day, int month, int year)
{
	check_valid_date(day, month, year);
	day_ = day;
	month_ = month;
	year_ = year;
}

void Date::set_day(int day)
{
	check_valid_date(day, month_, year_);
	day_ = day;
}

void Date::set_month(int month)
{
	check_valid_date(day_, month, year_);
	month_ = month;
}

void Date::set_year(int year)
{
	check_valid_date(day_, month_, year);
	year_ = year;
}

// Output function
// Will not throw (except possibly in exceptional situations).
void Date::output_shortform() const
{
	std::cout << "I am a date: " << (day_ < 10 ? "0" : "") << day_ << "/" << (month_ < 10 ? "0" : "") << month_ << "/" << year_ << std::endl;
}

