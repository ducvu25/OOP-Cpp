#include <iostream>
#include "BigInteger.h"

using namespace std;

int main()
{
    BigInteger x, y;
    cin >> x >> y;
    cout << "The number 1: " << x << endl;
    cout << "The number 2: " << y << endl;
    if (x > y)
        cout << "The first number is larger than the second number\n";
    else
        cout << "The first number is smaller than or equal to the second number\n";

    cout << "The symmetry number of" << x << ": "<< - x << endl;
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    cout << x << " % " << y << " = " << x % y << endl;
    return 0;
}
/*
2345431234652413
76593535
*/