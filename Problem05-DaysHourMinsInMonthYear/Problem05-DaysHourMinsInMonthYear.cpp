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

short NumberOfDaysInAMonth(short month , short year)
{
	if(month < 1 || month > 12)
		return 0;

	else if (month == 2)
		return IsLeapYearOnlyOneLine(year) ? 29 : 28;

	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

short NumberOfDaysInAMonthV2(short month, short year)
{
	if (month < 1 || month > 12)
		return 0;

	if (month == 2)
	{
		return IsLeapYearOnlyOneLine(year) ? 29 : 28;
	}
	short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

	for (short i = 0; i < 7; i++)
	{
		if (arr31Days [i -1] == month)
			return 31;
	}
	return 30;

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

		cout << "Number of Days in    Month[" << month <<  "] is "
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


