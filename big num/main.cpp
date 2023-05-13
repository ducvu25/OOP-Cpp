#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class BigInteger
{
public: // +, -, *, /, %
    string value;
    BigInteger()
    {
        value = "";
    }
    BigInteger(const BigInteger &a)
    {
        value = a.value;
    }
    friend istream &operator>>(istream &cin, BigInteger &x)
    {
        cin >> x.value;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, BigInteger x)
    {
        cout << x.value;
        return cout;
    }
    bool operator>(const BigInteger &x)
    {
        if (this->value[0] == '-' && x.value[0] != '-')
            return false;
        if (this->value[0] != '-' && x.value[0] == '-')
            return true;
        if (this->value[0] == '-' && x.value[0] == '-')
        {
            if (this->value.size() != x.value.size())
                return !(this->value.size() > x.value.size());
            return !(this->value > x.value);
        }
        if (this->value.size() != x.value.size())
            return this->value.size() > x.value.size();

        return this->value > x.value;
    }
    bool operator==(const BigInteger &x)
    {
        return this->value == x.value;
    }
    bool operator>=(const BigInteger &x)
    {
        return (this->value == x.value || *this > x);
    }
    BigInteger operator+(const BigInteger &x)
    {
        BigInteger a = *this;
        BigInteger b = x;
        if (this->value[0] == '-' && x.value[0] != '-')
        {
            a.value.erase(0, 1);
            return b - a;
        }
        if (this->value[0] != '-' && x.value[0] == '-')
        {
            b.value.erase(0, 1);
            return a - b;
        }
        if (this->value[0] == '-' && x.value[0] == '-')
        {
            a.value.erase(0, 1);
            b.value.erase(0, 1);
            return -(a + b);
        }
        if (a > b == false && !(a == b))
            return b + a;

        a = a.Reverse();
        b = b.Reverse();

        BigInteger c;
        int d = 0;
        for (int i = 0; i < a.value.size(); i++)
        {
            int di2 = i < b.value.size() ? b.value[i] - 48 : 0;
            int sum = a.value[i] - 48 + di2 + d;
            d = sum > 9 ? 1 : 0;
            c.value.push_back(sum % 10 + 48);
        }
        if (d > 0)
            c.value.push_back(d + 48);
        return c.Reverse();
    }
    BigInteger operator-(const BigInteger &x)
    {
        BigInteger a = *this;
        BigInteger b = x;
        if (this->value[0] == '-' && x.value[0] != '-')
        {
            a.value.erase(0, 1);
            return -(a + b);
        }
        if (this->value[0] != '-' && x.value[0] == '-')
        {
            b.value.erase(0, 1);
            return a + b;
        }
        if (this->value[0] == '-' && x.value[0] == '-')
        {
            a.value.erase(0, 1);
            b.value.erase(0, 1);
            return b - a;
        }
        if (a == b)
        {
            a.value = "0";
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
        for (int i = 0; i < b.value.size(); i++)
        {
            c.value[i] -= b.value[i] - 48;
            int j = i;
            while (c.value[j] < '0')
            {
                c.value[j] += 10;
                if (j + 1 < c.value.size())
                {
                    c.value[j + 1] -= 1;
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
        while (c.value[0] == '0')
            c.value.erase(0, 1);
        if (d == -1)
            c.value = "-" + c.value;
        return c;
    }
    BigInteger operator*(const int &x)
    {
        BigInteger a = *this;
        if (this->value.size() == 0 || x == 0 || a.value[0] == '0')
        {
            a.value = "0";
            return a;
        }
        if (this->value[0] == '-')
        {
            a.value.erase(0, 1);
            return -(a * x);
        }
        a = a.Reverse();

        BigInteger c;
        int d = 0;
        for (int i = 0; i < a.value.size(); i++)
        {
            int di = a.value[i] - 48;
            int sum = di * x + d;
            d = sum > 9 ? sum / 10 : 0;
            c.value.push_back(sum % 10 + 48);
        }
        if (d > 0)
            c.value.push_back(d + 48);
        c = c.Reverse();
        return c;
    }
    BigInteger operator*(const BigInteger &x)
    {
        BigInteger a = *this;
        BigInteger b = x;
        if (this->value[0] == '-' && x.value[0] != '-')
        {
            a.value.erase(0, 1);
            return -(a * b);
        }
        if (this->value[0] != '-' && x.value[0] == '-')
        {
            b.value.erase(0, 1);
            return -(a * b);
        }
        if (this->value[0] == '-' && x.value[0] == '-')
        {
            a.value.erase(0, 1);
            b.value.erase(0, 1);
            return a * b;
        }
        if (a > b == false && !(a == b))
            return b * a;
        b = b.Reverse();
        BigInteger c;
        int d = 0;
        for (int i = 0; i < b.value.size(); i++)
        {
            BigInteger y = a * (b.value[i] - 48);
            for (int j = 0; j < d; j++)
                y.value.push_back('0');
            d++;
            c = c + y;
        }
        return c;
    }
    BigInteger operator/(const BigInteger &x)
    {
        BigInteger c, a = *this, b = x, d;
        c.value = "0";
        d.value = "1";
        if (x.value == "0")
        {
            c.value = "Error";
            return c;
        }
        if (x.value == "1")
            return *this;
        while (a >= b)
        {
            a = a - b;
            c = c + d;
        }
        return c;
    }
    BigInteger operator%(const BigInteger &x)
    {
        BigInteger c, a = *this;
        c = a / x;
        return a - c;
    }
    BigInteger operator-()
    {
        BigInteger a;
        if (this->value[0] != '-')
            a.value = "-" + this->value;
        else
            a.value = this->value.substr(1);
        return a;
    }
    BigInteger Reverse()
    {
        // if (this->value.size() == 1)
        //     return *this;
        BigInteger a;
        int index = 0;
        if (this->value[0] == '-')
        {
            index = 1;
        }
        for (int i = this->value.size() - 1; i >= index; i--)
        {
            a.value.push_back(this->value[i]);
            // cout << a;
        }
        if (index == 1)
            return -a;
        return a;
    }
    void Standard()
    {
        while (this->value[0] == '0' && this->value.size() > 1)
            this->value = this->value.substr(1);
    }
};
void Quiz(string s)
{
    ifstream in(s.c_str());
    int n = 0;
    vector<BigInteger> a;
    BigInteger x;
    BigInteger sum;
    while (in >> x)
    {
        n++;
        a.push_back(x);
        sum = sum + x;
    }
    cout << sum << endl
         << endl;
    cout << sum * a[0] << endl
         << endl;
    cout << sum * a[a.size() - 1] << endl
         << endl;
    cout << a.size();
}
int main()
{

    BigInteger a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == b && a.value == "0")
            return 0;
        cout << a / b << endl;
    }
    // Quiz("input.txt");
    return 0;
}