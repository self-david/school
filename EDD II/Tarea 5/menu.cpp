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
                        showAll();
                }
                cout << optionAdd << ".- Inertar" << endl
                     << optionShow << ".- Mostrar" << endl
                     << optionFind << ".- Buscar" << endl
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
                        show(position);
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
                songs.insert(song);
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
                        songs.insertPosition(newSong, songs.before(position));
                        option = "0";
                } else if(option == "2") {
                        songs.insertPosition(newSong, songs.after(position));
                        option = "0";
                } else {
                        cout << "Opcion invalida" << endl;
                }
        } while(option != "0");
}

void Menu::show(const int &position) {
        if(songs.empty()) {
                cout << "La lista esta vacia" << endl;
        } else {
                cin.ignore();
                cout << "Titulo: "
                     << songs.show(position).getTitle() << endl
                     << "Autor: "
                     << songs.show(position).getAuthor() << endl
                     << "Interprete: "
                     << songs.show(position).getInterprete() << endl
                     << "Duracion: "
                     << songs.show(position).getDuration() << endl
                     << "Posicion en Rangking: "
                     << songs.show(position).getRanking() << endl;
        }
}

void Menu::showAll() {
        cout << "Pocicion| Titulo\t\t| Autor\t\t\t| Interprete\t\t| Duracion | Ranking |" << endl;
        for (int i = 0; i <= songs.last(); i++) {
                for (int i=0;i<102;i++) {
                        cout << "_";
                }
                gotoxy(3, i+2);
                cout << i;
                gotoxy(8, i+2);
                cout << "| ";
                cout << songs.show(i).getTitle();
                gotoxy(32, i+2);
                cout << "| ";
                cout << songs.show(i).getAuthor();
                gotoxy(56, i+2);
                cout << "| ";
                cout << songs.show(i).getInterprete();
                gotoxy(80, i+2);
                cout << "| ";
                cout << songs.show(i).getDuration();
                gotoxy(91, i+2);
                cout << "| ";
                gotoxy(96, i+2);
                cout << songs.show(i).getRanking();
                gotoxy(101, i+2);
                cout << "|" << endl;
        }
        cout << endl;
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

void Menu::gotoxy(int x, int y) {
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon, dwPos);
}

void Menu::findL() {
    string name, interprete;
    int option;
    bool no = false;

    cout << "Busqueda lineal" << endl
         << "1.- nombre" << endl
         << "2.- interprete" << endl;
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            cout << "dame el nombre: " << endl;
            getline(cin, name);

            for (int i = 0; i <= songs.last(); i++) {
                if(songs.show(i).getTitle() == name) {
                    show(i);/*la cancion encontrada*/
                }
            }
            if(!no) {
                cout << "no se encontro la cancion" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << "dame el interprete: ";
            getline(cin, interprete);

            for (int i = 0; i <= songs.last(); i++) {
                if(songs.show(i).getInterprete() == interprete) {
                    show(i);/*la cancion encontrada*/
                }
            }
            if(!no) {
                cout << "no se encontro la cancion" << endl;
                system("pause");
            }
            break;
    }
}

void Menu::findB() {
    string name, interprete;
    int option, i(0), j(songs.last()), m;
    bool no = false;

    cout << "Busqueda binaria" << endl
         << "1.- nombre" << endl
         << "2.- interprete" << endl;
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            cout << "dame el nombre: " << endl;
            getline(cin, name);

            while(i <= j) {
                m = (i+j) / 2;

                if(songs.show(m).getTitle() == name) {
                    show(m);
                    no = true;
                }
                if(name < songs.show(m).getTitle()) {
                    j = m-1;
                } else {
                    i = m+1;
                }

            }
            if(!no) {
                cout << "no se encontro la cancion" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << "dame el interprete: ";
            getline(cin, interprete);

            while(i <= j) {
                m = (i+j) / 2;

                if(songs.show(m).getInterprete() == interprete) {
                    show(m);
                    no = true;

                }
                if(name < songs.show(m).getInterprete()) {
                    j = m-1;
                } else {
                    i = m+1;
                }

            }
            if(!no) {
                cout << "no se encontro la cancion" << endl;
                system("pause");
            }
            break;
    }
}

//    songs.findDataL();
