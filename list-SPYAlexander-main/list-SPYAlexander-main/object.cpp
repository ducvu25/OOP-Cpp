/*
 * Title:		General Object
 * Purpose:		Definition of methods of a general base class
 * Author:		Carlos Arias
 * Date:		April 29, 2020
 */
#include "object.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;
/**
 * Default Constructor
 * Does not do anything
 */
Object::Object(){

}
/**
 * Destructor
 * Does not do anything
 */
Object::~Object(){

}
/**
 * ToString
 * Creates a string representation of a general object. The string representation
 * will be "Object @ 0x123456789abc" indicating the memory address of *this
 * (the value of this)
 * @return a string representation of an object
 */
string Object::ToString()const{
	stringstream retVal;
	retVal << "Object @ " << this;
	return retVal.str();
}
/**
 * Verifies if two objects are equal.
 * At this level there is nothing to compare but to check if the two
 * objects are in fact the same object. This is achieved by comparing
 * the memory addresses.
 * @param rhs the object that we are comparing with this
 * @return true if the two objects are in the same memory address
 */
bool Object::Equals(const Object& rhs)const{
	if (this == &rhs){
		return true;
	}else{
		return false;
	}
}
/**
 * Creates a clone of the object.
 * In certain situations it is not possible to explicitly call the
 * copy constructor to create a copy, this method allows for
 * sub-classes of object to create deep copies explicitly
 * @return a deep copy of the object
 */
Object* Object::Clone()const{
	return new Object();
}
