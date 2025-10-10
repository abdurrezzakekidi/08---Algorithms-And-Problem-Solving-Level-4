#include <iostream>
#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyInputsLib.h"

using namespace std;
using MyDateLib::stDate;

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!MyDateLib::IsDate1BeforeDate2(Date1, Date2) && !MyDateLib::IsDate1EqualDate2(Date1, Date2));

}

int main()
{
    cout << "\n Enter Date1:\n";
	stDate Date1 = MyDateLib::ReadFullDate();

	cout << "\n Enter Date2:\n";
	stDate Date2 = MyDateLib::ReadFullDate();

	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\n Yes, Date1 is after Date2";
	else
		cout << "\nNo, Date1 is NOT after Date2";

	system("pause");
	return 0;
    
}


