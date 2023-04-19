/*
 * Title:		Comparable
 * Purpose:		Declaration of the class DoubleLinkedList
 * Author:		Carlos Arias
 * Date:		May 5, 2020
 */
#include "object.h"
#include "list.h"

#include <string>
using std::string;

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

class DoubleLinkedList : public List
{
protected:
	struct Node
	{
		Object *data;
		Node *next;
		Node *previous;
	};
	Node *_head;
	Node *_tail;
	DoubleLinkedList(const DoubleLinkedList &other);
	DoubleLinkedList &operator=(const DoubleLinkedList &rhs);

public:
	DoubleLinkedList();
	virtual ~DoubleLinkedList();
	virtual bool Insert(Object *element, size_t position);
	virtual int IndexOf(const Object *element) const;
	virtual Object *Remove(size_t position);
	virtual Object *Get(size_t position) const;
	virtual string ToString() const;
	virtual void Clear();
};

#endif // ADT_LIST_FULL_DLINKEDLIST_H
