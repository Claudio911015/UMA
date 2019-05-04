#ifndef DATE_HPP
#define DATE_HPP

//Date represents a (valid) date in the Gregorian calendar
class Date
{
	public:
		
		// public static members
		static bool is_valid_date(int day, int month, int year);
		static bool is_leap_year(int year);
		static int month_length(int month, int year);
		
		// public non-static members
		Date(int day, int month, int year); // constructor
		
		void output_shortform() const; //print to std::cout
		
		int get_day() const; // accessor
		int get_month() const; // accessor
		int get_year() const; // accessor
		
		void set_date(int day, int month, int year); // mutator
		void set_day(int day); // mutator
		void set_month(int month); // mutator
		void set_year(int year); // mutator
		
	private:
		
		// private static members
		static void check_valid_date(int day, int month, int year); // helper
		
		// private non-static data
		int day_;
		int month_;
		int year_;
};

#endif
