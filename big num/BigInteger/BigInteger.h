#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BigInteger
{
private:
    string theValue;
    bool theSign;
    // bool isValidBigInteger(string);

public:
    BigInteger();
    BigInteger(const int &n);
    BigInteger(const string &s);
    BigInteger(const BigInteger &x);

    operator string() const;
    friend istream &operator>>(istream &in, BigInteger &x);
    friend ostream &operator<<(ostream &out, BigInteger x);

    string toString();

    bool operator>(const BigInteger &x);
    bool operator==(const BigInteger &x);
    bool operator>=(const BigInteger &x);
    bool operator<(const BigInteger& x);
    bool operator<=(const BigInteger& x);
    BigInteger operator+(const BigInteger &x);
    BigInteger operator-(const BigInteger &x);
    BigInteger operator*(const int &x);
    BigInteger operator*(const BigInteger &x);
    BigInteger operator/(const BigInteger &x);
    BigInteger operator%(const BigInteger &x);

    BigInteger operator+=(const BigInteger &x);
    BigInteger operator-=(const BigInteger &x);
    BigInteger operator*=(const BigInteger &x);
    BigInteger operator/=(const BigInteger &x);
    BigInteger operator%=(const BigInteger &x);

    BigInteger operator++();
    BigInteger operator--();
    BigInteger operator-();
    BigInteger Reverse();
    void Standard();
};
