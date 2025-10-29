#include <iostream>
#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyInputsLib.h"

using namespace std;
using MyDateLib::stDate;

enum enComparisonResults { Before = -1, Equal = 0, After = 1 };
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
    if(
       MyDateLib:: CompareDates(Period2.EndDate, Period1.StartDate) ==enComparisonResults::Before
        ||
		MyDateLib:: CompareDates(Period2.StartDate, Period1.EndDate) == enComparisonResults::After
        )
		return false;
    else
		return true;


}

int main()
{
	cout << "\n Enter Period1:\n";
    stPeriod Period1 = ReadPeriod();

	cout << "\n Enter Period2:\n";
	stPeriod Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2))
        cout << "\n Yes, Periods Overlap\n";
	else
		cout << "\n No, Periods don't Overlap\n";

	system("pause>0");
	return 0;

    
}


