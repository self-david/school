#include "matrices.h"
#include <stdlib.h>
#include <ctime>


matrices::matrices() {
    srand((unsigned)time(NULL));
}

void matrices::setMatriz() {
    /*con esto se rellenara la matriz*/
    matriz = float(-1000+(rand()%2000))*10/100;
}

float matrices::getMatriz() const {
    return matriz;
}

void matrices::setMatrizSuma(float matriz1,float matriz2) {
    matriz = matriz1+matriz2;
}

void matrices::setMatrizMult(float matriz1,float matriz2) {
    matriz = matriz1*matriz2;
}
