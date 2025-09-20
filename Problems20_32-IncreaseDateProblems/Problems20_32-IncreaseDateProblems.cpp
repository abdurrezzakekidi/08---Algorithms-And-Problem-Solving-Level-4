#include <iostream>
#include "D://MyCPP_Libs/MyInputsLib.h"
#include "D://MyCPP_Libs/MyDateUtility.h"

using namespace std;
using MyDateLib::stDate;


 stDate IncereaseDateByXDays(stDate Date, short DaysToAdd)
{
	for (short i = 1; i <= DaysToAdd; i++)
		Date = MyDateLib::IncereaseDateByOneDay(Date);
	return Date ;
}

 stDate InceraseDateByOneWeek(stDate Date)
 {
	 return MyDateLib:: IncereaseDateByXDays(Date, 7);
 }

 stDate InceraseDateByXWeeks(stDate Date, short WeeksToAdd)
 {
	 for (int i = 1; i <= WeeksToAdd; i++)
	 {
		 Date = MyDateLib::InceraseDateByOneWeek(Date);

	 }
	 return Date;
 }

 stDate InceraseDateByOneMonth(stDate Date)
 {
	 if (Date.Month == 12)
	 {
		 Date.Month = 1;
		 Date.Year++;
	 }
	 else
	 {
		 Date.Month++;
	 }
		
 
 short NumberOfDaysInCurrentMonth =
	 MyDateLib:: NumberOfDaysInAMonth(Date.Month, Date.Year);
 if (Date.Day > NumberOfDaysInCurrentMonth)
 {
	 Date.Day = NumberOfDaysInCurrentMonth;
 }
 return Date;
 }

 stDate InceraseDateByXMonths(stDate Date, short MonthsToAdd)
 {
	 for (int i = 1; i <= MonthsToAdd; i++)
	 {
		 Date = MyDateLib::InceraseDateByOneMonth(Date);
	 }
	 return Date;
 }

 stDate InceraseDateByOneYear(stDate Date)
 {
	 Date.Year++;
	 return Date;
 }

 stDate InceraseDateByXYears(stDate Date, short YearsToAdd)
 {
	 for (int i = 1; i <= YearsToAdd; i++)
	 {
		 Date = MyDateLib::InceraseDateByOneYear(Date);

	 }
	 return Date;
 }

 stDate InceraseDateByXYearsFaster(stDate Date, short YearsToAdd)
 {
	 Date.Year += YearsToAdd;
	 return Date;
 }

 stDate InceraseDateBtOneDecade(stDate Date)
 {
	 Date.Year += 10;
	 return Date;
 }

 stDate InceraseDateByXDecades(stDate Date, short DecadesToAdd)
 {
	 for (int i = 1; i <= DecadesToAdd * 10; i++)
	 {
		 Date = MyDateLib::InceraseDateByOneYear(Date);
	 }
	 return Date;
 }

 stDate InceraseDateByXDecadesFaster(stDate Date, short DecadesToAdd)
 {
	 Date.Year += DecadesToAdd * 10;
	 return Date;
 }

 stDate InceraseDateByOneCentury(stDate Date)
 {
	 Date.Year += 100;
	 return Date;
 }

 stDate InceraseDateByOneMillennium(stDate Date)
 {
	 Date.Year += 1000;
	 return Date;
 }


 

int main()
{
	stDate date, newDate;
	date = MyDateLib::ReadFullDate();

	printf("\nDate after adding:\n\n");

	newDate = MyDateLib::IncereaseDateByOneDay(date);
	printf("01 - Adding %d day is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::IncereaseDateByXDays(newDate, 10);
	printf("02 - Adding %d days is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByOneWeek(newDate);
	printf("03 - Adding %d week is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByXWeeks(newDate, 10);
	printf("04 - Adding %d weeks is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByOneMonth(newDate);
	printf("05 - Adding %d month is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByXMonths(newDate, 5);
	printf("06 - Adding %d months is: %d/%d/%d\n", 5, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByOneYear(newDate);
	printf("07 - Adding %d year is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByXYears(newDate, 10);
	printf("08 - Adding %d years is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByXYearsFaster(newDate, 10);
	printf("09 - Adding %d years(Faster) is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateBtOneDecade(newDate);
	printf("10 - Adding %d decade is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByXDecades(newDate, 10);
	printf("11 - Adding %d decades is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByXDecadesFaster(newDate, 10);
	printf("12 - Adding %d decades(Faster) is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByOneCentury(newDate);
	printf("13 - Adding %d century is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::InceraseDateByOneMillennium(newDate);
	printf("14 - Adding %d millennium is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);
	
  
}


