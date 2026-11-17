#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>
using namespace std;
class DArray
{
    private:
    int *data{};
    int size{};
public:
    DArray();
    ~DArray();
    DArray &operator=(const DArray &other);
    void push_back(int value);
    friend ostream &operator<<(ostream &out, const DArray &arr);
};
#endif