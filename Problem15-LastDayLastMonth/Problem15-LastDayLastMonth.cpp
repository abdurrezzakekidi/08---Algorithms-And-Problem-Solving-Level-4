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

stDate ReadFullDate()
{
    stDate Date;
    Date.Year = ReadYear();
    Date.Month = MyInputLib::ReadInvalidMonth();
    Date.Day = MyInputLib::ReadDay(Date.Month, Date.Year);
    return Date;
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

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{ 
    return (Month == 12);
}




int main()
{
    stDate Date1 = ReadFullDate();

    if (IsLastDayInMonth(Date1))
        cout << "\nYes, Day is Last Day in Month.";
    else
        cout << "\nNo, Day is Not Last Day in Month.";

    if (IsLastMonthInYear(Date1.Month))
        cout << "\n\nYes, Month is Last Month in Year.";
    else 
        cout << "\n\nNo, Month is Not Last Month in Year.";
  

  

}


