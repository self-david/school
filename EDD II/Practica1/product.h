#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream> // permite el uso de las funciones to_string() y rand()
#include <string.h>  // permite el uso de la funcion strcpy()
#include <vector>

class Product {
private:
    char code[9];// codigo del producto
    char name[30];// nombre
    char descripcion[100];// descripcion
    float price;// precio
    char specialty[100];// especialidad

    size_t random;// numero random positivo de dos dijitos (10-99)

public:
    Product();
    char *getCode();
    void setCode(size_t);

    char *getName();
    void setName(char &value);

    char *getDescripcion();
    void setDescripcion(char &value);

    float getPrice();
    char *getStrPrice();
    void setPrice(float value);

    char *getSpecialty();
    void setSpecialty(char &value);

    char *whiteSpace(char *, size_t);

    std::vector<std::string> split(std::string &) ;

    size_t fRandom();

    friend std::ostream &operator << (std::ostream &os, Product &p) {
        /// sobrecarga de operador ostram para utomatizar el retorno de datos
        /// y guardarlos de una forma mas eficiente
        ///
        os << p.getCode() << '|';
        os << p.whiteSpace(p.getName(),25) << '|';
        os << p.whiteSpace(p.getSpecialty(), 30) << '|';
        os << p.whiteSpace(p.getDescripcion(), 30) << '|';
        os << p.whiteSpace(p.getStrPrice(), 6);
        return os;
    }

    Product &operator () (std::string s) {
        /// sobrecarga de operador istram para utomatizar la recoleccion de datos
        ///
        strcpy(code, std::to_string(random).c_str());
        strcat(code,split(s)[0].c_str());
        strcpy(name,split(s)[1].c_str());
        strcpy(specialty,split(s)[2].c_str());
        strcpy(descripcion,split(s)[3].c_str());
        price = std::stof(split(s)[4]);
    }
};

#endif // PRODUCT_H
