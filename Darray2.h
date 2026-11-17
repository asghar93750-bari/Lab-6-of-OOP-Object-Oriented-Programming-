
#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray
{
private:
    int *data;
    int currentSize;
    int currentCapacity;

public:
    // Default constructor
    DArray();

    // Destructor
    ~DArray();

    // Copy constructor
    DArray(const DArray &other);

    // Insert element
    void push_back(int value);

    // Copy assignment operator
    DArray &operator=(const DArray &other);

    // Output operator
    friend ostream &operator<<(ostream &out, const DArray &arr);

    // Size and capacity
    int size() const;
    int capacity() const;

    // Subscript operators
    int &operator[](int index);
    const int &operator[](int index) const;
    // Equality operator
    bool operator==(const DArray &other) const;
};

#endif
