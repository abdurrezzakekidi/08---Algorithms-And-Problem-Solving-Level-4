#include <iostream>
#include "D://MyCPP_Libs/MyInputsLib.h"
#include "D://MyCPP_Libs/MyDateUtility.h"

using namespace std;
using MyDateLib::stDate;
using MyDateLib::DayOfWeekOrder;
using MyDateLib::DayShortName;


bool IsEndOfWeek(stDate Date)
{
	// in Turkey week starts on Monday and ends on Sunday
	return (DayOfWeekOrder(Date.Day, Date.Month, Date.Year)  == 0);
}

bool IsWeekEnd(stDate Date)
{
	// in Turkey Weekends are Saturday(6) and Sunday(0)
	return (DayOfWeekOrder(Date) == 0 || DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !MyDateLib::IsWeekEnd(Date);
}

short DaysUntilEndOfWeek(stDate Date)
{
	return (6 - DayOfWeekOrder(Date));
}

short DaysUntilEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = MyDateLib::NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;
	return MyDateLib::GetDifferenceInDaysBetween2Dates(Date, EndOfMonthDate, true);
	
}

short DaysUntilEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;
	return MyDateLib::GetDifferenceInDaysBetween2Dates(Date, EndOfYearDate, true);

}



int main()
{
    stDate Date1 = MyDateLib::GetSystemDate();

    cout << "\n Today is: " << DayShortName(DayOfWeekOrder(Date1)) << ", "
		<< Date1.Day << "/"  << "/" << Date1.Year << endl;
	//---------------------------------------------

	cout << "\nIs it End of Week?\n";
	if (MyDateLib::IsEndOfWeek(Date1))
		cout << "Yes, It is Sunday, it's of week.\n";
	else
		cout << "No, it's Not End of Week.\n";
	//---------------------------------------------

	cout << "\nIs it Week End?\n";
	if (MyDateLib::IsWeekEnd(Date1))
		cout << "Yes, It is Weekend.\n";
	else
		cout << "No today is " << DayShortName(DayOfWeekOrder(Date1)) << ", it's Not Weekend.\n";
	//---------------------------------------------

	cout << "\nIs it Business Day?\n";
	if (MyDateLib::IsBusinessDay(Date1))
		cout << "Yes, It is Business Day.\n";
	else
		cout << "No, today is " << DayShortName(DayOfWeekOrder(Date1)) << ", it's Not Business Day.\n";
	//---------------------------------------------
	cout << "\nDays until end of week: " << MyDateLib::DaysUntilEndOfWeek(Date1) << " days.\n";

	cout << "\nDays until end of month: " << MyDateLib::DaysUntilEndOfMonth(Date1) << " days.\n";
	cout << "\nDays until end of year: " << MyDateLib::DaysUntilEndOfYear(Date1) << " days.\n";

	//---------------------------------------------







	system("pause>0");
	return 0;
   
}


