#include <iostream>
#include <string>
#include <vector>
#include "D://MyCPP_Libs/MyDateUtility.h"
#include "D://MyCPP_Libs/MyStringUtility.h"


using namespace std;
using MyDateLib::stDate;

string DateToString(stDate Date)
{
    return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
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
    cout << "\nDay:" << Date.Day << endl; 
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year << endl;

    cout << "\nYou Entered: " << DateToString(Date) << "\n";
    
    system("pause>0");
    return 0;
  
}


