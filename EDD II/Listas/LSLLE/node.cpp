#include "node.h"

template<class Type>
node<Type>::node() : next(nullptr) { }

template<class Type>
node<Type>::node(const Type &e) : data(e), next(nullptr) { }

template<class Type>
Type node<Type>::getData() const {

}

template<class Type>
node<Type> *node<Type>::getNext() const {

}

template<class Type>
void node<Type>::setData(const Type &) {

}

template<class Type>
void node<Type>::setNext(node<Type> *) {

}
