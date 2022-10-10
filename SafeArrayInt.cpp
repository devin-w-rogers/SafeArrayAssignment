#include "SafeArrayInt.h"

using namespace std;

SafeArrayInt::SafeArrayInt()
{
    capacity = 10;
    p_nums = new int[capacity];
    numElementsUsed = 0;
}

//SafeArrayInt::~SafeArrayInt()
//{
//    cout << "This is in the destructor" << endl;
//}

int SafeArrayInt::size()
{
    return numElementsUsed;
}

void SafeArrayInt::push_back(int newVal)
{
    if (numElementsUsed == capacity) {
        capacity = capacity * 2;
        int* newArray = new int[capacity];

        for (int i = 0; i < capacity / 2; i++) {
            newArray[i] = p_nums[i];
        }

        delete[] p_nums;
        p_nums = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            p_nums[i] = newArray[i];
        }
        delete[] newArray;
        newArray = 0;
    }
    cout << "Before push_back... newVal = " << newVal << endl;
    p_nums[numElementsUsed] = newVal;
    numElementsUsed++;
    cout << "After push_back..." << endl;
}

int SafeArrayInt::pop_back()
{
    int lastNum = p_nums[numElementsUsed - 1];
    numElementsUsed--;

    if (capacity != 10) {
        if (numElementsUsed == capacity / 4) {
            capacity = capacity / 4;
            int* newArray = new int[capacity];

            for (int i = 0; i < capacity; i++) {
                newArray[i] = p_nums[i];
            }
            delete[] p_nums;
            p_nums = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                p_nums[i] = newArray[i];
            }
            delete[] newArray;
            newArray = 0;
        }
    }

    return lastNum;
}

int& SafeArrayInt::at(int pos)
{
    if (pos < 0 || pos >= numElementsUsed) {
        cout << "Tried to access an element outside the bounds..." << endl;
        system("pause");
        exit(0);
    }
    else {
        return p_nums[pos];
    }
}

int& SafeArrayInt::operator[](int pos)
{
    return at(pos);
}