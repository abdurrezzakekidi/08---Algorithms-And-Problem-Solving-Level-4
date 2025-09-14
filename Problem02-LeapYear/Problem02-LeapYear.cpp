#include <iostream>
/*
 Note: 
 All Years which are perfectly divisible by 4 are leao years 
 execpt for century years (years ending whith 00), which are leap
 years only if they are perfectly divisible  by 400.

*/

using namespace std;


short ReadYear()
{
	short year;

	cout << "Please enter a year to check ?";
	cin >> year;

	return year;

}

bool IsLeapYear(short year)
{
	// leap year if perfectly divisible by 400
	if (year % 400 == 0)
	{
		return true;
	}
	
	else if (year % 100 == 0)
		return false;

	else if (year % 4 == 0)
		return true;

	else
	{
		return false;
	}

		    
}

int main()
{
	// Leap Year:     {1968, 2004, 2012, 1200, 1600, 2000}
	// Not Leap Year: {1971, 2006, 2010, 1700, 1800, 1900}
	short year = ReadYear();
	if (IsLeapYear(year))
		cout << "\nYes, Year [" << year << "] is a leap year.\n";
	else 
		cout << "\nNo, Year [" << year << "] is NOT a leap year.\n";

	system("pause>0");
	return 0;
  
}


