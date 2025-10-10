#include <iostream>
#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyInputsLib.h"

using namespace std;
using MyDateLib::stDate;

enum enComparisonResults { Before = -1, Equal = 0, After = 1 };

enComparisonResults CompareDates(stDate Date1, stDate Date2)
{
	if (MyDateLib::IsDate1BeforeDate2(Date1, Date2))
		return enComparisonResults::Before;

	else if (MyDateLib::IsDate1EqualDate2(Date1, Date2))
		return enComparisonResults::Equal;

	else
		return enComparisonResults::After;
}


int main()
{

	cout << "\n Enter Date1:\n";	
	stDate Date1 = MyDateLib::ReadFullDate();

	cout << "\n Enter Date2:\n";
	stDate Date2 = MyDateLib::ReadFullDate();

	enComparisonResults Result = CompareDates(Date1, Date2);

	cout << "\nCompare Result = " << Result;

	
	return 0;





    
}

