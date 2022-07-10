#include "list.h"
#include <stdexcept>

template<typename Type>
List<Type>::List() : counter(0) { }

template<typename Type>
Type &List<Type>::operator[](int &e) {
    if(empty()) {
        std::cout << "empty list";
    }
    if(e>=counter) {
        std::cout << "invalid position ";
    }
    return data[e];
}

template<typename Type>
bool List<Type>::validPosition(const int &position) {
        if(position >= counter or position < 0) {
                return false;
        }
        return true;
}

template<typename Type>
void List<Type>::mergeSort() {
    mergeSort(0, counter);
}

template<typename Type>
void List<Type>::mergeSort(const int &left, const int &right) {
    if(left >= right) {
        /*criterio de paro */
        return;
    }
    /*copia a temporal*/
    Type temp[SIZE];
    for (int z(left); z <= right; z++) {
        temp[z] = data[z];
    }

    int m((left+right)/2);

    mergeSort(left, m);
    mergeSort(m+1, right);

    int i(left), j(m+1), x(left);

    while (i <= m and j <= right) {
        while (i <= m and temp[i] <= temp[j]) {
            data[x++] = temp[i++];
        }
        if(i <= m) {
            while (j <= right and temp[j] <= temp[i]) {
                data[x++] = temp[j++];
            }
        }
    }
    while (i <= m) {
        data[x++] = temp[i++];
    }

    while (j <= right) {
        data[x++] = temp[j++];
    }
}

template<typename Type>
void List<Type>::quickSort() {
    quickSort(0, counter);
}

template<typename Type>
void List<Type>::quickSort(const int &left, const int &right) {
    if(left >= right) {
        /*criterio de paro */
        return;
    }

    int i(left), j(right);

    while (i < j) {
        while (i < j and data[i] <= data[right]) {
            i++;
        }
        while (i < j and data[j] >= data[right]) {
            j--;
        }
        if(i != j) {
            sortData(data[i], data[j]);
        }
    }
    if(i != right) {
        sortData(data[i], data[right]);
    }

    quickSort(left, i-1);
    quickSort(i+1, right);
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
void List<Type>::append(const Type &newElement) {
        if(full()) {
                std::cout << std::endl << "la lista esta llena" << std::endl;
        } else {
                data[counter] = newElement;
                counter++;
        }
}

template<typename Type>
void List<Type>::append(const Type &newElement, const int &position) {
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

template<class Type>
void List<Type>::sortData(Type &a, Type &b) {
    Type aux(a);
    a = b;
    b = aux;
}

template<typename Type>
void List<Type>::erase(int &position) {
        position--;
        if(!validPosition(position)) {
                std::cout << "posicion invalida" << std::endl;
        } else {
                for (int i(position); i < counter; i++) {
                        data[i] = data[i+1];
                }
                counter--;
        }

}


template <class Type>
int List<Type>::findDataL(const Type &e) {
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
    return -1;
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
                std::cout << "   " << position << data[position];
                return data[position];
        }
        return data[0];
}

template<typename Type>
void List<Type>::showAll() {
        if(empty()){
                std::cout << "la lista esta vacia" << std::endl;
        } else {
            for (int i(0); i < counter; i++) {
                std::cout << "   " << i << data[i];
            }
        }
}

template<typename Type>
void List<Type>::bubbleSort() {
    int band,i,j;
     i = counter-1;

     do {
         band=0;
         j=0;
         while(j < i) {
             if(data[j] > data[j+1]) {
                 sortData(data[j], data[j+1]);
                 band=1;
             }
             j++;
         }
         i--;
     }while(band==1);


}

template<typename Type>
void List<Type>::shellSort() {
    int dif, i = 0;
    float fact = 0.75;

    dif=(counter-1)*fact;

    while(dif>0) {
        while(i<counter-1-dif) {
            if(data[i] > data[i+dif]) {
                sortData(data[i+dif], data[i]);
            }
            i++;
        }
        dif*=fact;
    }
}

template<typename Type>
void List<Type>::insertionSort() {
    int i = 1 ,j;
    Type aux;

    while(i < counter){
        aux = data[i];
        j=i;
        while(j >0 and aux < data[j-1]){

            data[j] = data[j-1];
            j--;
        }
        if(i!=j){
            data[j] = aux;
        }
        i++;
    }
}

template<typename Type>
void List<Type>::selectSort() {
    int i,j,menor;
    i=0;
    while(i<counter-1){
        menor=i;
        j=i+1;
        while(j<counter){
            if(data[j] < data[menor])
            menor=j;
            j++;
        }
        if(menor!=i){
            sortData(data[i], data[menor]);
        }
        i++;
    }
}

template<typename Type>
void List<Type>::remove() {
        counter = 0;
}
