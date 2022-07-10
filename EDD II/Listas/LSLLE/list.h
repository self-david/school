#ifndef LIST_H
#define LIST_H

#include "node.h"
//#include "node.cpp"

template <class Type>
class list {
private:
    node<Type> ancla;


public:
    list();
    ~list();

    list(const Type list);

    bool isEmpty();
    bool isFull();

    void insertData(node<Type>*, const Type &); /*posicion, elemento*/
    void deleteData(const int &);

    int getFirsPos();
    int getLastPos(node<Type> *);
    int getPrevPos(const int &);
    int getNextPos(const int &);

    int findData(const int &);
    int findDataL(const Type &);/*lineal*/
    int findDataB(const Type &);/*binario*/

    Type retrieve(const int &);

    void burble();
    void shell();
    void sortData(Type &, Type &);

    void sortData();
    void print();
    void deleteAll();

};

#endif // LIST_H
