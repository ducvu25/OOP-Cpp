#include "BigInteger.h"

BigInteger ::BigInteger()
{
    this->theValue = "0";
    this->theSign = true;
}

BigInteger ::BigInteger(const int &n)
{
    if (n == 0)
    {
        this->theValue = "";
        this->theSign = true;
        return;
    }
    if (n < 0)
        this->theSign = false;
    else
        this->theSign = true;

    this->theValue = "";
    int m = n;
    while (m != 0)
    {
        char c = m % 10 + 48;
        this->theValue = c + this->theValue;
        m /= 10;
    }
}
BigInteger ::BigInteger(const string &s)
{
    if (s[0] != '-')
    {
        this->theSign = true;
        this->theValue = s;
    }
    else
    {
        this->theSign = false;
        this->theValue = s.substr(1);
    }
}
BigInteger ::BigInteger(const BigInteger &x)
{
    this->theSign = x.theSign;
    this->theValue = x.theValue;
}
BigInteger::operator string() const
{
    if (theValue == "Error")
        return theValue;
    return (this->theSign ? "" : "-") + this->theValue;
}
istream &operator>>(istream &in, BigInteger &x)
{
    string s;
    in >> s;
    x = BigInteger(s);
    return in;
}
ostream &operator<<(ostream &out, BigInteger x)
{
    out << x.toString();
    return out;
}

