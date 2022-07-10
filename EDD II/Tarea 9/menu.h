#ifndef MENU_H
#define MENU_H

#include "list.h"
#include "songs.h"

class Menu {
private:
        List<Songs> songs;/*lista de canciones*/
        Songs song; /*back de la cancion a agregar*/

public:
        Menu();

        void add();
        void addPosition(const Songs &);
        void erase();
        void findL();
        void findB();
        void order();
        void change(const int &);

        enum Options {
                optionAdd = 1,
                optionShow,
                optionFind,
                optionErase,
                optionOut
        };
};

#endif // MENU_H
