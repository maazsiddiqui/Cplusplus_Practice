// Date.cpp

#include "Date.h"
#include <iostream>
using namespace std;

// Initializes a date to the default value of January 1, 1970
Date::Date() {
   month = 1;
   day = 1;
   year = 1970;
}


// Initializes a date to the values in the parameters.  If the
// date is not legal, sets the date to 1 of the illegal value.
// (Illegal years are set to 2000)
Date::Date(int m, int d, int y) {
   month = m;
   day = d;
   year = y;
   adjust();
}

// Returns the month stored by the class
string Date::getMonth() const { 
   if (month == 1)
      return "January";
   if (month == 2)
      return "February";
   if (month == 3)
      return "March";
   if (month == 4)
      return "April";
   if (month == 5)
      return "May";
   if (month == 6)
      return "June";
   if (month == 7)
      return "July";
   if (month == 8)
      return "August";
   if (month == 9)
      return "September";
   if (month == 10)
      return "October";
   if (month == 11)
      return "November";
   return "December";
}

// Returns the month stored by the class as a number
int Date::getMonthNum() const { return month; }

// Returns the day stored by the class
int Date::getDay() const { return day;}

// Retruns the year stored by the class
int Date::getYear() const { return year;}


// solicit the date from the user
istream& operator >> (istream& in, Date& a) {

	cout << "Input month: ";
	cin >> a.month;
	cout << "Input day: ";
	cin >> a.day;
	cout << "Input year: ";
	cin >> a.year;
	a.adjust();
	
	return in;

}

// output the date in a nice format
ostream& operator << (ostream& out, const Date& a) {

	cout << a.getMonth() << " " << a.day << ", " << a.year << endl;
	
	return out;

}


// Fixes the date so that it is in legal range
void Date::adjust() {
   if (month < 1)
      month = 1;
   if (month > 12)
      month = 12;
   if (day < 1)
      day = 1;
   if (day > 31)
      day = 31;
   if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) &&
       (day > 30))
      day = 30;
   if ((month == 2) && (year % 4 != 0) && (day > 28))
      day = 28;
   if ((month == 2) && (year % 4 == 0) && (day > 29))
      day = 29;
}



