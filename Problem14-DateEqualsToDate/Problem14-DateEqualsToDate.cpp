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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false) : false;
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 is Equal To Date2.";
    else
        cout << "\nNo, Date1 is NOT Equal To Date2.";

}


