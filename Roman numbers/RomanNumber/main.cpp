// RomanNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"RomanNumber.h"

using namespace std;


int main()
{
    int num1 = 0, num2 = 0;
    string s;
    while(true) {
        cout << "Enter the string: ";
        getline(cin, s);
        if(s == "0" || s == "O")
            break;
        RomanNumber x;
        if (x.isValidDecimalNumber(s)) {
            x = RomanNumber(s);
            cout << s << " convert decimal to roman: " << x << endl;
            num1++;
        }
        else if (x.isValidRomanNumber(s)) {
            cout << s << " convert roman to decimal: " << x.convertRomanToDecimal(s) << endl;
            num1++;
        }
        else {
            cout << "Error!\n";
            num2++;
        }
        cout << endl;
    }
    cout << "There are " << num1 << " successful conversion cases\n";
    cout << "There are " << num2 << " exceptions that are ignored\n";
}
/*
2345
76
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
