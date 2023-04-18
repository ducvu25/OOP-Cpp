/*
 * Title:		Person Class
 * Purpose:		Definition of the methods of the Person class
 * Author:		Carlos Arias
 * Date:		April 29, 2020
 */
#include "person.h"

#include <cstring>
#include <string>
#include <sstream>
#include <cassert>
using std::string;
using std::stringstream;
/**
 * Constructor
 * Creates a person using the values of the parameters.
 * @param name the name of the person as a string
 * @param age the age of the person
 */
Person::Person(const string& name, size_t age) : _age(age){
	_name = new char[name.length() + 1];
	strcpy(_name, name.c_str());
}
/**
 * Copy constructor
 * Creates a deep copy of the person. The person uses dynamic memory
 * for the name, so it is required to have a copy constructor
 * @param person the original person being copied
 */
Person::Person(const Person& person) : _age(person._age){
	_name = new char[strlen(person._name) + 1];
	strcpy(_name, person._name);
}
/**
 * Copy Assignment Operator
 * Allows the deep assignment of two persons. Required, see Copy Constructor
 * @param rhs the person to be copied into this
 * @return this to follow chain assignment standard
 */
const Person& Person::operator=(const Person& rhs){
	if (strlen(_name) != strlen(rhs._name)){
		delete[] _name;
		_name = new char[strlen(rhs._name) + 1];
	}
    _age = rhs._age;
	strcpy(_name, rhs._name);
	return *this;
}
/**
 * Destructor
 * Releases the memory used by the name
 */
Person::~Person(){
	delete[] _name;
}
/**
 * Creates a string representation of a person.
 * The string representation is in JSON format
 * @return a string representing the person
 */
string Person::ToString()const{
	stringstream retVal;
	retVal << "Person: {name: " << _name << ", age: " << _age << "}";
	return retVal.str();
}
/**
 * Compares two persons.
 * Follows these steps:
 * 1. Checks if the two objects are the same
 * 2. Checks if rhs is actually a person
 * 3. Casts rhs and compares if the two have the same name and age
 * @param rhs the person to compare to
 * @return true if the two person have the same name and age, false otherwise
 */
bool Person::Equals(const Object& rhs)const{
	if (this == &rhs){
		return true;
	}
	const Person* rhsPtr = dynamic_cast<const Person*>(&rhs);
	if (rhsPtr == nullptr){
		return false;
	}
	return strcmp(rhsPtr->_name, _name) == 0 && rhsPtr->_age == _age;

}
/**
 * Explicitly creates a deep copy of this
 * @return a new copy of this
 */
Object* Person::Clone()const{
	return new Person(*this);
}
/**
 * Increases the age of the person by 1
 */
void Person::Birthday(){
	_age++;
}
/**
 * Compares two Persons. The method checks if rhs is an actual
 * reference to an Person, it will assert false otherwise.
 * Note that the return value is zero if the this and rhs are holding
 * the same person's name, negative if this->_name is less than p->_name,
 * and positive otherwise. It takes advantage of the function strcmp to
 * compare to c-strings.
     * @param rhs The object that this is being compared to
     * @return if this->_name is equal to p->_name it returns 0.
     *         if this->_name < p->_name returns a negative number.
     *         if this->_name > p->_name returns a positive number.
 */
int Person::CompareTo(const Comparable* rhs)const {
    const Person* p = dynamic_cast<const Person*>(rhs);
    assert(p != nullptr);
    return strcmp(_name, p->_name);
}
