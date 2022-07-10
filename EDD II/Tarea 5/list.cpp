#include "list.h"

template<typename Type>
List<Type>::List() : counter(0) { }

template<typename Type>
bool List<Type>::validPosition(const int &position) {
        if(position >= counter or position < 0) {
                return false;
        }
        return true;
}

template<typename Type>
bool List<Type>::empty() {
        return counter == 0;
}

template<typename Type>
bool List<Type>::full() {
        return counter == SIZE;
}

template<typename Type>
void List<Type>::insert(const Type &newElement) {
        if(full()) {
                std::cout << std::endl << "la lista esta llena" << std::endl;
        } else {
                data[counter] = newElement;
                counter++;
        }
}

template<typename Type>
void List<Type>::insertPosition(const Type &newElement, const int &position) {
        if(full()) {
                std::cout << std::endl << "la lista esta llena" << std::endl;
        } else if(!validPosition(position)) {
                std::cout << std::endl << "posicion invalida" << std::endl;
        } else {
                for (int i(counter); i >= position; i--) {
                        data[i+1] = data[i];
                }
                data[position] = newElement;
                counter++;
        }
}

template<typename Type>
void List<Type>::erase(int &position) {
        position--;
        if(!validPosition(position)) {
                std::cout << "posicion invalida" << std::endl;
        } else {
                for (int i = position; i < counter; i++) {
                        data[i] = data[i+1];
                }
                counter--;
        }

}

template <class Type>
int List<Type>::findDataL(const Type &e) {
    /*pendiente*/
    for (size_t i = 0; i <= counter; i++) {
        if(data[i] == e) {
            return i;
        }
    }
    return -1;
}

template <class Type>
int List<Type>::findDataB(const Type &e) {
    int i(0), j(counter),  m;

    while (i <= j) {
        m = (i+j) / 2;

        if(data[m] == e) {
            return m;
        }
        if(e < data[m]) {
            j = m-1;
        } else {
            i = m+1;
        }
    }
}

template<typename Type>
int List<Type>::first() {
        if(empty()) {
             return -1;
        }
        return 0;
}

template<typename Type>
int List<Type>::last() {
        return counter-1;
}

template<typename Type>
int List<Type>::before(const int &position) {
        if(!validPosition(position)) {
                return -1;
        }
        return position-1;
}

template<typename Type>
int List<Type>::after(const int &position) {
        if(!validPosition(position)) {
                return -1;
        }
        return position+1;
}

template<typename Type>
Type List<Type>::show(const int &position) {
        if(empty()){
                std::cout << "la lista esta vacia" << std::endl;
        } else if(!validPosition(position)) {
                std::cout << "posicion invalida" << std::endl;
        } else {
                return data[position];
        }
}

template<typename Type>
void List<Type>::remove() {
        counter = 0;
}
