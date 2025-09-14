#include <iostream>
#include <string>
#include "D://MyCPP_Libs/MyInputsLib.h"

using namespace std;

string NumberToText(int number)
{
    if (number == 0)
    {
        return "";
    }
    if (number >= 1 && number <= 19)
    {
        const string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six",
                              "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                              "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

        return arr[number] + " ";
    }
    if (number >= 20 && number <= 99)
    {
        const string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
                              "Sixty", "Seventy", "Eighty", "Ninety" };

        return arr[number / 10] + " " + NumberToText(number % 10);
    }
    if (number >= 100 && number <= 199)
    {
        return "One Hundred " + NumberToText(number % 100);
    }
    if (number >= 200 && number <= 999)
    {
        return NumberToText(number / 100) + "Hundred " + NumberToText(number % 100);
    }
    if (number >= 1000 && number <= 1999)
    {
        return "One Thousand " + NumberToText(number % 1000);
    }
    if (number >= 2000 && number <= 999999)
    {
        return NumberToText(number / 1000) + "Thousand " + NumberToText(number % 1000);
    }
    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + NumberToText(number % 1000000);
    }
    if (number >= 2000000 && number <= 999999999)
    {
        return NumberToText(number / 1000000) + "Million " + NumberToText(number % 1000000);
    }
    if (number >= 1000000000 && number <= 1999999999)
    {
        return "One Billion " + NumberToText(number % 1000000000);
    }
    else
    {
        return NumberToText(number / 1000000000) + "Billion " + NumberToText(number % 1000000000);
    }
}

int main()
{
    int number = MyInputLib::ReadInvalidNumber();

    cout << NumberToText(number) << endl;

    return 0;
}
