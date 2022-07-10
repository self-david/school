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

    void copyAll(const Queue<Type, ARRAYSIZE> &);
public:
    Queue();
    Queue(const Queue<Type, ARRAYSIZE> &);

    bool empty();
    bool full();

    void enqueue(const Type &);
    Type dequeue();

    Type getFront();

    Queue<Type, ARRAYSIZE> &operator = (const Queue<Type, ARRAYSIZE>&);
};

#endif // QUEUE_H
