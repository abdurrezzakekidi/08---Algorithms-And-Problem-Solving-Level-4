#include <iostream>

using namespace std;

short ReadYear()
{
	short year;

	cout << "Please enter a year ?";
	cin >> year;

	return year;

}

short ReadMonth()
{
	short month;

	cout << "Please enter a month   (1 to 12) ?";
	cin >> month;

	return month;

}

bool IsLeapYearOnlyOneLine(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sun, 1:Mon, 2:Tue... etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short NumberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month > 12)
		return 0;

	int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (month == 2) ? (IsLeapYearOnlyOneLine(year) ? 29 : 28) : numberOfDays[month - 1];


}

string MonthShortName(short MonthNumber)
{
	string arrMnthNames[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug", "Sep", "Oct", "Nov", "Dec"};
	return arrMnthNames[MonthNumber - 1];
}

void PrintMonthCalendar(short year, short month)
{
	int NumberOfDays;

	// Index of the day from 0 to 6
	int Current = DayOfWeekOrder(1, month, year);

	NumberOfDays = NumberOfDaysInAMonth(month, year);

	printf("\n_________________%s___________________\n\n",
		MonthShortName(month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i;
	for (i = 0; i < Current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n______________________________________\n");


}



int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	PrintMonthCalendar(Year, Month);

	system("pause");
	return 0;

	
    
}

