#include "menu.h"

using namespace std;

Menu::Menu() { }

void Menu::init() {
    char option;
    long start, finish;

    do{
        cout << "\t\t\t\t\t.:ORDENAMINETO DE DATOS ALEATORIOS:." << endl
                  << "1.Ordenamiento Burbuja" << endl
                  << "2.Ordenamiento Seleccion" << endl
                  << "3.Ordenamiento Insersion" << endl
                  << "4.Ordenamiento Shell" << endl
                  << "5.Ordenamiento MergeSort "<< endl
                  << "6.Ordenamiento QuickSort" << endl
                  << "7.Salir" << endl
                  <<"Elige una opcion : ";
        cin >> option;

        Order<Rand, 10000> numeros;/*genero los numeros aleatorios*/
        start = clock();/*inicializo el conteo del tiempo*/

        switch (option) {
            case '1': numeros.bubble();
            break;

            case '2': numeros.select();
            break;

            case '3': numeros.insert();
            break;

            case '4': numeros.shell();
            break;

            case '5': numeros.merge();
            break;

            case '6': numeros.quick();
            break;


            case '7': cout << "Fin del programa." << endl;
            break;

        default: cout << "introduce un dato valido" << endl;
        }

        if(option > '0' and option < '7') {/*asi solo me arroja el tiempo cuando uso algun metodo de ordenamiento*/
            finish = clock();/*despues de terminar el ordenamiento cuenta el tiempo de nuevo*/
            numeros.print();/*imprime los numero*/
            double time = (double(finish-start)/CLOCKS_PER_SEC);
            cout << "el tiempo consumido en segundos es: " << time << endl;
        }
    } while (option != '7');
}
