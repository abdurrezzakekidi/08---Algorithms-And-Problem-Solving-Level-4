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

short ReadDay()
{
	short month;

	cout << "Please enter a Day (1 to 31) ?";
	cin >> month;

	return month;

}

short DayOfWeekOrder(short Day, short Month , short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sun, 1:Mon, 2:Tue... etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
	cout << "\n Day Name : " << DayShortName((DayOfWeekOrder(Day, Month, Year)));

	system("pause>0");
	return 0;
	 
    
}


