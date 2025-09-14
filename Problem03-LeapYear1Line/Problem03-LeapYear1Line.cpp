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

bool IsLeapYearOnlyOneLine(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
	// Leap Year:     {1968, 2004, 2012, 1200, 1600, 2000}
	// Not Leap Year: {1971, 2006, 2010, 1700, 1800, 1900}
	short year = ReadYear();
	if (IsLeapYearOnlyOneLine(year))
		cout << "\nYes, Year [" << year << "] is a leap year.\n";
	else
		cout << "\nNo, Year [" << year << "] is NOT a leap year.\n";

	system("pause>0");
	return 0;

}


