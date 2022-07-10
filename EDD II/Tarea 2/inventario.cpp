#include "inventario.h"

using namespace std;

Inventario::Inventario() : last(0) { }

bool Inventario::isFull() {
    return last == FULL;
    /*last es la cantidad de elementos que hay menos uno ya que
      inicia desde cero*/
}

void Inventario::addProduct() {
    string code, name;
    float weight, price;
    int existence;

    if(isFull()) {
        cout << "el inventario esta lleno" << endl;
    } else {
            cout << "'\t\t\t\t.:Nuevo producto para el inventario:." << endl;

            do {
                cout << "Introdusca el codigo: ";
                cin >> code;
                /*añade el codigo al final*/
                products[last].setBarCode(code);
            } while(!products[last].validateBarCode(code) or searchCode(code));
            /*verifica que tenga 13 digitos, y que ese codigo no exista
              para añadirlo y continuar*/

            do {
                cout << "cuantos elementos hay del producto: ";
                cin >> existence;
                products[last].add(existence);
            } while(existence <= 0);
            /*verifica que se este añadiendo por lo menos un elemento*/

            do{
                cout << "Introduce el nombre del producto: ";
                cin >> name;
                products[last].setName(name);
            } while(name.size() < 1);
            /*verifica que almenos tenga 1 caracteres el nombre del producto*/


            do{
                cout << "introduce el peso del producto: ";
                cin >> weight;
                products[last].setWeight(weight);
            } while (weight <= 0);
            /*verifica que el peso sea positivo*/

            do{
                cout << "cual es el precio del producto: ";
                cin >> price;
                products[last].setPrice(price);
            } while (price <= 0);
            /*verifica que el precio sea positivo*/
        products[last].Date();/*genera la fecha de creacion*/
        last++;
    }
}

void Inventario::print() {
    cout << endl << endl << "__________________________________________" << endl;
    for (int i = 0; i < last; i++) {
        cout << "\t\t\t\t\t\tProducto " << i + 1 << endl << endl;
        products[i].showProducts();
        cout << "__________________________________________" << endl << endl;
    }
}

void Inventario::Add(const string code) {
        int existence;
        if(searchCode(code) and last != 0) {
                cout << "el articulo existe, ";
                do{
                    cout << "cuantos elementos desea agregar al producto: ";
                    cin >> existence;
                    cout << endl;
                    /*aqui utlizamos la posicion que se guarda al buscar el codigo
                     para modificar la cantidad de elementos del producto*/
                } while(existence <= 0);
                products[positionCode].add(existence);
                /*y verifica que sea una cantidad positiva*/
        } else {
                cout << endl << endl << "el articulo no existe ";
                cout << "o el inventario esta vacio" << endl << endl;
        }
}

bool Inventario::searchCode(const string code) {
        /*verifica si existe el codigo*/
        for (int i = 0;i < last; i++) {
                products[i].getBarCode();
                if(products[i].getBarCode() == code) {
                        positionCode = i;
                        /*si existe, guarda la posicion en la que esta ese codigo*/
                        return true;
                }
        }
        return false;
}

void Inventario::Remove(const string code) {
        int existence;
        if(searchCode(code) and last != 0) {
                cout << "el articulo existe, ";
                do{
                    cout << "cuantos elementos desea quitar del inventario: ";
                    cin >> existence;
                    cout << endl;
                } while(existence <= 0);
                products[positionCode].remove(-1*(existence));
                /*esto verifica que no se esten añadiendo elementos*/
        } else {
                cout << endl << endl << "el articulo no existe ";
                cout << "o el inventario esta vacio" << endl << endl;
        }
}
