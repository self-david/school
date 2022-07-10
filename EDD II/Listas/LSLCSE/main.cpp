#include <iostream>
#include "list.h"

using namespace std;
/*este funciona*/
int main() {
    List<string> data;

    data.insert(data.getFirst(), "1");
    /*
    data.insert(data.getLast(), "6");
    data.insert(data.getFirst(), "4");
    data.insert(data.getFirst(), "2");
    data.insert(data.getFirst(), "7");
    data.insert(data.getFirst(), "9");*/


//    cout << data.find(data.getFirst()->getData()) << endl;
/*
    cout << data.find("6") << endl;
    cout << data.find("12") << endl;*/

    cout << "Hola mundo!" << endl;

    return 0;
}
