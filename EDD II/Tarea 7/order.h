#ifndef ORDER_H
#define ORDER_H

#include <iostream>

template< class Type, const unsigned long int MAX>
class Order {
private:
    Type data[MAX];

    void merge(unsigned long, unsigned long);
    void quick(unsigned long, unsigned long);

public:
    Order();

    void sort(Type &,Type &);//ordena dos datos
    void bubble();
    void shell();
    void select();
    void insert();
    void merge();
    void quick();
    void print();
    int index();

};
#endif // ORDER_H
