#include <iostream>
#include <windows.h>

#include "product.h"

using namespace std;

char *whiteSpace(char *char_, size_t size) {
    size_t count=0;
    char *finally = new char[size];
    while (count < size) { finally[count++] = *char_ ? *char_++ : '*'; }
    return finally;
}



char *valor(char &val) {
    char *v = &val;
    return v;
}

int main() {
    Product pizza, pizza2;
    char name[] = "pizza hawahiana";
    char specialty[] = "es una pizza magica";
    char descripcion[] = "pizza de hiervas con pinia";
    char d[] = "codigo|nombre|especialidad|descripcion|15.56";

    cout << endl;

    pizza.setName(*name);
    pizza.setSpecialty(*specialty);
    pizza.setDescripcion(*descripcion);
    pizza.setPrice(float(10.8));
    pizza.setCode(3);

    /*cout << "codigo: " << pizza.getCode() << endl;
    cout << pizza.getName() << endl;
    cout << pizza.getPrice() << endl;
    cout << pizza.getSpecialty() << endl;
    cout << pizza.getDescripcion() << endl;*/

    cout << pizza << endl;

    pizza2(d);

    cout << pizza2 << endl;
//51es piz|pizza hawahiana               |10.800|es una pizza magica           |pizza de hiervas con pinia
    /*
    for(uint16_t i = 0; i < 256; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout << "test " << "\t";
    }*/
    return 0;
}
