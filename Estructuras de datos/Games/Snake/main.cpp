#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define ANCHURA 100
#define ALTURA 28
static short COLA = 10;

struct Cursor { short x, y; };

void Gotoxy(Cursor cursor) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = cursor.x;
    dwPos.Y = cursor.y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void cursor_visible(bool visible) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    if(visible) {
        cci.bVisible = true;
        cci.dwSize = 100;
    } else {
        cci.bVisible = false;
        cci.dwSize = 1;
    }
    SetConsoleCursorInfo(hcon,&cci);

}

void dibujar_bordes() {
    Cursor cursor;
    for (short i = 0; i < ANCHURA+1; i++) {
        for (short j = 0; j < ALTURA+1; j++) {
            if(i == 0 or i == ANCHURA) {
                cursor.x = i;
                cursor.y = j;
                Gotoxy(cursor);
                cout << char(186);
            }
            if(j == 0 or j == ALTURA) {
                cursor.x = i;
                cursor.y = j;
                Gotoxy(cursor);
                cout << char(205);
            }
        }
        Gotoxy({0,0});
        cout << char(201);

        Gotoxy({ANCHURA, 0});
        cout << char(187);

        Gotoxy({0, ALTURA});
        cout << char(200);

        Gotoxy({ANCHURA, ALTURA});
        cout << char(188);
    }
}

void mover(Cursor vibora[], char tecla) {
    for (short i = COLA; i > 0; i--) {
        vibora[i].x = vibora[i-1].x;
        vibora[i].y = vibora[i-1].y;
    }
    if(tecla == ARRIBA) {
        if(vibora[0].y == 1) { vibora[0].y = ALTURA-1; }
        else                { vibora[0].y--; }
    }
    if(tecla == ABAJO) {
        if(vibora[0].y == ALTURA-1) { vibora[0].y = 1; }
        else                     { vibora[0].y++; }
    }
    if(tecla == IZQUIERDA) {
        if(vibora[0].x == 1) { vibora[0].x = ANCHURA-1; }
        else              { vibora[0].x--; }
    }
    if(tecla == DERECHA) {
        if(vibora[0].x == ANCHURA-1) { vibora[0].x = 1; }
        else                      { vibora[0].x++; }
    }
}

void nueva_comida(Cursor &comida) {
    comida.x = rand()%(ANCHURA-1)+1;
    comida.y = rand()%(ALTURA-1)+1;
    Gotoxy(comida);
    cout << char(64);
}

void dibujar(Cursor vibora[]) {
    Gotoxy(vibora[COLA]);
    cout << " ";
    if(COLA > 0) {
        Gotoxy(vibora[1]);
        cout << char(177);
    }
    Gotoxy(vibora[0]);
    cout << char(219);
}

bool colision(Cursor a, Cursor b) {
    if(a.x == b.x and a.y == b.y) { return true; }
    return  false;
}

int main() {
    cursor_visible(false);
    dibujar_bordes();
    bool gameover = false;

    Cursor vibora[20], comida;
    vibora[0].x = rand()%ANCHURA;
    vibora[0].y = rand()%ALTURA;
    nueva_comida(comida);

    dibujar(vibora);
    char tecla = '\0';
    bool anterior = false;
    Gotoxy({ANCHURA+2, 0});
    cout << "puntos: " << COLA*3+2;

    while (!gameover) {
        if(colision(vibora[0], comida)) {
            COLA++;
            vibora[COLA].x = comida.x;
            vibora[COLA].y = comida.y;
            nueva_comida(comida);
            Gotoxy({ANCHURA+10, 0});
            cout << COLA*3+2;
        }

        if(kbhit()) {
            tecla = getch();
            anterior = true;
            mover(vibora, tecla);
            dibujar(vibora);
        } else if(anterior) {
            mover(vibora, tecla);
            dibujar(vibora);
        }

        for (short i = COLA; i > 1; i--) {
            if(colision(vibora[0], vibora[i])) {
                gameover = true;
            }
        }
        Sleep(180);
    }
    cout <<"perdiste";
    return 0;
}
