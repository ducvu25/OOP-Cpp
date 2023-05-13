#include"RomanNumber.h"

using namespace std;

bool RomanNumber::isValidDecimalNumber(string s) {
	int n = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!(s[i] >= '0' && s[i] <= '9' || (s[i] == '.' && n == 0)))
			return false;
		if (s[i] == '.')
			n++;
	}
	return true;
}
bool RomanNumber::isValidRomanNumber(string s) {
	for (int i = 0; i < s.size(); i++)
		if (!(s[i] == 'I' || s[i] == 'V' || s[i] == 'X' || s[i] == 'L' || s[i] == 'C' || s[i] == 'D' || s[i] == 'M'))
			return false;
	return true;
}
string RomanNumber:: convertRomanToDecimal(string s) {
	string ss = s;
	int values[] = { 1000,  900,  500,  400,  100,   90,   50,   40,   10,    9,    5,    4,    1 };
	string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int n = 0;
	for (int i = 0; i < 13; i++) {
		int value = 0;
		while (ss.size() >= symbols[i].size() && ss.find(symbols[i]) == 0) {
			value++;
			ss.erase(0, symbols[i].size());
		}
		if (value != 0)
			n += values[i]*value;
	}
	return to_string(n);
}