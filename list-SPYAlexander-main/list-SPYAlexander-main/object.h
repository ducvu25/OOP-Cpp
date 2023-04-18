/*
 * Title:		General Object
 * Purpose:		Declaration of a general base class
 * Author:		Carlos Arias
 * Date:		April 29, 2020
 */
#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using std::string;

class Object{

public:
	Object();
	virtual ~Object();
	virtual string ToString()const;
	virtual bool Equals(const Object& rhs)const;
	virtual Object* Clone()const;
};

#endif
