#ifndef LIST_H
#define LIST_H

#include <iostream>


template <typename Type>
class List {
private:
        static const int SIZE = 50;
        Type data[SIZE];
        int counter;

        bool validPosition(const int &);
public:
        List();

        bool empty();/*revisa si esta vacia*/
        bool full();/*revisa si esta llena*/

        void insert(const Type &);/*elemento a insertar al final de la lista*/
        void insertPosition(const Type &, const int &position);
        /*inserta elemento en posicion elejida, "dato, lugar"*/
        void erase(int &);/*borra un dato de la lista*/

        int first();/*devuelve la primer posocion*/
        int last();/*devuelve la ultima posicion*/
        int before(const int &);/*anterior, devuleve posicion actual*/
        int after(const int &);/*siguente, devuelve posicion siguente*/

        int findDataL(const Type &);/*lineal*/
        int findDataB(const Type &);/*binario*/

        Type show(const int &);/*retorna el elemento para poder mostrarlo*/
        void remove();/*elimina toda la lista*/

};

#endif // LIST_H

