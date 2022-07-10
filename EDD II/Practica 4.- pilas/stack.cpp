#include "stack.h"
#include <stdexcept>

using namespace std;

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) { }

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE> &s) {
    copyAll(s);
}

template<class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() {
    return top == -1;
}

template<class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() {
    return top == ARRAYSIZE-1;
}

template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T &newData) {
    if(isFull()) {
        throw invalid_argument("desbordamiento de datos");
    }
    data[++top] = newData;
}

template<class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop() {
    if(isEmpty()) {
        throw  invalid_argument("insuficiencia de datos");
    }
    return data[top--];
}

template<class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() {
    if(isEmpty()) {
        throw invalid_argument("insuficiencia de datos");
    }
    return data[top];
}

template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>&s) {
    int i(0);
    while(i <= s.top) {
        data[i] = s.data[i];
        i++;
    }
    top = s.top;
}

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE> & Stack<T, ARRAYSIZE>:: operator = (const Stack<T, ARRAYSIZE>&e) {
    copyAll(e);
    return *this;
}
