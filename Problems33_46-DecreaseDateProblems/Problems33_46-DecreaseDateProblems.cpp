#include <iostream>
#include "D://MyCPP_Libs/MyInputsLib.h"
#include "D://MyCPP_Libs/MyDateUtility.h"

using namespace std;
using MyDateLib::stDate;

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = MyDateLib::NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
        
    return Date;
}

stDate DecreaseDateByXDays(stDate Date, short DaysToSubtract)
{
    for (short i = 1; i <= DaysToSubtract; i++)
        Date = MyDateLib:: DecreaseDateByOneDay(Date);
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    return MyDateLib::DecreaseDateByXDays(Date, 7);
}

stDate DecreaseDateByXWeeks(stDate Date, short WeeksToSubtract)
{
    for (int i = 1; i <= WeeksToSubtract; i++)
    {
        Date = MyDateLib::DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    // last check day in date should not exeed max days in the current month 
	// example 31/3/2023 - 1 month = 31/2/2023 (not valid date) so we will convert it to 28/2/2023
    short NumberOfDaysInCurrentMonth =
        MyDateLib::NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short MonthsToSubtract)
{
    for (int i = 1; i <= MonthsToSubtract; i++)
    {
        Date = MyDateLib::DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, short YearsToSubtract)
{
    for (int i = 1; i <= YearsToSubtract; i++)
    {
        Date = MyDateLib::DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short YearsToSubtract)
{
    Date.Year -= YearsToSubtract;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, short DecadesToSubtract)
{
    for (int i = 1; i <= DecadesToSubtract * 10; i++)
    {
        Date = MyDateLib::DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short DecadesToSubtract)
{
    Date.Year -= DecadesToSubtract * 10;
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    stDate date, newDate;
    date = MyDateLib::ReadFullDate();

    printf("\nDate after subtracting:\n\n");

    newDate = MyDateLib::DecreaseDateByOneDay(date);
    printf("01 - Subtracting %d day is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByXDays(newDate, 10);
    printf("02 - Subtracting %d days is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByOneWeek(newDate);
    printf("03 - Subtracting %d week is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByXWeeks(newDate, 10);
    printf("04 - Subtracting %d weeks is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::DecreaseDateByOneMonth(newDate);
	printf("05 - Subtracting %d month is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::DecreaseDateByXMonths(newDate, 5);
	printf("06 - Subtracting %d months is: %d/%d/%d\n", 5, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::DecreaseDateByOneYear(newDate);
	printf("07 - Subtracting %d year is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::DecreaseDateByXYears(newDate, 10);
	printf("08 - Subtracting %d years is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::DecreaseDateByXYearsFaster(newDate, 10);
	printf("09 - Subtracting %d years (faster) is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

	newDate = MyDateLib::DecreaseDateByOneDecade(newDate);
	printf("10 - Subtracting %d decade is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByXDecades(newDate,10);
    printf("10 - Subtracting %d decades is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByXDecadesFaster(newDate, 10);
    printf("10 - Subtracting %d decades(Faster) is: %d/%d/%d\n", 10, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByOneCentury(newDate);
    printf("10 - Subtracting %d century is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);

    newDate = MyDateLib::DecreaseDateByOneMillennium(newDate);
    printf("10 - Subtracting %d millennium is: %d/%d/%d\n", 1, newDate.Day, newDate.Month, newDate.Year);


	system("pause>0");
	return 0;

    
}


