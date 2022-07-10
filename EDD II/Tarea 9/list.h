#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename Type>
class List {
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

    class Node {
    private:
        Type data;
        Node *next;
        Node *prev;

    public:
        Node();
        Node(const Type &);

        Type &getData();
        Node *getNext() const;
        Node *getPrev() const;

        void setData(const Type &);
        void setNext(Node *);
        void setPrev(Node *);
    };

private:
    Node *anchor;

    bool validPos(Node*) const;
    void copyAll(const List &);

public:
    List();
    List(const List &);

    ~List();

    bool empty() const;

    void insert(Node *, const Type &);
    void erase(Node *);

    Node *getFirst() const;
    Node *getLast() const;
    Node *getPrev(Node *) const;
    Node *getNext(Node *) const;

    Node *find(const Type &) const;
    Type &retrieve(Node *);

    std::string toString() const;

    void deleteAll();

    List &operator = (const List &);
};

/// Implementacion

/// Node ///
template<typename Type>
List<Type>::Node::Node() : next(nullptr), prev(nullptr) { }

template<typename Type>
List<Type>::Node::Node(const Type &e) : data(e), next(nullptr), prev(nullptr) { }

template<typename Type>
Type &List<Type>::Node::getData() {
    return data;
}

template<typename Type>
typename List<Type>::Node* List<Type>::Node::getNext() const {
    return next;
}

template<typename Type>
typename List<Type>::Node* List<Type>::Node::getPrev() const {
    return prev;
}

template<typename Type>
void List<Type>::Node::setData(const Type &e) {
    data = e;
}

template<typename Type>
void List<Type>::Node::setNext(List<Type>::Node *p) {
    next = p;
}

template<typename Type>
void List<Type>::Node::setPrev(List<Type>::Node *p) {
    prev = p;
}

/// List ///
template<typename Type>
bool List<Type>::validPos(List<Type>::Node *p) const {
    if(empty()) {
        return  false;
    }

    Node * aux(anchor);

    do {
        if(aux == p) {
            return  true;
        }
        aux = aux->getNext();
    }while (aux != anchor);

    return false;
}

template<typename Type>
void List<Type>::copyAll(const List &l) {
    Node *aux(l.anchor);
    Node *last(nullptr);
    Node *newNode;

    do{
        newNode = new Node(aux->getData());

        if(newNode ==  nullptr) {
            throw List<Type>::Exception("Memoria no disponible, coplyAll");
        }

        if(last ==  nullptr) {
            anchor = newNode;
        } else {
            last->setNext(newNode);
            newNode->setPrev(last);
        }

        last = newNode;
        aux = aux->getNext();
    } while (aux != l.anchor);

    last->setNext(anchor);
    anchor->setPrev(last);
}

template<typename Type>
List<Type>::List() : anchor(nullptr) { }

template<typename Type>
List<Type>::List(const List &l) {
    copyAll(l);
}

template<typename Type>
List<Type>::~List() {
    deleteAll();
}

template<typename Type>
List<Type> &List<Type>::operator = (const List<Type> &l) {
    deleteAll();

    copyAll(l);

    return *this;
}

template<typename Type>
bool List<Type>::empty() const {
    return anchor == nullptr;
}

template<typename Type>
void List<Type>::insert(List<Type>::Node *p, const Type &e) {
    if(p != nullptr and !validPos(p)) {
        throw  Exception("posicion invalida, insert");
    }

    Node *aux(new  Node(e));

    if(aux == nullptr) {
        throw Exception("memoria no disponible, insert");
    }

    if(p == nullptr) { // inserta al principio
        if(empty()) { // insertar el primer elemento
            aux->setPrev(aux);
            aux->setNext(aux);
        } else { // no es el primer elemeneto
            aux->setPrev(getLast());
            aux->setNext(anchor);
            getLast()->setNext(aux);//
            anchor->setPrev(aux);
        }

        anchor = aux;
    } else { // insertar en otra posicion
        aux->setPrev(p);
        aux->setNext(p->getNext());

        p->getNext()->setPrev(aux);
        p->getPrev()->setNext(aux);////
    }
}

template<typename Type>
void List<Type>::erase(List<Type>::Node *p) {
    if(!validPos(p)) {
        throw Exception("posicion invalida, erase");
    }

//    if(p == anchor) { // eliminar el primero
//        if(p->getData() == p) { // es nodo unico
//            anchor = nullptr;
//        } else { // todavia hay mas de un nodo
//            getLast()->setNext(p->getNext());
//            anchor = anchor->getNext();
//        }
//    } else { // eliminar otro
//        getPrev(p)->setNext(p->getNext());
//    }
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    if(p == anchor) {//eliminando al primero
        if(p->getNext() == p) {
            anchor == nullptr;
        } else {
            anchor = anchor->getNext();
        }

    }
    delete p;
}

template<typename Type>
typename List<Type>::Node *List<Type>::getFirst() const {
    return  anchor;
}

template<typename Type>
typename List<Type>::Node *List<Type>::getLast() const {
    if(empty()) {
        return nullptr;
    }

    Node *aux(anchor);
    aux = aux->getPrev();
    return aux;////////////modificar
}

template<typename Type>
typename List<Type>::Node *List<Type>::getPrev(List<Type>::Node *p) const {

    if(p == anchor or !validPos(p)) {
        return  nullptr;
    }

    return p->getPrev();
}

template<typename Type>
typename List<Type>::Node *List<Type>::getNext(List<Type>::Node *p) const {
    if(!validPos(p) or p->getNext() == anchor) { // encapsulamiento
        return nullptr;
    }
    return p->getNext();
}

template<typename Type>
typename List<Type>::Node *List<Type>::find(const Type &e) const /**/{
    Node *aux(anchor);

    while (aux != nullptr and aux->getData() != e) {
        aux = aux->getNext();
    }
    return  aux;
}

template<typename Type>
Type &List<Type>::retrieve(List<Type>::Node *p) {
    if(!validPos(p)) {
        throw Exception("posicion invalida, retrieve");
    }
    return p->getData();
}

template<typename Type>
std::string List<Type>::toString() const {
    std::string result = "\n";

    if(!empty()){

        Node *aux(anchor);
        do {
            result += aux->getData().toString() + "\n";
            aux = aux->getNext();
        } while (aux != anchor);
    }
    return result;
}

template<typename Type>
void List<Type>::deleteAll() {
    if(empty()) {
        return;
    }

    Node *mark(anchor);
    Node *aux;

    do {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    } while (anchor != nullptr);//modify
}

#endif // LIST_H



