#include <iostream>
#include <limits>
using namespace std;

short ReadYear()
{
    short year;
    cout << "Please enter a year: ";
    cin >> year;
    return year;
}

short ReadInvalidMonth()
{
    short Month;
    cout << "Please enter a Month (1 to 12): ";
    cin >> Month;

    while (cin.fail() || Month < 1 || Month > 12)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Invalid input! Please enter a valid month (1-12): ";
        cin >> Month;
    }
    return Month;
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
    return (month == 2) ? (IsLeapYearOnlyOneLine(year) ? 29 : 28) : numberOfDays[month - 1];
}

short ReadDay(short month, short year)
{
    short Day;
    cout << "Please enter a Day (1 to " << NumberOfDaysInAMonth(month, year) << "): ";
    cin >> Day;

    while (cin.fail() || Day < 1 || Day > NumberOfDaysInAMonth(month, year))
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Invalid input! Please enter a valid day (1-"
            << NumberOfDaysInAMonth(month, year) << "): ";
        cin >> Day;
    }
    return Day;
}

short DaysPassedFromBeginningOfYear(short year, short month, short day)
{
    short totalDays = 0;
    for (short m = 1; m < month; m++)
    {
        totalDays += NumberOfDaysInAMonth(m, year);
    }
    return totalDays + day;
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    stDate Date;
	short ReaminingDaysInYear = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        if (ReaminingDaysInYear > MonthDays)
        {
            ReaminingDaysInYear -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = ReaminingDaysInYear;
            break;

        }
    }
		return Date;
   
}


int main()
{
    short Year = ReadYear();
    short Month = ReadInvalidMonth();
    short Day = ReadDay(Month, Year);

    short DaysOrderInYear = DaysPassedFromBeginningOfYear(Year, Month, Day);
    cout << "Number of days passed from the beginning of the year is "<< DaysOrderInYear << endl;

	stDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
	cout << "The date of day order " << DaysOrderInYear << " in year " << Year << " is "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    return 0;
}
