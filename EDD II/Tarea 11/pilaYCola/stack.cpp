#include "stack.h"
#include <stdexcept>

using namespace std;

template<class Type>
Stack<Type>::Stack() : List<Type>(nullptr) { }

template<class Type>
bool Stack<Type>::isEmpty() {
    return List<Type>::empty();
}

template<class Type>
void Stack<Type>::push(const Type &newData) {
    this->insert(this->getFirst(), newData);
}

template<class Type>
Type Stack<Type>::pop() {
 if(isEmpty()) {
 throw invalid_argument("insuficiencia de datos");
 }
 this->erase(this->getFirst());

}

template<class Type>
Type Stack<Type>::getTop() {
    if(isEmpty()) {
        throw invalid_argument("insuficiencia de datos");
    }
    return this->getFirst()->getData();
}
