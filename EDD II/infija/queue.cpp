#include "queue.h"

using namespace std;

template<class Type, int ARRAYSIZE>
Queue<Type, ARRAYSIZE>::Queue() : frontPos(0), endPos(ARRAYSIZE-1) { }

template<class Type, int ARRAYSIZE>
bool Queue<Type, ARRAYSIZE>::empty() {
    return (frontPos == endPos+1) or
            ((frontPos == 0) and (endPos == ARRAYSIZE-1));
}

template<class Type, int ARRAYSIZE>
bool Queue<Type, ARRAYSIZE>::full() {
    return (frontPos == endPos+2) or
            ((frontPos == 0) and (endPos == ARRAYSIZE-2)) or
            ((frontPos == 1) and (endPos == ARRAYSIZE-1));
}

template<class Type, int ARRAYSIZE>
void Queue<Type, ARRAYSIZE>::enqueue(const Type &e) {
    if(full()) {
        throw invalid_argument("desbordamiento de datos");
    }
//    endPos++;
//    endPos = (++endPos == ARRAYSIZE) ? 0 : endPos;
    data[ endPos = (++endPos == ARRAYSIZE) ? 0 : endPos] = e;
}

template<class Type, int ARRAYSIZE>
Type Queue<Type, ARRAYSIZE>::dequeue() {
    if(empty()) {
        throw invalid_argument("insuficiencia de datos, dequeue");
    }
    Type result(data[frontPos]);

    frontPos = (++frontPos == ARRAYSIZE ? 0 : frontPos);

    return result;

}

template<class Type, int ARRAYSIZE>
Type Queue<Type, ARRAYSIZE>::getFront() {
    if(empty()) {
        throw invalid_argument("insuficiencia de datos, getFront");
    }
    return data[frontPos];
}
