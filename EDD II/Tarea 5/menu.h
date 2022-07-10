#ifndef MENU_H
#define MENU_H

#include "list.h"
#include "list.cpp"
#include "songs.h"

class Menu {
private:
        List<Songs> songs;/*lista de canciones*/
        Songs song; /*back de la cancion a agregar*/

public:
        Menu();

        void add();
        void addPosition(const Songs &);
        void show(const int &);
        void showAll();
        void erase();
        void gotoxy(int, int);
        void findL();
        void findB();

        enum Options {
                optionAdd = 1,
                optionShow,
                optionFind,
                optionErase,
                optionOut
        };
};

#endif // MENU_H
