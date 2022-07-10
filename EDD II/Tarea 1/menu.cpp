#include "menu.h"
#include <iostream>
#include <limits>
#include <float.h> /*buscar*/

using namespace std;


void Menu::MostrarMenu() {
    bool salir = false;
    char option;

    do {
             cout<<"\n\n\tMenu:";
             cout<< "\n\n\tA) Tama"<<char(164)<<"o y rangos de los Tipos de Dato Primitivos.";
             cout<< "\n\n\tB) Ejemplo de uso de Tipo de dato Estructurado.";
             cout<< "\n\n\tC) Salir.";
             cout<< "\n\n\tOpci"<<char(162)<<"n a elegir: ";
             cin >> option;

        switch (option) {
            case 'A':
                DatosPrimitivos();
                break;
            case 'B':
                DatoEstructurado();
                break;
            case 'C':
                salir = true;
                break;
            default:
                cout << "\n\n\tOpci"<<char(162)<<"n no v"<<char(160)<<"lida, por favor escoja una v"<<char(160)<<"lida\n\n\n\t";
        }
        system ("pause");
        system ("cls");
    } while(!salir);
}

void Menu::DatosPrimitivos() {
    std::cout << Separacion << std::endl
              << system("cls")
            <<"| \tTIPO DE DATO\t | \tBITS\t | VALOR MINIMO  |  VALOR MAXIMO |\n"
            << Separacion << std::endl

            <<"|Caracter con signo      |\t" << sizeof(char) <<"\t |\t"
            << SCHAR_MIN << " \t |\t" << SCHAR_MAX  << "\t |" << std::endl
            << Separacion << std::endl

            <<"|Caracter sin signo      |\t"<< sizeof(unsigned char) <<"\t |\t"
            << 0 << " \t |\t" << UCHAR_MAX  << "\t |" << std::endl
            << Separacion << std::endl

            <<"|Entero corto con signo  |\t"<< sizeof(short) <<"\t |\t"
            << SHRT_MIN << " \t |\t" << SHRT_MAX  << "\t |" << std::endl
            << Separacion << std::endl

            <<"|Entero corto sin signo  |\t"<< sizeof(unsigned short) <<"\t |\t"
            << 0 << " \t |\t" << USHRT_MAX  << "\t |" << std::endl
            << Separacion << std::endl

            <<"|Entero largo con signo  |\t"<< sizeof(long) <<"\t | "
           << LONG_MIN << "   |   " << LONG_MAX  << "  |" << std::endl
            << Separacion << std::endl

            <<"|Entero largo sin signo  |\t"<< sizeof(unsigned long int) <<"\t |\t"
           << 0 << " \t |   " << ULONG_MAX  << "  |" << std::endl
            << Separacion << std::endl

            <<"|Real de precisi"<<char(162)<<"n simple|\t"<< sizeof(float) <<"\t | "
            << FLT_MIN << "  |  " << FLT_MAX  << " |" << std::endl
            << Separacion << std::endl

            <<"|Real de precisi"<<char(162)<<"n doble |\t"<< sizeof(double) <<"\t |  "
            << DBL_MIN << " |  " << DBL_MAX  << " |" << std::endl
            << Separacion << std::endl;
}

void Menu::DatoEstructurado() {
    do {
        std::cout << "Tama"<<char(164)<<"o de Matriz: ";
        std::cin >> TamMatriz;
        if ((TamMatriz<3)||(TamMatriz>10)) {
            std::cout<< "Dato no valido"<< std::endl;
            std::cout<<"El tamaño de la matriz debe ser como minimo y como maximo 10\n";
        }
    }while(TamMatriz<3 || TamMatriz>10);

    RellenarMatriz(Matriz_1);
    RellenarMatriz(Matriz_2);

    /*Mostrando Matrices de nxn*/
    std::cout<<"\t\tMatriz 1"<< std::endl;
    MostrarMatriz(Matriz_1);
    std::cout << line << std::endl;

    std::cout <<"\t\tMatriz 2"<< std::endl;
    MostrarMatriz(Matriz_2);
    std::cout << line << std::endl;

    SumaYProducto(Matriz_1, Matriz_2);


    /*MOSTRANDO RESULTADOS DE LAS OPERACIONES CON MATRICES*/
    std::cout << "\t\tMultiplicacion de entre Matriz 1 y Matriz 2 : " << std::endl;
    MostrarMatriz(productoMatriz);

    std::cout << line << std::endl;
    std::cout<<"\t\tSuma de Matriz 1 Y Matriz 2 \n";
    MostrarMatriz(sumaMatriz);
}

void Menu::RellenarMatriz(matrices matriz[MAX][MAX]) {
    for(int i=0;i<TamMatriz;i++) {
        for(int j=0;j<TamMatriz;j++) {
            matriz[i][j].setMatriz();
        }
    }
}

void Menu::MostrarMatriz(matrices matriz[MAX][MAX]) {
    for(int i=0;i<TamMatriz;i++) {
        for(int j=0;j<TamMatriz;j++){
            std::cout << matriz[i][j].getMatriz() <<" ";
        }
        std::cout << std::endl;
    }
}

void Menu::SumaYProducto(matrices matriz1[MAX][MAX], matrices matriz2[MAX][MAX]) {
    for(int i=0;i<TamMatriz;i++){
        for(int j=0;j<TamMatriz;j++) {
           productoMatriz[i][j].setMatrizMult(matriz1[i][j].getMatriz(), matriz2[i][j].getMatriz());
           sumaMatriz[i][j].setMatrizSuma(matriz1[i][j].getMatriz(), matriz2[i][j].getMatriz());
        }
    }
}
