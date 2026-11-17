#include "DArray.h"
DArray::DArray() : data{nullptr}, size{0} {}
DArray::~DArray()
{
    delete[] data;
}
DArray &DArray::operator=(const DArray &other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i{}; i < size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}
void DArray::push_back(int value)
{
    int *temp = new int[size + 1];
    for (int i{}; i < size; ++i)
        temp[i] = data[i];
    temp[size] = value;
    delete[] data;
    data = temp;
    ++size;
}
ostream &operator<<(ostream &out, const DArray &arr)
{
    for (int i{}; i < arr.size; ++i)
        out << arr.data[i] << " ";
    return out;
}