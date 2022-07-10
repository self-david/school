/*arraystack*/
#include "stack.h"
#include "stack.cpp"
#include <iostream>

using namespace std;



int main() {
    Stack<int> mypila;
    Stack<int> otra;
    int data = 5;
    cout << "Hello World!" << endl;

    mypila.push(data);
    mypila.push(data+1);
    mypila.push(data-1);
//    cout << mypila.getTop() << endl;
    otra = mypila;
    while (!mypila.isEmpty()) {
        cout << mypila.getTop() << endl;
        mypila.pop();
    }
    while (!otra.isEmpty()) {
        cout << otra.getTop() << endl;
    }
//    stack<int> otherPila(mypila);
    return 0;
}
