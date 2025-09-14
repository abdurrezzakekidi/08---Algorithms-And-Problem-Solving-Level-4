#include <iostream>

using namespace std;

short ReadYear()
{
	short year;

	cout << "Please enter a year to check ?";
	cin >> year;

	return year;

}

short ReadMonth()
{
	short month;

	cout << "Please enter a month to check (1 to 12) ?";
	cin >> month;

	return month;

}

bool IsLeapYearOnlyOneLine(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month > 12)
		return 0;

	int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (month == 2) ?(IsLeapYearOnlyOneLine(year) ? 29 : 28): numberOfDays[month - 1];

	
}

short NumberOfhoursInAMonth(short month, short year)
{
	return NumberOfDaysInAMonth(month, year) * 24;
}

long long NumberOfMinutesInAMonth(short month, short year)
{
	return NumberOfhoursInAMonth(month, year) * 60;
}

long NumberOfSecondsInAMonth(short month, short year)
{
	return NumberOfMinutesInAMonth(month, year) * 60;
}


int main()
{
	short year = ReadYear();
	short month = ReadMonth();

	cout << "Number of Days in    Month[" << month << "] is "
		<< NumberOfDaysInAMonth(month, year);

	cout << "\nNumber of Hours in   Month[" << month << "] is "
		<< NumberOfhoursInAMonth(month, year);

	cout << "\nNumber of Minutes in Month[" << month << "] is "
		<< NumberOfMinutesInAMonth(month, year);

	cout << "\nNumber of Seconds in Month[" << month << "] is "
		<< NumberOfSecondsInAMonth(month, year) << endl;

	system("pause>0");
	return 0;

}


