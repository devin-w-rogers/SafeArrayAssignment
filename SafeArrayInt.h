#include <cmath>
#include <iostream>

using namespace std;

template <class T>
class SafeArrayInt
{
public:
    SafeArrayInt();
    //~SafeArrayInt();
    int size();
    void push_back(T newVal);
    T pop_back();
    T& at(int pos);
    T& operator[](int pos);

private:
    int capacity;
    T* p_nums;
    int numElementsUsed;

};

template <class T>
SafeArrayInt<T>::SafeArrayInt()
{
    capacity = 10;
    p_nums = new T[capacity];
    numElementsUsed = 0;
}

//SafeArrayInt::~SafeArrayInt()
//{
//    cout << "This is in the destructor" << endl;
//}

template <class T>
int SafeArrayInt<T>::size()
{
    return numElementsUsed;
}

template <class T>
void SafeArrayInt<T>::push_back(T newVal)
{
    if (numElementsUsed == capacity) {
        capacity = capacity * 2;
        T* newArray = new T[capacity];

        for (int i = 0; i < capacity / 2; i++) {
            newArray[i] = p_nums[i];
        }

        delete[] p_nums;
        p_nums = new T[capacity];

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

template <class T>
T SafeArrayInt<T>::pop_back()
{
    T lastNum = p_nums[numElementsUsed - 1];
    numElementsUsed--;

    if (capacity != 10) {
        if (numElementsUsed == capacity / 4) {
            capacity = capacity / 4;
            T* newArray = new T[capacity];

            for (int i = 0; i < capacity; i++) {
                newArray[i] = p_nums[i];
            }
            delete[] p_nums;
            p_nums = new T[capacity];
            for (int i = 0; i < capacity; i++) {
                p_nums[i] = newArray[i];
            }
            delete[] newArray;
            newArray = 0;
        }
    }

    return lastNum;
}

template <class T>
T& SafeArrayInt<T>::at(int pos)
{
    if (pos < 0 || pos >= numElementsUsed) {
        cout << "ERROR: Tried to access an element outside the bounds..." << endl;
        system("pause");
        exit(0);
    }
    else {
        return p_nums[pos];
    }
}

template <class T>
T& SafeArrayInt<T>::operator[](int pos)
{
    return at(pos);
}