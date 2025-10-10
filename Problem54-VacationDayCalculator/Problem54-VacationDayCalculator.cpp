#include <iostream>

#include "D://MyCPP_Libs/MyDateUtility.h"

using namespace std;
using MyDateLib::stDate;
using MyDateLib::DayOfWeekOrder;
using MyDateLib::DayShortName;

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;

	while (MyDateLib::IsDate1BeforeDate2(DateFrom,DateTo))
	{
		if (MyDateLib::IsBusinessDay(DateFrom))
		{
			DaysCount++;
		}
		DateFrom = MyDateLib::IncereaseDateByOneDay(DateFrom);

	}
	return DaysCount;
}

int main()
{
	cout <<"\nVacation Starts:\n ";
	stDate DateFrom = MyDateLib::ReadFullDate(); 

	cout <<"\nVacation Ends:\n ";
	stDate DateTo = MyDateLib::ReadFullDate();

	cout << "\n\nVaction From: " << MyDateLib::DayShortName(DayOfWeekOrder(DateFrom)) << ", " 
		<< DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << "\n\nVaction To: " << MyDateLib::DayShortName(DayOfWeekOrder(DateTo)) << ", " 
		<< DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\n\n Actucal Vacation Days Is: " <<MyDateLib::CalculateVacationDays(DateFrom, DateTo) << " Day(s).\n";

	system("pause>0");

	return 0;
   
}

