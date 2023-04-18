/**
 * Title:		SortedDoubleLinkedList
 * Purpose:		A double linked list that keeps its elements sorted at all times.
 * Author:		Carlos Arias
 * Date:		April 4, 2023
 */

#include "sorted_double_linked_list.h"

SortedDoubleLinkedList ::SortedDoubleLinkedList()
{
    for (Node *i = this->_head; i != this->_tail; i = i->next)
        for (Node *j = i->next; j != nullptr; j = j->next)
            if (i->data->ToString() > j->data->ToString())
            {
                Object t = *(i->data);
                *i->data = *j->data;
                *j->data = t;
            }
}
bool SortedDoubleLinkedList ::Insert(Comparable *element)
{
    int d = 0;
    for (Node *i = this->_head; i != nullptr; i = i->next)
    {
        if (i->data->Equals(*element))
        {
            DoubleLinkedList ::Insert(element, d);
            return true;
        }
        d++;
    }
    return false;
}
// Implement ALL methods of class SortedDoubleLinkedList
