#include <iostream>
#include "SafeArrayInt.h"
#include <cassert>

using namespace std;

int main()
{

    //create a safe array
    SafeArrayInt s1;
    //verify that the number of used elements is 0
    assert(s1.size() == 0);
    cout << "s1.size = " << s1.size() << endl;

    //add 3 items
    s1.push_back(10);
    s1.push_back(20);
    s1.push_back(30);

    //number of used elements is 3
    cout << "s1.size = " << s1.size() << endl;
    assert(s1.size() == 3);
    
    /*for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }*/

    //retrieve the values by position
    assert(s1.at(0) == 10);
    assert(s1.at(1) == 20);
    assert(s1.at(2) == 30);

    //verify the overloaded operator []    
    assert(s1[0] == 10);
    assert(s1[1] == 20);
    assert(s1[2] == 30);

    //update the first two with at()
    s1.at(0) = 50;
    s1.at(1) = 40;

    //verify
    assert(s1.size() == 3);
    assert(s1.at(0) == 50);
    assert(s1.at(1) == 40);
    assert(s1.at(2) == 30);

    //adding 100 random numbers
    for (int i = 0; i < 100; i++)
    {
        s1.push_back(rand());
        cout << "s1.size() = " << s1.size() << endl;
    }

    //verify
    assert(s1.size() == 103);
    assert(s1.at(0) == 50);
    assert(s1.at(1) == 40);
    assert(s1.at(2) == 30);

    //removing the last 100 random numbers
    for (int i = 0; i < 100; i++)
    {
        s1.pop_back();
    }

    cout << "s1.size() = " << s1.size() << endl;

    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }

    //verify
    assert(s1.size() == 3);
    assert(s1.at(0) == 50);
    assert(s1.at(1) == 40);
    assert(s1.at(2) == 30);

    cout << "I am at end" << endl;

    //going outside the bounds, the program should end
    s1.at(3) = 40;
    cout << "You should not see this on the screen!" << endl;

    return 0;

}