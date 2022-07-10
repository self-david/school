#include "order.h"


template<class Type, const unsigned long int MAX>
Order<Type, MAX>::Order() { }

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::sort(Type &a, Type &b) {
    Type aux;
    aux = a;
    a = b;
    b = aux;
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::bubble() {
    int i = MAX, j;
    bool band;

    do{
        band = false;
        j=0;

        while(j < i) {
            if(data[j] > data[j+1]) {
                sort(data[j], data[j+1]);
                band = true;
            }
            j++;
        }
        i--;
    }while(band);

}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::shell() {
    float fact = 3.0/4.0;
    unsigned long dif = MAX*fact;

    while(dif > 0){
        for(unsigned long i=0; i <= MAX-dif; i++) {
            if(data[i] > data[i+dif]) {
                sort(data[i],data[i+dif]);
            }
        }
        dif*=fact;
    }
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::select() {
    unsigned long i = 0, j, menor;

    while(i < MAX-1) {
        menor = i;
        j = i+1;
        while(j < MAX) {
            if(data[j] < data[menor]){
               menor = j;
            }
            j++;
        }
        if(menor != i) {
           sort(data[i],data[menor]);
        }
        i++;
    }
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::insert() {
    unsigned long i = 1, j;
    Type element;

    while(i < MAX) {
        element = data[i];
        j = i;
        while(j > 0 and element < data[j-1]) {
            data[j] = data[j-1];
            j--;
        }
        if(i != j) {
            data[j] = element;
        }
        i++;
    }
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::merge() {
    merge(0, MAX);
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::merge(unsigned long left, unsigned long right) {
    if(left >= right){
       return;
    }

    Type temp[MAX];
    for(unsigned long i(left); i <= right; i++){
       temp[i] = data[i];
    }

    unsigned long medio((left+right)/2);

    merge(left, medio);
    merge(medio+1, right);

    unsigned long i(left), j(medio+1), x(left);

    while(i<=medio and j<=right){
        while(i<=medio and temp[i] <= temp[j]){
            data[x++]=temp[i++];
        }
        if(i<=medio){
            while(j<=right and temp[j]<=temp[i]){
            data[x++]=temp[j++];
            }
        }
    }
    while(i<=medio){
        data[x++] = temp[i++];
    }
    while(j<=right){
        data[x++] = temp[j++];
    }
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::quick() {
    quick(0, MAX);
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::quick(unsigned long left, unsigned long right) {
    if(left>=right){
        return;
    }


    unsigned long i(left), j(right);
    unsigned long pivote((left+right)/2);
    sort(data[pivote], data[right]);

    while(i < j) {
        while(i < j and data[i] <= data[right]) {
            i++;
        }
        while(i < j and data[j] >= data[right]) {
            j--;
        }
        if(i != j) {
            sort(data[i], data[j]);
        }
    }

    if(i != right) {
        sort(data[i],data[right]);
    }
    quick(left, i-1);
    quick(i+1, right);
}

template<class Type, const unsigned long int MAX>
void Order<Type, MAX>::print() {
    for(unsigned long i(0); i < MAX; i++) {
        std::cout<< data[i] << " ";
    }
}

template<class Type, const unsigned long int MAX>
int Order<Type, MAX>::index() {
    return MAX;
}
