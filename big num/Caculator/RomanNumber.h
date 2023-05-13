#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class RomanNumber {
private:
	int value;
public:
	int GetValue() { return this->value; }
	const int maxValue = 9999;
	bool isValidDecimalNumber(string s);
	bool isValidRomanNumber(string s);
	string convertRomanToDecimal(string s);

	RomanNumber() {
		this->value = 1;
	}
	RomanNumber(const int &x) {
		this->value = x;
	}
	RomanNumber(const double &x) {
		int d = x;
		RomanNumber a(d);
		this->value = a.value;
	}
	RomanNumber(const string &s) {
		this->value = 0;
		if (this->isValidDecimalNumber(s)) {
			int d = 0;
			for (int i = 0; i < s.size() && s[i] != '.'; i++)
				d = d * 10 + s[i] - 48;
				this->value = d;
		}
		else if (this->isValidRomanNumber(s)) {
			string ss = this->convertRomanToDecimal(s);
			RomanNumber a(ss);
			this->value = a.value;
		}
		else {
			cout << "Error!\n";
		}
	}
	RomanNumber(const RomanNumber& x) {
		this->value = x.value;
	}
	operator int() const {
		return this->value;
	}
	operator double() const {
		return this->value;
	}
	operator string() const {
		return this->toString();
	}
	string toString() const{
		string roman = "";
		if (this->value > this->maxValue)
			roman = "The value is larger than the max value";
		else if (this->value == 0) {
			roman = "The value is zero";
		}
		else if (this->value < 0) {
			roman = "The value is smaller than zero";
		}
		else{
			int values[] = { 1000,  900,  500,  400,  100,   90,   50,   40,   10,    9,    5,    4,    1 };
			string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
			int n = this->value;
			for (int i = 0; i < 13; i++) {
				while (n >= values[i]) {
					roman = roman + symbols[i];
					n -= values[i];
				}
			}
		}
		return roman;
	}
	RomanNumber& operator=(const RomanNumber& other) {
		if (this != &other) {
			this->value = other.value;
		}
		return *this;
	}
	friend istream& operator>>(istream& in, RomanNumber& x) {
		string s;
		in >> s;
		x = RomanNumber(s);
		return in;
	}
	friend ostream& operator<<(ostream& out, RomanNumber x) {
		out << x.toString();
		return out;
	}
	RomanNumber operator+(const RomanNumber& x) {
		return RomanNumber(this->value + x.value);
	}
	RomanNumber operator-(const RomanNumber& x) {
		return RomanNumber(this->value - x.value);
	}
	RomanNumber operator*(const RomanNumber& x) {
		return RomanNumber(this->value * x.value);
	}
	RomanNumber operator/(const RomanNumber& x) {
		return RomanNumber(this->value / x.value);
	}
	RomanNumber operator%(const RomanNumber& x) {
		return RomanNumber(this->value % x.value);
	}
	RomanNumber operator+=(const RomanNumber& x) {
		this->value += x.value;
		return *this;
	}
	RomanNumber operator-=(const RomanNumber& x) {
		this->value -= x.value;
		return *this;
	}
	RomanNumber operator*=(const RomanNumber& x) {
		this->value *= x.value;
		return *this;
	}
	RomanNumber operator/=(const RomanNumber& x) {
		this->value /= x.value;
		return *this;
	}
	RomanNumber operator%=(const RomanNumber& x) {
		this->value %= x.value;
		return *this;
	}
	bool operator>(const RomanNumber& x) {
		return this->value > x.value;
	}
	bool operator>=(const RomanNumber& x) {
		return this->value >= x.value;
	}
	bool operator==(const RomanNumber& x) {
		return this->value == x.value;
	}
	bool operator<(const RomanNumber& x) {
		return this->value < x.value;
	}
	bool operator<=(const RomanNumber& x) {
		return this->value <= x.value;
	}

};