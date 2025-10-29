#include <iostream>
#include "D://MyCPP_Libs/MyDateUtility.h"

using namespace std;
using MyDateLib::stDate;

enum enComparisonResults { Before = -1, Equal = 0, After = 1 
};
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

enComparisonResults CompareDates(stDate Date1, stDate Date2)
{
    if (MyDateLib::IsDate1BeforeDate2(Date1, Date2))
        return enComparisonResults::Before;

    else if (MyDateLib::IsDate1EqualDate2(Date1, Date2))
        return enComparisonResults::Equal;

    else
        return enComparisonResults::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
       MyDateLib:: CompareDates(Period2.EndDate, Period1.StartDate) == enComparisonResults::Before
        ||
       MyDateLib:: CompareDates(Period2.StartDate, Period1.EndDate) == enComparisonResults::After
        )
        return false;
    else
        return true;


}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;
    stDate OverlapStartDate = (MyDateLib:: CompareDates(Period1.StartDate, Period2.StartDate) == enComparisonResults::After) ? Period1.StartDate : Period2.StartDate;
    stDate OverlapEndDate = (MyDateLib:: CompareDates(Period1.EndDate, Period2.EndDate) == enComparisonResults::Before) ? Period1.EndDate : Period2.EndDate;
    return MyDateLib::GetDifferenceInDaysBetween2Dates(OverlapStartDate, OverlapEndDate);
}

short GetPeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
    return MyDateLib::GetDifferenceInDaysBetween2Dates(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateInPeriodOptim(stDate DateToCheck, stPeriod StPeriod)
{
    return !(MyDateLib:: CompareDates(DateToCheck, StPeriod.StartDate) == enComparisonResults::Before
        ||
       MyDateLib:: CompareDates(DateToCheck, StPeriod.EndDate) == enComparisonResults::After);

}

int CountOverlapDaysOptim(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = GetPeriodLengthInDays(Period1, true);
	int Period2Length = GetPeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while(MyDateLib::IsDate1BeforeDate2(Period1.StartDate,Period1.EndDate))
        {
            if(IsDateInPeriodOptim(Period1.StartDate,Period2))
				OverlapDays++;
			Period1.StartDate = MyDateLib::IncereaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (MyDateLib::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateInPeriodOptim(Period2.StartDate, Period1))
                OverlapDays++;
            Period2.StartDate = MyDateLib::IncereaseDateByOneDay(Period2.StartDate);
        }
	}
	return OverlapDays;
    
}

int main()
{
    cout << "\n Enter Period1:\n";
    stPeriod Period1 = ReadPeriod();

    cout << "\n Enter Period2:\n";
    stPeriod Period2 = ReadPeriod();
	short OverlapDays = CountOverlapDays(Period1, Period2);
    int OverlapDays2 = CountOverlapDaysOptim(Period1, Period2);


	cout << "\n Overlap Days Count Is :" << OverlapDays2;
}


