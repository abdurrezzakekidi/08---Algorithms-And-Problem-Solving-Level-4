#include <iostream>

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

short NumberOfDaysInYear(short year)
{
	return IsLeapYearOnlyOneLine(year) ? 366 : 365;
}

short NumberOfHoursInYear(short year)
{
	return NumberOfDaysInYear(year) * 24;
}

short NumberOfMinutesInYear(short year)
{
	return NumberOfHoursInYear(year) * 60;
}

long NumberOfSecondsInYear(short year)
{
	return NumberOfMinutesInYear(year) * 60;
}

void NumberOfDaysHoursMinutesSecondsInYear(short year)
{
	short days = 365;
	if (IsLeapYearOnlyOneLine(year))
		days = 366;
	int hours = days * 24;
	int minutes = hours * 60;
	long seconds = minutes * 60;
	cout <<  "Number of Days in     Year[" << year <<"]   is " <<days;
	cout << "\nNumber of Hours in   Year [" << year << "] is " << hours;
	cout << "\nNumber of Minutes in Year [" << year << "] is " << minutes;
	cout << "\nNumber of Seconds in Year[" << year << "]  is " << seconds << endl;

	
}


int main()
{
	short year = ReadYear();
	//NumberOfDaysHoursMinutesSecondsInYear(year);

	cout << "Number of Days in    Year[" << year << "] is "
		<< NumberOfDaysInYear(year);

	cout << "\nNumber of Hours in   Year[" << year << "] is "
		<< NumberOfHoursInYear(year);

	cout << "\nNumber of Minutes in Year[" << year << "] is "
		<< NumberOfMinutesInYear(year);

	cout << "\nNumber of Seconds in Year[" << year << "] is "
		<< NumberOfSecondsInYear(year) << endl;

	system("pause>0");
	return 0;
	
  
}


