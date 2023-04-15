// Complex Numbers Demo
// John Goulden
// F1998 - 2020
// Yes it has improved with age
// OCU and OCCC

#include <iostream>
#include "./ComplexNumber.h"
using namespace std;

int main()
{

    ComplexNumber x;
    ComplexNumber y;
    cout << "Enter the complex number 1: ";
    cin >> x;
    cout << "Enter the complex number 2: ";
    cin >> y;
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    cout << endl;

    if (x >= y)
        cout << x << " >= " << y << endl;
    else
        cout << x << " < " << y << endl;

    if (x <= y)
        cout << x << " <= " << y << endl;
    else
        cout << x << " > " << y << endl;
    cout << endl;

    ComplexNumber z = x;
    x += y;
    cout << z << " += " << y << x << endl;
    x = z;

    x -= y;
    cout << z << " -= " << y << x << endl;
    x = z;

    x *= y;
    cout << z << " *= " << y << x << endl;
    x = z;

    x /= y;
    cout << z << " /= " << y << x << endl;
    x = z;

    return 0;
}