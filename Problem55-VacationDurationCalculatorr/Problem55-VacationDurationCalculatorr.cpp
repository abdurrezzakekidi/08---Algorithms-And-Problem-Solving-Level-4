#include <iostream>

#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyInputsLib.h"

using namespace std;
using MyDateLib::stDate;

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;

    while (MyDateLib::IsWeekEnd(DateFrom))
    {
        DateFrom = MyDateLib::IncereaseDateByOneDay(DateFrom);
    }
    // here we increase the vacation dates to add all weekends to it 

    for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
    {
        if(MyDateLib::IsWeekEnd(DateFrom))
			WeekEndCounter++;
		DateFrom = MyDateLib::IncereaseDateByOneDay(DateFrom);
    }

    // in case the return date is week end keep adding one day util you reash business day
    while (MyDateLib::IsWeekEnd(DateFrom))
    {
		DateFrom = MyDateLib::IncereaseDateByOneDay(DateFrom);
    }
	return DateFrom;

    
}



int main()
{
    cout << "Vacation Starts:\n";
	stDate DateFrom = MyDateLib::ReadFullDate();

    cout << "\nPlease enter vacation days?";
     short VacationDays = MyInputLib::ReadInvalidNumber();

    stDate ReturnDate = CalculateVacationReturnDate(DateFrom, VacationDays);

    cout << "\n\nReturn Date: " << MyDateLib::DayShortName(DayOfWeekOrder(ReturnDate)) << " , "
        << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;
    
}

