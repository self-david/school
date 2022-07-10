#include "product.h"

using namespace std;

void Product::Date() {
    DataBase.entryDate.generate();
}

Product::Product() {
    DataBase.existence = 0;
}

void Product::setBarCode(std::string &value) {
    if(validateBarCode(value)) {
        DataBase.barCode = value;
    } else {
        cout << "codigo invalido" << endl << endl;
    }
}

void Product::setName(const std::string &value) {
    DataBase.name = value;
}

string Product::getName() const {
    return DataBase.name;
}

int Product::getExistence() const {
    return DataBase.existence;
}

void Product::add(int value) {
    DataBase.existence += value;
}

void Product::remove(int value){
    DataBase.existence -= value;
}


string Product::getBarCode() const {
    return DataBase.barCode;
}

float Product::getWeight() const {
    return DataBase.weight;
}

void Product::setWeight(float value) {
    DataBase.weight = value;
}

void Product::setPrice(float value) {
    DataBase.price = value;
}

float Product::getWholesalePrice() const {
    return DataBase.price*0.85;
}

float Product::getRetailPrice() const {
    return  DataBase.price;
}

bool Product::validateBarCode(const std::string &value) {
    /*con esto se obtiene el codigo de barras de 13 dijitos*/
    if(value.size() == 13) {
        /*Con esto rectifica que sean solo digitos*/
        for (int i = 0; i < value.size(); i++) {
            if(value[i] < 48 or value[i] > 57) {
                return false;
            }
        }
        DataBase.barCode = value;
    } else {
        return false;
    }
    /*si cumple con todas las condiciones saldra y retornara verdadero*/
    return true;
}

void Product::showProducts() const {
    cout << "\t\t\tCodigo de barras: " << getBarCode() << endl
         << "\t\t\tNombre: " << getName() << endl
         << "\t\t\tPeso del producto: " << getWeight() <<endl
         << "\t\t\tFecha: " << DataBase.entryDate.getYear() << "/"
                      << DataBase.entryDate.getMonth() << "/"
                      << DataBase.entryDate.getDay() << " "
                      << DataBase.entryDate.getHour() << ":"
                      << DataBase.entryDate.getMinute() << ":"
                      << DataBase.entryDate.getSecond() << endl
         << "\t\t\tPrecio por mayoreo: " << getWholesalePrice() << endl
         << "\t\t\tPrecio por menudeo: " << getRetailPrice() << endl
         << "\t\t\tExistenncia del producto: " << getExistence() << endl;

}

