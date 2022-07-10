#ifndef GOTO_H
#define GOTO_H

#include <windows.h>

class Cursor {
public:
    Cursor() { }

    void Gotoxy(int x, int y) {
            HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD dwPos;
            dwPos.X = x;
            dwPos.Y = y;
            SetConsoleCursorPosition(hcon, dwPos);
    }

    int wherex() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.dwCursorPosition.X;
    }

    int wherey() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.dwCursorPosition.Y;
    }
};

#endif // GOTO_H
