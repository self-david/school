#ifndef IN_TO_POST_H
#define IN_TO_POST_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
//#include <regex>


using namespace std;

class In_to_post {
private:
    stack<string> pila;
    vector<string> cola;
    size_t contador;


public:
    In_to_post();

    size_t size;
    vector<string> convertir(string);
    int precedencia(string);
    bool es_operador(string);
    vector<string> infijo_a_postfijo(string);
    void limpiar();
};

#endif // IN_TO_POST_H
