#include <iostream>
#include <limits>
#include "D://MyCPP_Libs/MyInputsLib.h"
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short year;
    cout << "Please enter a year: ";
    cin >> year;
    return year;
}

short NumberOfDaysFromBeginningOfYear(short year, short month, short day)
{
    short totalDays = 0;
    for (short m = 1; m < month; m++)
    {
        totalDays +=MyInputLib::NumberOfDaysInAMonth(m, year);
    }
    return totalDays + day;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Year = ReadYear();
    Date.Month = MyInputLib:: ReadInvalidMonth();
    Date.Day = MyInputLib:: ReadDay(Date.Month, Date.Year);
    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "Please enter number of days to add? ";
    cin >> Days;
    return Days;
}

stDate DateAddDays(short Days, stDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromBeginningOfYear(Date.Year, Date.Month,
        Date.Day);

    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {
        MonthDays = MyInputLib::NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;

}


int main()
{
	stDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);
 

    cout << "\nDate after adding [" << Days << "] days is: "; 
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
	
        return 0;
    }
