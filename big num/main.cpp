#include <iostream>
#include <string>

using namespace std;

class BigInteger
{
public:
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
        BigInteger c = a;
        // cout << c << endl;
        int d;
        for (int i = 0; i < b.value.size(); i++)
        {
            c.value[i] += b.value[i] - 48;
            int j = i;
            while (c.value[j] > '9')
            {
                c.value[j] -= 10;
                if (j + 1 < c.value.size())
                {
                    c.value[j + 1] += 1;
                    j++;
                }
                else
                {
                    c.value.push_back('1');
                }
            }
        }
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
        c.value = "0";
        // c.value.push_back((a.value[0] - 48) * x + 48);
        for (int i = 0; i < a.value.size(); i++)
        {
            c.value[i] += (a.value[i] - 48) * x;
            if (c.value[i] > '9')
            {
                int d = (c.value[i] - 48) / 10;
                // cout << d << endl;
                c.value[i] = (c.value[i] - 48) % 10 + 48;
                if (i + 1 < c.value.size())
                    c.value[i + 1] += d;
                else
                    c.value.push_back(d + 48);
            }
            else
                c.value.push_back(48);
            // cout << c << endl;
        }
        // if(c)
        c = c.Reverse();
        while (c.value[0] == '0')
            c.value.erase(0, 1);
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
            // cout << c << " " << y << endl;
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
            // cout << a << " " << b << endl;
            a = a - b;
            c = c + d;
            // cout << a << " " << b << " " << c << endl
            //      << endl;
            // system("pause");
        }
        return c;
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
    // cin >> a >> b;
    // cout << a << " + " << b << " = " << a + b << endl;
    // cout << a << " - " << b << " = " << a - b << endl;
    // // cout << a * 2;
    // cout << a << " * " << b << " = " << a * b << endl;
    // cout << a << " / " << b << " = " << a / b << endl;
    return 0;
}