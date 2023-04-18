/*
 * Title:		Comparable
 * Purpose:		Declaration of a class to enable comparison between objects
 * Author:		Carlos Arias
 * Date:		April 4, 2023
 */
#ifndef COMPARABLE_H
#define COMPARABLE_H

#include "object.h"

class Comparable : public Object{
public:
    /**
     * This method compares two Comparable objects. It works like
     * strcmp or the method string::compare
     * This method is virtual pure, it must be implemented by Comparable's
     * derived classes.
     * @param rhs The object that this is being compared to
     * @return if this is equal to rhs it returns 0.
     *         if this < rhs returns a negative number.
     *         if this > rhs returns a positive number.
     */
    virtual int CompareTo(const Comparable* rhs)const = 0;
    virtual string ToString()const;
};


#endif //AST_LIST_SOLUTION_COMPARABLE_H
