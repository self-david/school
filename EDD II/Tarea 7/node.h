#ifndef NODE_H
#define NODE_H



template<class Type>
class Node {
private:
    Type data;
    Node<Type> *next;
public:
    Node();
    Node(const Type &);

    Type getData() const;
    Node<Type> *getNext() const;

    void setData(const Type &);
    void setNext(Node<Type> *);
};


#endif // NODE_H
