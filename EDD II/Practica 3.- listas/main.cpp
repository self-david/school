#include "list.h"
#include "list.cpp"
#include <iostream>

using namespace std;

int main() {
    List<int, 23> mylista;


//    for (int i=0 ; i < 20; ++i(0)) {
//        data = intDice();
//        cout << "insertando: " << data << endl;
//        mylista.insertData(mylista.getLastPos(), data);
//    }

    for (int i = 0; i < 10 ;i++) {
        mylista.insertaData(mylista.getLastPos(), i);
    }
    cout << endl << endl << endl;
    cout << "contenido de la lista: " << endl;
//    mylista.print();
}
