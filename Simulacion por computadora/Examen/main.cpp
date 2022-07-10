#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "functions/goto.h"
#include "functions/Rectangle.h"
#include "functions/Table.h"
#include "functions/Box.h"
#include "functions/Records.h"
#include "functions/generateBar.h"

#include <windows.h>
#include <winuser.h>
#include "wtypes.h"

using namespace std;

void draw();

bool is_number(const string &str)
{
  return str.find_first_not_of("0123456789") == string::npos;
}

bool lambda(vector<string> &vec1, vector<string> &vec2)
{
  return stoi(vec1[1]) < stoi(vec2[1]);
}

int main()
{
  int processes(-1);
  bool flag(true);
  while (processes == -1)
  {
    string str;
    system("cls");
    if (!flag)
    {
      cout << "Valor no valido, vuelva a ingresarlo \n\n";
    }
    cout << "Ingrese cantidad de procesos: ";
    cin >> str;
    if (!is_number(str) or str.length() > 6 or stoi(str) < 0 or stoi(str) > 50)
    {
      flag = 0;
    }
    else
    {
      processes = stoi(str);
    }
  }
  vector<vector<string>> content1;
  vector<vector<string>> content2;

  int MAX_VALUE = 1000000;

  int global_time = 0;
  for (int i = 0; i < processes; i++)
  {
    system("cls");
    cout << "Inicio: ";
    string start;
    cin >> start;
    if (!is_number(start) or start.length() > 6 or stoi(start) < 0 or stoi(start) > MAX_VALUE)
    {
      cout << "Valor no valido, vuelva a ingresarlo";
      i--;
      continue;
    }
    cout << "Duracion: ";
    string fin;
    cin >> fin;
    if (!is_number(fin) or fin.length() > 6 or stoi(fin) < 0 or stoi(start) + stoi(fin) > MAX_VALUE)
    {
      cout << "Valor no valido, vuelva a ingresarlo";
      i--;
      continue;
    }

    global_time = max(global_time, stoi(start) + stoi(fin));

    vector<string> c1(3);
    c1[0] = "P" + to_string(i);
    c1[1] = start;
    c1[2] = fin;
    vector<string> c2(3);
    c2[0] = "P" + to_string(i);
    c2[1] = start;
    c2[2] = fin;
    content1.push_back(c1);
    content2.push_back(c2);
  }
  sort(content2.begin(), content2.end(), lambda);

  system("cls");

  int columns, rows;
  struct Rectangle box_left = {"Control de procesos", 1, 2, 46, 0};
  struct Rectangle box_number = {"Tiempo Global", 2, 0, 0, 9};
  struct Rectangle box_right = {"Control de procesos", box_left.x + box_left.width, 2, 0, 0};
  vector<string> header1 = {"Proceso", "Inicio", "Duracion"};
  vector<string> header2 = {"Proceso", "Ejecucion"};
  getSize(columns, rows);

  box_right.height = box_left.height = content2.size() * 2 + 7 + box_number.height;
  box_right.width = columns - box_left.width - 2;
  int progress = 0;
  int size_identifier = 3 + to_string(content1.size()).length();
  int width_process = box_right.width - size_identifier; // ancho total de la barra
  vector<vector<int>> bars = Bars(content1, width_process);
  
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int total_time = global_time;
  int iterations = width_process;
  int bars_length = bars.size();
  while (iterations >= 0)
  {
    // dibujado y renderizado de la pantalla
    /* *********************************************************************************** */
    Box(box_left);
    table("Datos de los procesos:", header1, content1, 2, 4, 3);
    box_number.y = table("Orden de ejecucion:", header2, content2, 27, 4, 2);
    box_number.width = box_left.width - 2;
    Box(box_number);
    Records((iterations*total_time)/width_process, box_number.x + 2, box_number.y + 3);
    Box(box_right);
    DrawProgress(box_right, total_time);
    /* *********************************************************************************** */

    // dibujar las progressbar
    /* *********************************************************************************** */
    int x_coor = box_right.x + 1;
    int y_coor = box_right.y + 2;
    int height = (box_right.height-2) / bars_length; // obtener a partir de la altura total entre la cantidad de procesos
    for(int i = 0; i < progress; i++) {
      for(int j = 0; j < bars_length; j++) {
        for(int k = 0; k < height; k++) {  
            gotoxy(x_coor+i, y_coor+j*height+k);
            if(bars[j][i] == 1) {
              cout << char(219) << "p" << j;
            }
        }
      }
    }
    progress++;
    /* *********************************************************************************** */
    iterations--;
    Sleep(650);
  }
  gotoxy(0, box_right.y + box_right.height + 2);
  return 0;
}

/*
[1,1,1,1,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,1,1,1,1,0,0,0,0,0,0],
[0,1,1,1,0,0,0,0,1,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,1,1],
[0,0,0,0,0,0,0,0,1,1,1,1,1,1],
[0,0,0,1,1,1,1,1,0,0,0,0,0,0]
*/

/*
6
0 4
4 4
8 4
12 2
8 6
3 5
*/