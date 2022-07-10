#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List<int> data;

    data.insert(data.getFirst(), 6);
    data.insert(data.getFirst(), 7);
    data.insert(data.getFirst(), 8);
    data.insert(data.getFirst(), 3);
    data.insert(data.getFirst(), 4);



    cout << "Hola mundo!" << endl;

    return 0;
}
