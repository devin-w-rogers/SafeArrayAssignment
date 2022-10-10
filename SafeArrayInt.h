#include <cmath>
#include <iostream>

class SafeArrayInt
{
public:
    SafeArrayInt();
    //~SafeArrayInt();
    int size();
    void push_back(int newVal);
    int pop_back();
    int& at(int pos);
    int& operator[](int pos);

private:
    int capacity;
    int* p_nums;
    int numElementsUsed;

};