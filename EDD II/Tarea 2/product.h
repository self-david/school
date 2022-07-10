#ifndef PRODUCT_H
#define PRODUCT_H

#include <fecha.h>
#include <iostream>

class Product {
private:
    struct Data {
    std::string barCode;/*Codigo de barras de 13 digitos*/
    std::string name;/*Nombre* del producto*/
    float weight;/*Peso*/
    Fecha entryDate; /*Fecha de entrada*/
    float price;/*Precio*/
    int existence; /*Existencia actual*/
    }DataBase;

public:
    Product();

    void Date();

    std::string getBarCode() const;
    void setBarCode(std::string &);

    std::string getName() const;
    void setName(const std::string &);

    float getWeight() const;
    void setWeight(float);

    void setPrice(float);
    float getWholesalePrice() const;/*Precio mayoreo*/
    float getRetailPrice() const; /*Precio menudeo*/

    void showProducts() const;
    int getExistence() const;/*ver cantidad de productos*/
    void add(int);/*añadir productos*/
    void remove(int);/*remueve productos*/
    bool validateBarCode(const std::string &);
};

#endif // PRODUCT_H
