#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include <string>
#include <iostream>

template <class Type, int ARRAYSIZE = 512>
class Queue {
private:
    Type data[ARRAYSIZE];
    int frontPos;
    int endPos;

public:
    Queue();

    bool empty();
    bool full();

    void enqueue(const Type &);
    Type dequeue();

    Type getFront();

};

#endif // QUEUE_H
