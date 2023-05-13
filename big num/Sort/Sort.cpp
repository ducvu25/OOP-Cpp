// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BigInteger.h"
#include "RomanNumber.h"

using namespace std;

string NameOutput(string s)
{
    string name = s;
    name.insert(name.find("."), "_sorted");
    return name;
}
string* Input(string s, int& n)
{
    ifstream in(s.c_str());
    in >> n;
    string* a = new string[n];
    for (int i = 0; i < n; i++)
        in >> a[i];
    in.close();
    return a;
}
void Output(string s, string* a, int n)
{
    ofstream out(s.c_str());
    for (int i = 0; i < n; i++)
        out << a[i] << endl;
    out.close();
}
void Swap(string& x, string& y)
{
    string t = x;
    x = y;
    y = t;
}
void QuickSort(string* a, int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        bool check = true;
        RomanNumber roman;
        while (i < j)
        {
            string x = a[i];
            string y = a[j];
            if ((roman.isValidDecimalNumber(y) && roman.isValidDecimalNumber(x) && BigInteger(y) > BigInteger(x))
                || (roman.isValidRomanNumber(y) && roman.isValidRomanNumber(x) && BigInteger(roman.convertRomanToDecimal(y)) > BigInteger(roman.convertRomanToDecimal(x)))
                || (roman.isValidDecimalNumber(y) && roman.isValidRomanNumber(x) && BigInteger(y) > BigInteger(roman.convertRomanToDecimal(x)))
                || (roman.isValidRomanNumber(y) && roman.isValidDecimalNumber(x) && BigInteger(roman.convertRomanToDecimal(y)) > BigInteger(x)))
            {
                Swap(a[i], a[j]);
                if (check == true)
                    i++;
                else
                    j--;
                check = !check;
            }
            else
            {
                if (check == true)
                    j--;
                else
                    i++;
            }
        }
        // Print(a, 10);
        // cout << i << " " << j << endl;
        // system("pause");
        QuickSort(a, left, i - 1);
        QuickSort(a, i + 1, right);
    }
}
int main()
{
    int n;
    string s;
    cout << "Enter file input: ";
    getline(cin, s);
    string* a = Input(s, n);
    QuickSort(a, 0, n - 1);
    cout << "Name file output: " << NameOutput(s);
    Output(NameOutput(s), a, n);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
