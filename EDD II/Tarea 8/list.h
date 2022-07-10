#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iostream>
#include <string>


template <typename Type, int ARRAYSIZE = 3000>
class List {
private:
    Type **data;
    int last;

    void copyAll(const List& l) {
            deleteAll();

        for(last = -1; last < l.last; data[++last] = new Type(*l.data[last])){
                if (data[last] == nullptr)
                    throw Exception("Something went wrong in List constructor, memory not available");
            }
    }

    bool validPos(const int& p) {
        return p >= 0 or p <= last;
    }

    //void mergeSort(const int &left, const int &right);

    void sort(const int& l, const int& r) {/*Quick*/
            if(l >= r)
                return;

            if (l + 1 == r) {
                if(*data[l] > *data[r]){
                    std::swap(data[l], data[r]);
                }
              return;
              }

            int i = l, j = r;

            while(i < j) {
                while(i < j and *data[i] <= *data[r]) {
                    i++;
                }
                while(i < j and *data[j] >= *data[r]) {
                    j--;
                }

                if(i != j) {
                    std::swap(data[i], data[j]);
                }
            }

            if(i != r){
                std::swap(data[i], data[r]);
            }

            if(i > l) {
                sort(l, i - 1);
            }

            if(i < j) {
                sort(i + 1, j);
            }
        }

public:        
    class Exception : public std::exception {
            private:
                std::string msg;

            public:
              explicit Exception(const char* message) : msg(message) { }
              explicit Exception(const std::string& message) : msg(message) { }
              virtual ~Exception() throw () { }
              virtual const char* what() const throw () { return msg.c_str(); }
        };

    List() {
        if((data = new Type*[ARRAYSIZE]) == nullptr) {
            throw Exception("Something went wrong in List constructor, memory not available");
        }
        for(last = ARRAYSIZE; last >= 0; data[--last] = nullptr);
    }

    List(const List& l) : List() {
        copyAll(l);
    }

    ~List() {
        deleteAll();

        delete[] *data;
    }

    Type &operator [] (int &e) {
        if(empty()) {
            throw Exception("lista vacia, []");
        }
        if(e > last) {
            throw Exception("posicion invalida, []");
        }
        return *data[e];
    }

    bool empty() {
        return last == -1;
    }

    bool full() {
        return last == ARRAYSIZE - 1;
    }

    void insert(const Type &e, int p) {
        if(full()) {
            throw Exception("Can not insert data in a full List");
        }

        if(p != -1 and !validPos(p)) {
            throw Exception("There is an invalid position, trying to insert data into List");
        }

        for(int i = last++; i > p; data[i + 1] = data[i]);

        if((data[p + 1] = new Type(e)) == nullptr) {
            throw Exception("Something went wrong inserting new data in List");
        }
    }

    void insert(const Type &e) {
        insert(e, getLast());
    }

    void erase(int p) {
        if(!validPos(p)) {
            throw Exception("There is an invalid position, trying to delete data from List");
        }

        for(int i = p; i < last; i++) {
            data[i] = data[i+1];
        }

        delete data[last--];
      }

    int getFirst() {
        return last == -1 ? -1 : 0;
    }

    int getLast() {
        return last;
    }

    int getPrev(const int& p) {
        return p == 0 or !validPos(p) ? -1 : p - 1;
    }

    int getNext(const int& p) {
        return p == last or !validPos(p) ? -1 : p + 1;
    }

    int find( Type &e) {
        for(int i = 0; i <= last; i++) {
            if(*data[i] == e) {
                return i;
            }
        }
        return -1;
    }

    int findB(Type &e) {/*busqueda binario*/
        int i(0), j(last),  m;

        while (i <= j) {
            m = (i+j) / 2;

            if(*data[m] == e) {
                return m;
            }
            if(e < *data[m]) {
                j = m-1;
            } else {
                i = m+1;
            }
        }
        return -1;
    }

    Type retrieve(const int p) {
        if(!validPos(p)) {
            throw Exception("Invalid position, trying to retrieve data from List");
        }
        return *data[p];
    }

    void sort() {/*Quick*/
        sort(0, last);
    }

    void print() {
      for(int i = 0; i <= last; i++) {
          std::cout << i << *data[i];
      }
    }

    void print(const int &position) {
       if(empty()){
            throw Exception("la lista esta vacia");
       } else if(!validPos(position)) {
           throw Exception("posicion invalida");
       } else {
           std::cout << "   " << position << *data[position];
//           return this->data[position];
       }
       //return data[0];
    }

    void deleteAll() {
        for( ; last >= 0; last--) {
            delete data[last];
            data[last--] = nullptr;
        }
    }

    List& operator = (const List& l) {
        deleteAll();

        copyAll(l);

        return *this;
    }

    friend std::ostream& operator << (std::ostream& os, List& l) {
        for(int i = 0; i <= l.last; i++) {
            os << l.data[i] << std::endl;
        }
        return os;
    }

    friend std::istream& operator >> (std::istream& is, List& l) {
        Type myType;
        int i = 0;
        while (is >> myType)
            if((l.data[i++] = new Type(myType)) == nullptr) {
                throw Exception("Hay una posicion no valida, intentando insertar en >> operator");
        }
        return is;
    }

    void merge();/*meotodo de ordenamiento*/

    void bubble() {/*Burbuja Mejorada*/
    int band,i,j;
     i = last-1;

     do {
         band=0;
         j=0;
         while(j < i) {
             if(data[j] > data[j+1]) {
                 std::swap(data[j], data[j+1]);
                 band=1;
             }
             j++;
         }
         i--;
     }while(band==1);
}

    void shell() {//shell
        int dif, i = 0;
        float fact = 0.75;

        dif=(last-1)*fact;

        while(dif>0) {
            while(i<last-1-dif) {
                if(data[i] > data[i+dif]) {
                    std::swap(data[i+dif], data[i]);
                }
                i++;
            }
            dif*=fact;
        }
    }

    void insertion() {//Insersion
        int i = 1 ,j;
        Type *aux;

        while(i < last){
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

    void select() {//Seleccion
        int i,j,menor;
        i=0;
        while(i<last-1){
            menor=i;
            j=i+1;
            while(j<last){
                if(data[j] < data[menor])
                menor=j;
                j++;
            }
            if(menor!=i){
                std::swap(data[i], data[menor]);
            }
            i++;
        }
    }

    bool operator == (const List &l) {
        return  this->data == l.data;
    }

};

#endif // LIST_H

