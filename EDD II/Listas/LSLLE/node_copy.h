#ifndef NODE_H
#define NODE_H


template<class Type>
class node {
private:
    Type data;
    node<Type> *next;
public:
    node();
    node(const Type &);

    Type getData() const;

    node<Type> *getNext() const;

    void setData(const Type &);
    void setNext(node<Type> *);
};

#endif // NODE_H
