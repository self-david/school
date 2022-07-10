#ifndef STACK_H
#define STACK_H

#include <exception>
#include <string>

class StackException : public std::exception {
private:
    std::string asg;
public:
//    explicit exception();
};


template <class T, int ARRAYSIZE = 512>
class Stack {
private:
    T data[ARRAYSIZE];
    int top;

    void copyAll(const Stack<T, ARRAYSIZE>&);

public:
    Stack();
    Stack(const Stack<T, ARRAYSIZE>&);/*constructor copia*/

    bool isEmpty();
    bool isFull();

    void push(const T&);
    T pop();

    T getTop();

    Stack<T, ARRAYSIZE> &operator = (const Stack<T, ARRAYSIZE>&);
};

#endif // STACK_H
