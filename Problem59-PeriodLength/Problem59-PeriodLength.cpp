#include <iostream>
#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyInputsLib.h"

using namespace std;
using MyDateLib::stDate;

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\n Enter Start Date:\n";
    Period.StartDate = MyDateLib::ReadFullDate();
    cout << "\n Enter End Date:\n";
    Period.EndDate = MyDateLib::ReadFullDate();
    return Period;
}

short GetPeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
	return MyDateLib::GetDifferenceInDaysBetween2Dates(Period.StartDate, Period.EndDate, IncludeEndDay);
}


int main()
{
    cout << "\n Enter Period1:\n";
    stPeriod Period1 = ReadPeriod();
	short PeriodLengthInDays = GetPeriodLengthInDays(Period1);

    cout << "\n Period Length In Days = " << PeriodLengthInDays;
	cout << "\n Period Length In Days (Including End Day) = " << GetPeriodLengthInDays(Period1, true);

	system("pause>0");
	return 0;
}


