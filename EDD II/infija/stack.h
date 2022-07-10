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

public:
    Stack();

    bool isEmpty();
    bool isFull();

    void push(const T&);
    T pop();

    T getTop();

 };

#endif // STACK_H
