#include "node.h"

template<class Type>
Node<Type>::Node() : next(nullptr) { }

template<class Type>
Node<Type>::Node(const Type &e) : data(e), next(nullptr) { }

template<class Type>
Type Node<Type>::getData() const {
 return data;
}

template<class Type>
Node<Type> *Node<Type>::getNext() const {
    return next;
}

template<class Type>
void Node<Type>::setData(const Type &d) {
    data = d;
}

template<class Type>
void Node<Type>::setNext(Node<Type> *n) {
    next = n;
}
