#ifndef MENU_H
#define MENU_H
#include "stack.h"
#include "stack.cpp"
#include "queue.h"
#include "queue.cpp"
#include <iostream>

class Menu {
public:
    Menu();
    void converter(const std::string &);
    bool operatorValid(const char &);
    int precedencia(const char &);
};
#endif // MENU_H
