
#include "DArray.h"

// Default constructor
DArray::DArray()
    : data{nullptr}, currentSize{0}, currentCapacity{0}
{
}

// Destructor
DArray::~DArray()
{
    delete[] data;
}

// Copy constructor
DArray::DArray(const DArray &other)
    : currentSize{other.currentSize},
      currentCapacity{other.currentCapacity}
{
    if (currentCapacity == 0)
    {
        data = nullptr;
    }
    else
    {
        data = new int[currentCapacity];

        for (int i{}; i < currentSize; ++i)
        {
            data[i] = other.data[i];
        }
    }
}
// push_back()
void DArray::push_back(int value)
{
    if (currentSize == currentCapacity)
    {
        int newCapacity;

        if (currentCapacity == 0)
            newCapacity = 1;
        else
            newCapacity = currentCapacity * 2;

        int *newData = new int[newCapacity];

        for (int i{}; i < currentSize; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        currentCapacity = newCapacity;
    }
    data[currentSize] = value;
    ++currentSize;
}
// Copy assignment operator
DArray &DArray::operator=(const DArray &other)
{
    if (this != &other)
    {
        delete[] data;
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;

        if (currentCapacity == 0)
        {
            data = nullptr;
        }
        else
        {
            data = new int[currentCapacity];

            for (int i{}; i < currentSize; ++i)
            {
                data[i] = other.data[i];
            }
        }
    }

    return *this;
}
// Output operator
ostream &operator<<(ostream &out, const DArray &arr)
{
    for (int i{}; i < arr.currentSize; ++i)
    {
        out << arr.data[i] << " ";
    }

    return out;
}
// size()
int DArray::size() const
{
    return currentSize;
}
// capacity()
int DArray::capacity() const
{
    return currentCapacity;
}
// Non-const subscript operator
int &DArray::operator[](int index)
{
    return data[index];
}
// Const subscript operator
const int &DArray::operator[](int index) const
{
    return data[index];
}
// Equality operator
bool DArray::operator==(const DArray &other) const
{
    if (currentSize != other.currentSize)
    {
        return false;
    }
    for (int i{}; i < currentSize; ++i)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }
    return true;
}
