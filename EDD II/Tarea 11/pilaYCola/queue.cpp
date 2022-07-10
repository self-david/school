#include "queue.h"

using namespace std;

template<class Type>
Queue<Type>::Queue() : List<Type>(nullptr) { }
template<class Type>
bool Queue<Type>::empty() {
    return List<Type>::empty();
}


template<class Type>
void Queue<Type>::enqueue(const Type &e) {
    this->insert(this->getLast(), e);

}
template<class Type>
Type Queue<Type>::dequeue() {
 if(empty()) {
 throw invalid_argument("insuficiencia de datos, dequeue");
 }
 this->erase(this->getFirst());
}

template<class Type>
Type Queue<Type>::getFront() {
 if(empty()) {
 throw invalid_argument("insuficiencia de datos, getFront");
 }
 return this->getFirst()->getData();
 }
