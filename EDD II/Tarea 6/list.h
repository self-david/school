#ifndef LIST_H
#define LIST_H

#include <iostream>


template <typename Type>
class List {
private:
        static const int SIZE = 3000;
        Type data[SIZE];
        size_t counter;

        bool validPosition(const int &);
        void mergeSort(const int &left, const int &right);
        void quickSort(const int &left, const int &right);
public:
        List();

        Type &operator[](int &);

        bool empty();/*revisa si esta vacia*/
        bool full();/*revisa si esta llena*/

        int first();/*devuelve la primer posocion*/
        int last();/*devuelve la ultima posicion*/
        int before(const int &);/*anterior, devuleve posicion actual*/
        int after(const int &);/*siguente, devuelve posicion siguente*/

        void sortData(Type &, Type &);

        void append(const Type &);/*elemento a insertar al final de la lista*/
        void append(const Type &, const int &);/*inserta en una posicion exacta*/
        void erase(int &);/*borra un dato de la lista*/
        void remove();/*elimina toda la lista*/

        int findDataL(const Type &);/*busqueda lineal*/
        int findDataB(const Type &);/*busqueda binario*/

        void mergeSort();/*meotodo de ordenamiento*/
        void quickSort();/*meotodo de ordenamiento*/ /*revisar*/


        Type show(const int &);/*retorna el elemento para poder mostrarlo*/
        void showAll();/*retorna el elemento para poder mostrarlo*/
        void bubbleSort();//Burbuja Mejorada
        void shellSort();//shell
        void insertionSort();//Insersion
        void selectSort();//Seleccion


};

#endif // LIST_H

