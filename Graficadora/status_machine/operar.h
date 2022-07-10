#ifndef OPERAR_H
#define OPERAR_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "in_to_post.h"
#include <math.h>

#define PI 3.1415926535
using namespace std;

class Operar : public In_to_post {
private:


public:
    Operar();

    string analizar(vector<string>);

    bool es_unario(string);

    string resultado(string, string);
    string resultado(string, string, string);

    string suma(string,string);
    string resta(string,string);
    string multiplicacion(string,string);
    string divicion(string,string);
    string modulo(string,string);
    string potencia(string,string);
    string raiz(string);
    string factorial(string);
    string seno(string);
    string coseno(string);
    string tangente(string);
    string logarimo(string);
    string ln(string);
};

#endif // OPERAR_H
