#include "menu.h"
#include <windows.h>

using namespace std;

Menu::Menu() {
        int option;

        do{
                system("cls");
                cout << "\t\t\t\t\t\t .:MENU:." << endl;
                if(songs.empty()) {
                        cout << "\t\t\t\t\t      .:LISTA VACIA:." << endl;
                } else {
                    cout << "Pocicion| Titulo\t\t| Autor\t\t\t| Interprete\t\t| Duracion | Ranking |" << endl;
                    songs.showAll();
                }
                cout << optionAdd << ".- Insertar" << endl
                     << optionShow << ".- Mostrar" << endl
                     << optionFind << ".- Buscar" << endl
                     << optionOrder << ".- Ordenar" << endl
                     << optionErase << ".- Borrar" << endl
                     << optionOut << ".- salir" << endl
                     << "Elige una opcion: ";
                cin >> option;
                cin.ignore();

                switch (option) {
                        case optionAdd: add();
                        break;

                        case optionShow:
                        int position;
                        cout << "Ingresa el numero de cancion a mostrar: ";
                        cin >> position;
                        cout << endl << "Pocicion| Titulo\t\t| Autor\t\t\t| Interprete\t\t| Duracion | Ranking |" << endl;
                        songs.show(position);
                        system("pause");
                        break;

                        case optionFind:
                            cout << "tu busqueda es" << endl
                                 << "1.- lineal" << endl
                                 << "2.- binaria" << endl;
                            cin >> option;
                            cin.ignore();
                            switch (option) {
                                case 1:
                                findL();
                                break;

                                case 2:
                                findB();
                                break;

                            }
                        break;

                        case optionOrder: order();
                        break;

                        case optionErase: erase();
                        break;

                        case optionOut:
                        break;

                        default:
                        cout << "valor invalido";
                }
//        system("pause");
        } while(option != optionOut);
}

void Menu::add() {
        string data;
        int ranking, position = 0;
        cout << "Nombre de la cancion: ";
        getline(cin, data);
        song.setTitle(data);
        cout << "Nombre del autor: ";
        getline(cin, data);
        song.setAuthor(data);
        cout << "Nombre del interprete: ";
        getline(cin, data);
        song.setInterprete(data);
        do{
                cout << "\n formato '01:23'\nDuracion de la cancion: ";
                getline(cin, data);
        } while(!song.validTime(data));
        song.setDuration(data);
        cout << "Posicion del ranking: ";
        cin >> ranking;/*por validar*/
        song.setRanking(ranking);
        cin.ignore();
        if(!songs.empty()) {
                cout << "desea escojer el punte de inserccion, 1/0: ";
                cin >> position;
                cin.ignore();
        }
        if(position == 1) {
                addPosition(song);
        } else {
                songs.append(song);
        }
}

void Menu::addPosition(const Songs &newSong) {
        int position;
        string option;
        do {
                cout << "Posicion de interes: ";
                cin >> position;/*por validar*/
                cout << "1.- antes del punto de interes" << endl
                     << "2.- Despues del punto de interes" << endl
                     << "opcion: ";
                cin >> option;
                if(option == "1") {
                        songs.append(newSong, songs.before(position));
                        option = "0";
                } else if(option == "2") {
                        songs.append(newSong, songs.after(position));
                        option = "0";
                } else {
                        cout << "Opcion invalida" << endl;
                }
        } while(option != "0");
}

void Menu::erase() {
        if(songs.empty()) {
                cout << "La lista esta vacia" << endl;
        } else {
                int position;
                cout << "Ingresa la posicion del dato a eliminar:";
                cin >> position;
                cin.ignore();
                songs.erase(position);
        }

}

void Menu::findL() {
    string name, interprete;
    int option;

    cout << "Busqueda lineal" << endl
         << "1.- nombre" << endl
         << "2.- interprete" << endl;
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            cout << "dame el nombre: " << endl;
            getline(cin, name);
            song.setTitle(name);
            break;

        case 2:
            cout << "dame el interprete: ";
            getline(cin, interprete);
            song.setInterprete(interprete);
            song.setOrder(option);/*con esto analiza el interprete en vez del titulo*/
            break;
    }
    songs.show(songs.findDataL(song));
    system("pause");
}

void Menu::findB() {
    string name, interprete;
    int option;

    cout << "Busqueda binaria" << endl
         << "1.- nombre" << endl
         << "2.- interprete" << endl;
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            cout << "dame el nombre: " << endl;
            getline(cin, name);
            song.setTitle(name);
            songs.findDataB(song);

            break;
        case 2:
            cout << "dame el interprete: ";
            getline(cin, interprete);
            song.setInterprete(interprete);
            song.setOrder(option);/*con esto analiza el interprete en vez del titulo*/
            break;
    }
    songs.show(songs.findDataB(song));
    system("pause");
}

void Menu::order() {
    string name, interprete;
    int option;

    cout << "ordenar lista" << endl
         << "1.- titulo" << endl
         << "2.- interprete" << endl;
    cin >> option;
    cin.ignore();
    switch (option) {
        case 1:
            change(0);/*asigna al titulo como valor a comparar*/
        break;
        case 2:
            change(1);/*asigna al interprete como valor a comparar*/
        break;
    }
    cout << "que metodo de ordenamiento quieres utilizar" << endl
         << "1.- bubleSort" << endl
         << "2.- shellSort" << endl
         << "3.- insertionSort" << endl
         << "4.- selectSort" << endl;
    cin >> option;
    cin.ignore();
    switch (option) {
        case 1: songs.bubbleSort();
        break;

        case 2: songs.shellSort();
        break;

        case 3: songs.insertionSort();
        break;

        case 4: songs.selectSort();
        break;
    }
}

void Menu::change(const int &e) {
    for (int i(0) ;i <= songs.last() ;i++) {
        songs[i].setOrder(e);
    }
    system("pause");
}
