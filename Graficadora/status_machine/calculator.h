#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include "operar.h"
#include <vector>
#include <regex>

using namespace std;

enum class Estado {
    Inicial,
    q1, // numero entero (0-9)
    q2, // punto decimal
    q3, // numero entero "despues del punto decimal" (0-9)
    q4, // caracter albabetico (a-zA-Z)
    q5, // suma y diferencia (+,-)
    q6, // producto, divicion, modulo (*,/,%)
    q7, // potencia (^)
    q8, // raiz (√)(<)
    q9, // factorial (!)
    q10,// logaritmos y trigonometricas (sin,con,tan,log,ln)
    q11,// parentesis apertura ('(')
    q12,// parentesis cierre (')')
    ERROR = -1 //si no cumple retorna ERROR
};


class calculator : private Operar {
private:
    size_t parentesis, contador;
    string funcion, vacio, error_code;
    string variable_nueva;
    vector<string> var, val;
    Estado actual;
    string grafica;


public:
    calculator();

    vector<string> grafica_final;

    Estado gramatica(string &);
    bool isfunction(string);
    bool reservada(string);
    bool terminal(Estado);

    string variable(string &);

    string asignacion(string);
    string asignacion2(string);
    bool buscar_variables(vector<string> &);
    vector<string> recta(vector<string>, string, string);


};

#endif // CALCULATOR_H
