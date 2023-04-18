/*
 * Title:		List class method definition
 * Purpose:		ADT List implementation
 * Author:		Carlos Arias
 * Date:		April 29, 2020
 */

#include "list.h"
/**
 * Default Constructor
 * Just initializes the size to zero
 */
List::List() : _size(0){

}
/**
 * Destructor
 * It does not do anything, needs to be in the base
 * class to activate polymorphism
 */
List::~List(){

}
/**
 * Size accessor
 * @return the number of elements in the list
 */
size_t List::Size()const{
	return _size;
}
/**
 * Verifies if the list is empty or not, it is based on size.
 * @return true if the size is empty (size == 0), false otherwise
 */
bool List::IsEmpty()const{
	return _size == 0;
}
