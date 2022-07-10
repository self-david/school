#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "BTree.h"

class Menu {
private:
    BTree tree;

    enum option{
        generate = 1,
        preorder,
        inorder,
        postorder,
        close
    };

public:
    Menu();

    long random();

    void generated(size_t i4);

    void selectOption();


};

#endif // MENU_H
