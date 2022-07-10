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
                    cout << songs.toString();
                }
                cout << optionAdd << ".- Insertar" << endl
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
                        cout << endl << "Pocicion| Titulo\t\t| Autor\t\t\t| Interprete\t\t| Duracion | Ranking |" << endl;
//                        songs.print(songs.retrieve(*songs.find()));
                        system("pause");
                        break;

                        case optionFind: findL();
                        break;

                        case optionErase: erase();
                        break;

                        case optionOut:
                        break;

                        default:
                        cout << "valor invalido";
                }
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
                songs.insert(songs.getFirst(), song);
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
                        songs.insert(songs.getFirst(), newSong);
                        option = "0";
                } else if(option == "2") {
                        songs.insert(songs.getNext(songs.getFirst()), newSong);
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
                string position;
                cout << "Ingresa la cancion a eliminar:";
                getline(cin, position);
                cin.ignore();
                songs.erase(songs.find(song));
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
//    songs.print(songs.find(song));
    cout << songs.retrieve(songs.find(song));
    system("pause");
}

//void Menu::change(const int &e) {
//    for (int i(0) ;i <= songs.getLast() ;i++) {
//        songs[i].setOrder(e);
//    }
//    system("pause");
//}
