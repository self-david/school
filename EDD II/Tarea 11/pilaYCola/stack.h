#ifndef STACK_H
#define STACK_H
#include <exception>
#include <string>
#include "list.h"


template <class Type>
class Stack : public List<Type>{
private:
    Type data;
public:
    Stack();
    bool isEmpty();
//    bool isFull();
    void push(const Type&);
    Type pop();
    Type getTop();
};
#endif // STACK_H
