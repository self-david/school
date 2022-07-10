#include "stack.h"
#include <stdexcept>

using namespace std;

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) { }


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
        throw  invalid_argument("insuficiencia de datos, pop");
    }
    return data[top--];
}

template<class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() {
    if(isEmpty()) {
        throw invalid_argument("insuficiencia de datos, getTop");
    }
    return data[top];
}

