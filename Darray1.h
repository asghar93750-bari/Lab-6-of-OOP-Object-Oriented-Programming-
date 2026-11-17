
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
    // Constructor.
    DArray();
    // Destructor.
    ~DArray();
    // Insert element.
    void push_back(int value);
    // Copy assignment operator
    DArray &operator=(const DArray &other);
    // Output operator
    friend ostream &operator<<(ostream &out, const DArray &arr);
    // Problem 2 functions
    int size() const;
    int capacity() const;
    int &operator[](int index);
};
#endif
