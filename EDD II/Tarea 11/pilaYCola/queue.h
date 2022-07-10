#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include <string>
#include <iostream>
#include "list.h"

template <class Type>
class Queue : public List<Type>{
private:
 Type data;
public:
 Queue();
 bool empty();
 bool full();
 void enqueue(const Type &);
 Type dequeue();
 Type getFront();
};
#endif // QUEUE_H
