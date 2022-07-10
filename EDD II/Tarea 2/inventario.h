#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <product.h>
#define FULL 500

class Inventario {
private:
    Product products[FULL];
    int last;
    int positionCode;/*guarda la posicion del codigo buscado*/
public:
    Inventario();

    bool isFull();/*revisa si el inventario esta lleno*/
    void addProduct();/*crea un nuevo producto*/

    void print();/*imprime en pantalla la lista de productos*/
    void Add(const std::string);/*añade cantidad a los productos*/
    bool searchCode(const std::string);/*verifica que el codigo introducido exista*/
    void Remove(const std::string);/*retira elementos de un producto*/


};

#endif // INVENTARIO_H
