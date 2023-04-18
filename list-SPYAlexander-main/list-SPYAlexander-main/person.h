/*
 * Title:		Person class
 * Purpose:		Declaration of a class to represent a basic person
 * 				it has two members name and age. Name is a dynamically
 * 				allocated c-string
 * Author:		Carlos Arias
 * Date:		April 29, 2020
 */
#ifndef PERSON_H
#define PERSON_H

#include "comparable.h"
#include <string>
using std::string;

class Person : public Comparable{
		char* _name;
		size_t _age;
	public:
		Person(const string& name, size_t age);
		Person(const Person& person);
		const Person& operator=(const Person& rhs);
		virtual ~Person();
		virtual string ToString()const;
		virtual bool Equals(const Object& rhs)const;
		virtual Object* Clone()const;
		void Birthday();
        virtual int CompareTo(const Comparable* rhs)const;
};

#endif /* end of include guard: PERSON */
