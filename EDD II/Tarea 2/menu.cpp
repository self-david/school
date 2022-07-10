#include "menu.h"

using namespace std;

void Menu::menu() {
        int option = 0;
        string code;
        cout << "\t\t\t.:BIENVENIDO:." << endl;
        do {
                cout << OptionCreate << ".- Agregar producto " << endl
                     << OptionAdd << ".- Actualizar existencia de producto " << endl
                     << OptionRemov << ".- Vender producto " << endl
                     << OptionSearch << ".- Mostrar productos " << endl
                     << OptionOut << " .- Salir"<<endl
                     <<"Elige una opcion: ";
                cin >> option;
                cin.ignore();

                switch (option) {
                        case OptionCreate:
                                inventario.addProduct();
                                break;
                        case OptionAdd:
                                cout << "introduce el codigo para agregar elementos del producto: ";
                                cin >> code;
                                inventario.Add(code);
                                break;
                        case OptionRemov:
                                cout << "introduce el codigo para retirar elementos del producto: ";
                                cin >> code;
                                inventario.Remove(code);
                                break;
                        case OptionSearch:
                                inventario.print();
                                break;
                        case OptionOut:
                                break;
                        default:
                         cout<<"Dato no valido "<<endl;
                                break;


                }
        } while(option != OptionOut);
}
