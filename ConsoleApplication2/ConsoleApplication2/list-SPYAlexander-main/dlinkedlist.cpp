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
}
bool DoubleLinkedList ::Insert(Object *element, size_t position)
{
    if (position > _size) {
        return false;
    }
    Node* newNode = new Node();
    newNode->data = element;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    if (_head == nullptr) {
        _head = newNode;
        _tail = newNode;
        _size++;
        return true;
    }

    if (position == 0) {
        newNode->next = _head;
        _head->previous = newNode;
        _head = newNode;
        _size++;
        return true;
    }
    if (position == _size) {
        newNode->previous = _tail;
        _tail->next = newNode;
        _tail = newNode;
        _size++;
        return true;
    }

    Node* current = _head;
    int count = 0;
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        _tail->next = newNode;
        newNode->previous = _tail;
        _tail = newNode;
        _size++;
        return true;
    }

    Node* prevNode = current->previous;
    newNode->previous = prevNode;
    newNode->next = current;
    prevNode->next = newNode;
    current->previous = newNode;
    _size++;
    return true;
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
    if (position > _size || position < 0) {
        return nullptr;
    }
    Object* retVal = nullptr;
    Node* current = _head;
    Node* prev = nullptr;

    for (int i = 0; i < position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        retVal = current->data;
        if (prev == nullptr) {
            _head = current->next;
        }
        else {
            prev->next = current->next;
        }

        if (current == _tail) {
            _tail = prev;
        }

        delete current;
        _size--;
    }
    return retVal;
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
    this->_size = 0;
    this->_head = nullptr;
    this->_tail = nullptr;
}
// Implement ALL methods of DoubleLinkedList class