string BigInteger::toString()
{
    return (this->theSign ? "" : "-") + this->theValue;
}
bool BigInteger::operator>(const BigInteger &x)
{
    if (!this->theSign && x.theSign)
        return false;
    if (this->theSign && !x.theSign)
        return true;
    if (this->theSign == false && x.theSign == false)
    {
        if (this->theValue.size() != x.theValue.size())
            return !(this->theValue.size() > x.theValue.size());
        return !(this->theValue > x.theValue);
    }
    if (this->theValue.size() != x.theValue.size())
        return this->theValue.size() > x.theValue.size();

    return this->theValue > x.theValue;
}
bool BigInteger::operator<(const BigInteger& x) {
    return !(*this >= x);
}
bool BigInteger::operator<=(const BigInteger& x) {
    return !(*this > x);
}
bool BigInteger::operator==(const BigInteger &x)
{
    return this->theValue == x.theValue;
}
bool BigInteger::operator>=(const BigInteger &x)
{
    return (this->theValue == x.theValue || *this > x);
}
BigInteger BigInteger::operator+(const BigInteger &x)
{
    BigInteger a = *this;
    BigInteger b = x;
    // cout << a << " " << b << endl;
    if (this->theSign == false && x.theSign)
    {
        a.theSign = true;
        return b - a;
    }
    if (this->theSign && x.theSign == false)
    {
        b.theSign = true;
        return a - b;
    }
    if (this->theSign == false && x.theSign == false)
    {
        a.theSign = true;
        b.theSign = true;
        return -(a + b);
    }
    if (a > b == false && !(a == b))
        return b + a;

    a = a.Reverse();
    b = b.Reverse();
    // cout << a << " " << b;
    string c = "";
    int d = 0;
    for (int i = 0; i < a.theValue.size(); i++)
    {
        int di2 = i < b.theValue.size() ? b.theValue[i] - 48 : 0;
        int sum = a.theValue[i] - 48 + di2 + d;
        d = sum > 9 ? 1 : 0;
        c.push_back(sum % 10 + 48);
    }
    if (d > 0)
        c.push_back(d + 48);
    return BigInteger(c).Reverse();
}
BigInteger BigInteger::operator-(const BigInteger &x)
{
    BigInteger a = *this;
    BigInteger b = x;
    if (this->theSign == false && x.theSign)
    {
        a.theSign = true;
        return -(a + b);
    }
    if (this->theSign && x.theSign == false)
    {
        b.theSign = true;
        return a + b;
    }
    if (this->theSign == false && x.theSign == false)
    {
        a.theSign = true;
        b.theSign = true;
        return b - a;
    }
    if (a == b)
    {
        a.theValue = "0";
        a.theSign = true;
        return a;
    }
    if (a > b == false)
        return -(b - a);

    a = a.Reverse();
    b = b.Reverse();
    // cout << a << " " << b << endl;
    BigInteger c = a;
    // cout << c << endl;
    int d = 1;
    for (int i = 0; i < b.theValue.size(); i++)
    {
        c.theValue[i] -= b.theValue[i] - 48;
        int j = i;
        while (c.theValue[j] < '0')
        {
            c.theValue[j] += 10;
            if (j + 1 < c.theValue.size())
            {
                c.theValue[j + 1] -= 1;
                j++;
            }
            else
            {
                d = -1;
            }
        }
        // cout << c << endl;
    }
    c = c.Reverse();
    while (c.theValue[0] == '0')
        c.theValue.erase(0, 1);
    if (d == -1)
    {
        c.theSign = false;
    }
    return c;
}
BigInteger BigInteger::operator*(const int &x)
{
    BigInteger a = *this;
    if (this->theValue.size() == 0 || x == 0 || a.theValue == "0")
    {
        a.theValue = "0";
        return a;
    }
    if (this->theSign == false)
    {
        a.theSign = true;
        return -(a * x);
    }
    a = a.Reverse();

    string c = "";
    int d = 0;
    for (int i = 0; i < a.theValue.size(); i++)
    {
        int di = a.theValue[i] - 48;
        int sum = di * x + d;
        d = sum > 9 ? sum / 10 : 0;
        c.push_back(sum % 10 + 48);
    }
    if (d > 0)
        c.push_back(d + 48);
    return BigInteger(c).Reverse();
}
BigInteger BigInteger::operator*(const BigInteger &x)
{
    BigInteger a = *this;
    BigInteger b = x;
    if (this->theSign == false && x.theSign)
    {
        a.theSign = true;
        return -(a * b);
    }
    if (this->theSign && x.theSign == false)
    {
        b.theSign = true;
        return -(a * b);
    }
    if (this->theSign == false && x.theSign == false)
    {
        a.theSign = true;
        b.theSign = true;
        return a * b;
    }
    if (a > b == false && !(a == b))
        return b * a;
    b = b.Reverse();
    BigInteger c;
    int d = 0;
    for (int i = 0; i < b.theValue.size(); i++)
    {
        BigInteger y = a * (b.theValue[i] - 48);
        for (int j = 0; j < d; j++)
            y.theValue.push_back('0');
        d++;
        c = c + y;
    }
    return c;
}
BigInteger BigInteger::operator/(const BigInteger &x)
{
    BigInteger a(*this);
    BigInteger b(x);
    if (x.theValue == "0")
    {
        return BigInteger("Error");
    }
    if (x.theValue == "1")
        return *this;
    if (this->theSign == false && x.theSign)
    {
        a.theSign = true;
        return -(a / b);
    }
    if (this->theSign && x.theSign == false)
    {
        b.theSign = true;
        return -(a / b);
    }
    if (this->theSign == false && x.theSign == false)
    {
        a.theSign = true;
        b.theSign = true;
        return a / b;
    }
    string z = a.theValue.substr(0, b.theValue.size() - 1);
   // cout << z << endl;
    string result = "";
    for (int i = b.theValue.size() - 1; i < a.theValue.size(); i++) {
        z += a.theValue[i];
        //cout << z << " " << b;
        BigInteger d(z);
        BigInteger c("0");
        while (d >= b)
        {
            d = d - b;
            c = c + BigInteger("1");
            /*cout << d << " " << c << endl;
            system("pause");*/
        }
       // cout << " " << c << endl;
        z = d.theValue;
        result += c.theValue;
   }
    BigInteger results(result);
    results.Standard();
    return results;
}
BigInteger BigInteger::operator%(const BigInteger &x)
{
    if (x.theSign == false || this->theSign== false)
    {
        return BigInteger("Error");
    }
    BigInteger c, a = *this;
    c = a / x;
    return a - c*x;
}
BigInteger BigInteger::operator-()
{
    BigInteger a(*this);
    if(a.theValue != "0")
        a.theSign = !this->theSign;
    return a;
}
BigInteger BigInteger::operator+=(const BigInteger &x)
{
    BigInteger a(*this);
    return a + x;
}
BigInteger BigInteger::operator-=(const BigInteger &x)
{
    BigInteger a(*this);
    return a - x;
}
BigInteger BigInteger::operator*=(const BigInteger &x)
{
    BigInteger a(*this);
    return a * x;
}
BigInteger BigInteger::operator/=(const BigInteger &x)
{
    BigInteger a(*this);
    return a / x;
}
BigInteger BigInteger::operator%=(const BigInteger &x)
{
    BigInteger a(*this);
    return a % x;
}
BigInteger BigInteger::operator++()
{
    BigInteger a(*this);
    BigInteger b("1");
    return a + b;
}
BigInteger BigInteger::operator--()
{
    BigInteger a(*this);
    BigInteger b("1");
    return a - b;
}
BigInteger BigInteger::Reverse()
{
    string s = "";
    for (int i = this->theValue.size() - 1; i >= 0; i--)
    {
        s += this->theValue[i];
    }
    return BigInteger(s);
}
void BigInteger::Standard()
{
    while (this->theValue[0] == '0' && this->theValue.size() > 1)
        this->theValue = this->theValue.substr(1);
    if (this->theValue.size() == 0)
        this->theValue = "0";
}