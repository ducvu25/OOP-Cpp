//
// Write your description
//

#include "object.h"
#include "list.h"
#include "vsarray.h"

VSArray ::VSArray(const VSArray &list)
{
    this->_capacity = list._capacity;
    this->_size = list._size;
    _data = new Object *[_capacity];
    this->_delta = list._delta;
    for (size_t i = 0; i < _size; i++)
    {
        _data[i] = list.Get(i)->Clone();
    }
    for (size_t i = _size; i < _capacity; i++)
    {
        _data[i] = nullptr;
    }
}
VSArray ::~VSArray()
{
    for (size_t i = 0; i < this->_capacity; i++)
    {
        Object *t = this->_data[i];
//        delete t;
    }
    delete this->_data;
}
const VSArray &VSArray ::operator=(const VSArray &rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    if (this->_capacity != rhs._capacity)
    {
        this->Clear();
        delete[] this->_data;
        this->_capacity = rhs._capacity;
        this->_data = new Object *[this->_capacity];
        for (size_t i = 0; i < this->_capacity; i++)
        {
            this->_data[i] = nullptr;
        }
    }
    for (size_t i = 0; i < rhs.Size(); i++)
    {
        this->_data[i] = rhs.Get(i)->Clone();
    }
    return *this;
}
void VSArray ::Resize()
{
    Object **t = new Object *[this->_capacity * 2];
    for (int i = 0; i < this->_capacity; i++)
        t[i] = this->_data[i];
    delete[] this->_data;
    this->_data = t;
    this->_capacity *= 2;
}
VSArray::VSArray(size_t capacity, double increasePercentage)
{
    this->_capacity = capacity;
    this->_size = 0;
    this->_data = new Object *[this->_capacity];
    this->_delta = increasePercentage;
    for (size_t i = 0; i < this->_capacity; i++)
    { // Issa correction to the _capacity
        this->_data[i] = nullptr;
    }
}

bool VSArray::Insert(Object *element, size_t position)
{
    if (position > this->_size)
        return false;

    if (this->_capacity <= this->_size) {
        this->Resize();
    }

    if (position <= _size)
    {
        for (size_t i = _size; i > position; i--)
        {
            _data[i] = _data[i - 1];
        }
    }
    _data[position] = element;
    _size++;
    return true;
}
int VSArray::IndexOf(const Object *element) const
{
    for (int i = 0; i < this->_size; i++)
        if (this->_data[i]->Equals(*element))
            return i;
    return -1;
}
Object *VSArray::Remove(size_t position)
{
    if (position >= _size)
    {
        return nullptr;
    }
    Object *retVal = _data[position];
    for (size_t i = position; i < _size - 1; i++)
    {
        _data[i] = _data[i + 1];
    }
    _data[_size - 1] = nullptr;
    _size--;
    return retVal;
}
Object *VSArray::Get(size_t position) const
{
    if (position >= _size)
        return nullptr;
    else
        return _data[position];
}
string VSArray::ToString() const
{
    string s = "{";
    for (size_t i = 0; i < _size; i++)
    {
        s += _data[i]->ToString() + ", ";
    }
    return s + "}";
}
void VSArray::Clear()
{
    for (size_t i = 0; i < _size; i++)
    {
        delete _data[i];
        _data[i] = nullptr;
    }
    _size = 0;
}
size_t VSArray::GetCapacity() const
{
    return this->_capacity;
}
// Implement ALL methods of VSArray class