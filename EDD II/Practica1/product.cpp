#include "product.h"


Product::Product() : random(fRandom()) { }

char *Product::getCode() {
    return code;
}


void Product::setCode(size_t Special) {
    char *Name = this->getName();
    char *Speciality = this->getSpecialty();
    size_t count = 2;

    strcpy(code, std::to_string(random).c_str());

    while (*Speciality && count < Special+2) { code[count++] = *Speciality++; }
    while (*Name && count < Special+5)       { code[count++] = *Name++; }
    code[count] = '\0';
}

char *Product::getName() { return name; }

void Product::setName(char &value) {
    // strcpy() recoge el valor del segundo campo y lo coloca en el primero
    strcpy(name, &value);
}

char *Product::getDescripcion() { return descripcion; }

void Product::setDescripcion(char &value) {
    strcpy(descripcion, &value);
}

float Product::getPrice() { return price; }

char *Product::getStrPrice() {
    char *Price = new char[6];
    strcpy(Price, std::to_string(this->getPrice()).c_str());
    return Price;
}

void Product::setPrice(float value) {
    price = value;
}

char *Product::getSpecialty() { return specialty; }

void Product::setSpecialty(char &value) {
    strcpy(specialty, &value);
}

char *Product::whiteSpace(char *char_, size_t size) {
    size_t count=0;
    char *finally = new char[size];
    while (count < size-1) { finally[count++] = *char_ ? *char_++ : ' '; }
    finally[count] = '\0';
    return finally;
}

std::vector<std::string> Product::split(std::string &str) {

    std::vector<std::string> resultado;

    std::string::const_iterator itBegin = str.begin();
    std::string::const_iterator itEnd   = str.end();

    size_t numItems = 1;
    for(std::string::const_iterator it = itBegin; it!=itEnd; ++it )
        numItems += *it==',';

    resultado.reserve(numItems);

    for(std::string::const_iterator it = itBegin; it!=itEnd; ++it ) {
        if( *it == '|' ) {
            resultado.push_back(std::string(itBegin,it));
            itBegin = it+1;
        }
    }

        if( itBegin != itEnd )
            resultado.push_back(std::string(itBegin,itEnd));

        return resultado;
}

size_t Product::fRandom() {
    // regresa un numero random (10-99)
    return rand()%90+10;
}
/*
std::ostream &Product::operator <<(std::ostream &os, const Product &p) {
    os << "fg";
    return os;
}*/





