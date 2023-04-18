// Remember to write your headers!

#include "object.h"
#include "dlinkedlist.h"

DoubleLinkedList ::DoubleLinkedList(const DoubleLinkedList &other)
{
    this->_head = other._head;
    this->_tail = other._tail;
}
DoubleLinkedList &DoubleLinkedList ::operator=(const DoubleLinkedList &rhs)
{
    DoubleLinkedList tempt(rhs);
    return tempt;
}
DoubleLinkedList ::DoubleLinkedList()
{
    this->_head = nullptr;
    this->_tail = nullptr;
}
DoubleLinkedList ::~DoubleLinkedList()
{
    while (_head != nullptr)
    {
        if (_head == _tail)
            _tail = nullptr;
        Node *t = _head;
        _head = _head->next;
        _head->previous = nullptr;
        delete t->data;
        delete t;
    }
}
bool DoubleLinkedList ::Insert(Object *element, size_t position)
{
    Node *p = new Node();
    p->data = element;
    p->next = nullptr;
    p->previous = nullptr;
    if (position == 0)
    {
        p->next = this->_head;
        this->_head->previous = p;

        this->_head = p;
        if (this->_tail == nullptr)
            this->_tail = this->_head;
        return true;
    }
    Node *i = this->_head;
    int d = 0;
    while (i != nullptr)
    {
        if (d - 1 == position)
        {
            p->next = i;
            p->previous = i->previous;
            i->previous = p;
            return true;
        }
        d++;
        i = i->next;
    }
    return false;
}
int DoubleLinkedList ::IndexOf(const Object *element) const
{
    Node *i = this->_head;
    int d = 0;
    while (i != nullptr)
    {
        if (i->data->Equals(*element))
            return d;
        i = i->next;
        d++;
    }
    return -1;
}
Object *DoubleLinkedList ::Remove(size_t position)
{
    if (this->_head == nullptr || position < 0)
        return nullptr;
    Node *current = this->_head;
    for (int i = 0; i < position && current != nullptr; i++)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        return nullptr;
    }
    if (current == this->_head)
    {
        this->_head = current->next;
    }
    if (current == this->_tail)
    {
        this->_tail = current->previous;
        this->_tail->next = nullptr;
    }
    if (current->previous != nullptr)
    {
        current->previous->next = current->next;
    }

    if (current->next != nullptr)
    {
        current->next->previous = current->previous;
    }
    Object *t = current->data;
    delete current;
    return t;
}
Object *DoubleLinkedList ::Get(size_t position) const
{
    if (this->_head == nullptr || position < 0)
        return nullptr;
    Node *current = this->_head;
    for (int i = 0; i < position && current != nullptr; i++)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        return nullptr;
    }
    return current->data;
}
string DoubleLinkedList::ToString() const
{
    string s = "{";
    for (Node *current = this->_head; current != nullptr; current = current->next)
    {
        s += current->data->ToString() + ", ";
    }
    return s + "}";
}
void DoubleLinkedList ::Clear()
{
    while (this->_head != nullptr)
    {
        Node *t = this->_head;
        this->_head = this->_head->next;
        if (t->data != nullptr)
            delete t->data;
        delete t;
    }
    this->_head = nullptr;
    this->_tail = nullptr;
}
// Implement ALL methods of DoubleLinkedList class