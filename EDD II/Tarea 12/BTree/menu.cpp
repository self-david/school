#include "menu.h"
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

Menu::Menu() { }

void Menu::generated(size_t i) {
    for (i; i > 0; i--) {
        tree.insert(random());
    }
}

void Menu::selectOption() {
    string option;
    size_t rand;

    do {
    cout << "\t\t\t\t\t\t\t.:MENU:." << endl
         << generate <<".- generar numeros aleatorios" << endl
         << preorder << ".- mostrar en preorden" << endl
         << inorder  << ".- mostrar en inorden" << endl
         << postorder<< ".- mostrar en postorden" << endl
         << "escoje una opcion: ";
    getline(cin, option);

    switch (option[0]) {
        case '1':
            tree.clear();
            cout << "cuantos numeros quieres generar: ";
            cin >> rand;
            cin.ignore();
            generated(rand);
            break;
        case '2':
            tree.prePrint();
            break;

        case '3':
            tree.inPrint();
        break;

        case '4':
            tree.postPrint();
            break;
        case '5':
            cout << "adios" << endl;
        break;
        default:
            cout << "valor incorrecto" << endl;
    }
    } while (option != to_string(close));
}

long Menu::random() {
    std::default_random_engine engine{std::chrono::steady_clock::now().time_since_epoch().count()};
    std::uniform_int_distribution<int> range{0, 1000000};

    long random_generated = range(engine);
    return random_generated;
}
