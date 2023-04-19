/*
 * Title:		Integer wrapper Class
 * Purpose:		A subclass of Object and Comparable to wrap up an integer and enable CompareTo
 * Author:		Carlos Arias
 * Date:		April 29, 2020
 */
#ifndef INTEGER_H
#define INTEGER_H

#include "comparable.h"

#include <string>
using std::string;

class Integer : public Comparable{
		int _value;
	public:
		Integer(int = 0);
		virtual string ToString()const;
		int GetValue()const;
		void SetValue(int);
		virtual bool Equals(const Object& rhs)const;
		virtual Object* Clone()const;
        virtual int CompareTo(const Comparable* rhs)const;
};

#endif /* end of include guard: INTEGER_H */
