#include <iostream>
#include "D://MyCPP_Libs/MyDateUtility.h"


using namespace std;
using MyDateLib::stDate;

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enComparisonResults { Before = -1, Equal = 0, After = 1
};

enComparisonResults CompareDates(stDate Date1, stDate Date2)
{
    if (MyDateLib::IsDate1BeforeDate2(Date1, Date2))
        return enComparisonResults::Before;

    else if (MyDateLib::IsDate1EqualDate2(Date1, Date2))
        return enComparisonResults::Equal;

    else
        return enComparisonResults::After;
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\n Enter Start Date:\n";
    Period.StartDate = MyDateLib::ReadFullDate();
    cout << "\n Enter End Date:\n";
    Period.EndDate = MyDateLib::ReadFullDate();
    return Period;
}

bool IsDateInPeriod(stDate DateToCheck, stPeriod StPeriod )
{
    if (
        MyDateLib::IsDate1BeforeDate2(DateToCheck, StPeriod.StartDate)
        ||
		MyDateLib::IsDate1AfterDate2(DateToCheck, StPeriod.EndDate)
        )

        return false;
    else
        return true;
}

bool IsDateInPeriodOptim(stDate DateToCheck, stPeriod StPeriod)
{
    return !(MyDateLib:: CompareDates(DateToCheck, StPeriod.StartDate) == enComparisonResults::Before
        ||
       MyDateLib:: CompareDates(DateToCheck, StPeriod.EndDate) == enComparisonResults::After);
    
}
int main()
{
    
    cout << "\n Enter Period1:\n";
    stPeriod Period1 = ReadPeriod();

	cout << "\n Enter Date to Check:\n";
	stDate DateToCheck = MyDateLib::ReadFullDate();
	
    if(IsDateInPeriodOptim(DateToCheck,Period1))
        cout << "\n Yes, Date is in Period\n";
    else
		cout << "\n No, Date is not in Period\n";

}


