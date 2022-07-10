#ifndef MENU_H
#define MENU_H

#include <inventario.h>
#include <iostream>

class Menu {
        Inventario inventario;
public:
        enum Options {
                OptionCreate = 1,
                OptionAdd,
                OptionRemov,
                OptionSearch,
                OptionOut
        };
        void menu();

};

#endif // MENU_H
