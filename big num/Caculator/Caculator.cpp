// Caculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "BigInteger.h"
#include "RomanNumber.h"

using namespace std;

void Caculator(string s) {
    stack<BigInteger> a;
    string d = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 32 && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '%')
            d = d + s[i];
        else {
            switch (s[i]) {
            case ' ': {
                if (d == "")
                    break;
                RomanNumber value(d);
                a.push(BigInteger(int(value)));
                break;
            }
            case '+': {
                BigInteger c = a.top();
                a.pop();
                BigInteger d = a.top();
                a.pop();
                a.push(c + d);
                break;
            }
            case '-': {
                BigInteger c = a.top();
                a.pop();
                BigInteger d = a.top();
                a.pop();
                a.push(c - d);
                break;
            }
            case '*': {
                BigInteger c = a.top();
                a.pop();
                BigInteger d = a.top();
                a.pop();
                a.push(c * d);
                break;
            }
            case '/': {
                BigInteger c = a.top();
                a.pop();
                BigInteger d = a.top();
                a.pop();
                a.push(c / d);
                break;
            }
            case '%': {
                BigInteger c = a.top();
                a.pop();
                BigInteger d = a.top();
                a.pop();
                a.push(c % d);
                break;
            }
            }
            d = "";
        }
    }
    cout << a.top();
}
int main()
{
    cout << "Enter the string: ";
    string s;
    getline(cin, s);
    Caculator(s);
    return 0;
}
// IV V 4 + III 10 * - %
// (3*10 - (5 + 4)) % 4
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
