/**
 * Title:		SortedDoubleLinkedList
 * Purpose:		A double linked list that keeps its elements sorted at all times.
 * Author:		Carlos Arias
 * Date:		April 4, 2023
 */

#include "sorted_double_linked_list.h"

SortedDoubleLinkedList ::SortedDoubleLinkedList()
{
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}
bool SortedDoubleLinkedList ::Insert(Comparable *element)
{
    int d = 0;
    for (Node *i = this->_head; i != nullptr; i = i->next)
    {
        if (i->data->ToString() > element->ToString())
        {
            break;
        }
        d++;
    }
    DoubleLinkedList::Insert(element, d);
    return true;
}
// Implement ALL methods of class SortedDoubleLinkedList
