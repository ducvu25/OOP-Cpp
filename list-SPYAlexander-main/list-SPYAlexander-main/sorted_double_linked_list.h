/*
 * Title:		SortedDoubleLinkedList
 * Purpose:		A double linked list that keeps its elements sorted at all times.
 * Author:		Carlos Arias
 * Date:		April 4, 2023
 */
#ifndef SORTED_DOUBLE_LINKED_LIST_H
#define SORTED_DOUBLE_LINKED_LIST_H

#include "dlinkedlist.h"
#include "comparable.h"

/**
 * Note that there are only two methods for this class
 * The constructor is not going to do anything
 * And Insert is overridden without position, as it is supposed
 * to insert in such a way that the list is always sorted.
 */

class SortedDoubleLinkedList : public DoubleLinkedList {
public:
    SortedDoubleLinkedList();
    virtual bool Insert(Comparable* element);
};


#endif //AST_LIST_SOLUTION_SORTED_DOUBLE_LINKED_LIST_H
