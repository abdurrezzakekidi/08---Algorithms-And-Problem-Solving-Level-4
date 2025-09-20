#include <iostream>
#include <limits>
#include "D://MyCPP_Libs/MyInputsLib.h"
#include "D://MyCPP_Libs/MyDateUtility.h"



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


short NumberOfDaysInAMonth(short month, short year)
{
    if (month < 1 || month > 12)
        return 0;

    int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (MyDateLib::IsLeapYearOnlyOneLine(year) ? 29 : 28) : numberOfDays[month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

stDate IncereaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {

        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;

        }

    }
    else
        Date.Day++;
    return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate ;

	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
}

int GetDifferenceInDaysBetween2Dates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
	short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
		// Swap Dates
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
    }
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Date1 = IncereaseDateByOneDay(Date1);
        Days++;
	}
	return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
   

}



int main()
{
    MyDateLib:: stDate Date1 = MyDateLib::ReadFullDate();
    MyDateLib:: stDate Date2 = MyDateLib::ReadFullDate();

    cout << "\nDiffrence is: " << GetDifferenceInDaysBetween2Dates(Date1, Date2) << " Day(s).";
    cout << "\nDiffrence (Including End Day) is: " << GetDifferenceInDaysBetween2Dates(Date1, Date2, true) << " Day(s).";


    system("pause>0");



}


