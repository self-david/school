#ifndef MENU_H
#define MENU_H

#include "matrices.h"


class Menu {
    static const int MAX = 10;

    /*ATRIBUTOS*/
private:
    matrices Matriz_1[MAX][MAX],
             Matriz_2[MAX][MAX],
             productoMatriz[MAX][MAX],
             sumaMatriz[MAX][MAX];
    int TamMatriz;

    char Separacion[75] = "|________________________|"
                           "_______________|"
                           "_______________|"
                           "_______________|";
    char line[50] = "_________________________________________________";
    /*METODOS*/
public:

    void DatosPrimitivos();
    void DatoEstructurado();
    void MostrarMenu();
    void RellenarMatriz(matrices [MAX][MAX]);
    void MostrarMatriz(matrices [MAX][MAX]);
    void Separacion_();
    void SumaYProducto(matrices [MAX][MAX], matrices [MAX][MAX]);
};

#endif // MENU_H
