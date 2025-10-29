#include <iostream>
#include <string>
#include <vector>
#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyStringUtility.h"


using namespace std;
using MyDateLib::stDate;

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    } 
    return S1;
}

string DateToString(stDate Date)
{
    return  to_string(Date.Day) +"/"+ to_string(Date.Month) +"/"+ to_string(Date.Year);
}

stDate StringToDate(string DateString)
{ 
    stDate Date;
    vector <string> vDate;
    vDate =MyStringLib::SplitString(DateString, "/"); 
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);  
    Date.Year = stoi(vDate[2]);
    return Date;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{ 
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day)); 
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month)); 
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return  FormattedDateString;
} 

string ReadStringDate(string Message) 
{ 
    string DateString;  
    cout << Message;   
    getline(cin >> ws, DateString);
    return DateString;
} 
int main() 
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    stDate Date = StringToDate(DateString);

    cout << "\n" << MyDateLib:: FormateDate(Date) << "\n";
    cout << "\n" << MyDateLib:: FormateDate(Date, "yyyy/dd/mm") << "\n"; 
    cout << "\n" << MyDateLib:: FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << MyDateLib:: FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << MyDateLib:: FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << MyDateLib::FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

	system("pause>0");
	return 0;
}



