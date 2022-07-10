
// #include "goto.h"
using namespace std;

int Box(struct Rectangle rect)
{
  string str = "";
  int x = rect.x;
  int y = rect.y;
  // imprimir titulo
  gotoxy(x, y++);
  cout << rect.title;
  // imprimir contenido
  for (size_t i = 0; i < rect.height; i++)
  {

    for (size_t j = 0; j < rect.width; j++)
    {
      if (i == 0 || j == 0 || i == rect.height - 1 || j == rect.width - 1)
      {
        if (i == 0 && j == 0)
        {
          // Esquina superior izquierda
          str += char(218);
        }
        else if (i == 0 && j == rect.width - 1)
        {
          // esquina superior derecha
          str += char(191);
        }
        else if (i == rect.height - 1 && j == 0)
        {
          // esquina inferior izquierda
          str += char(192);
        }
        else if (i == rect.height - 1 && j == rect.width - 1)
        {
          // esquina inferior derecha
          str += char(217);
        }
        else if (i == 0 || i == rect.height - 1)
        {
          // border superior e inferior centreal
          str += char(196);
        }
        else if (j == 0 || j == rect.width - 1)
        {
          // border izquierda y derecha
          str += char(179);
        }
        else
        {
          // border centro
          str += char(196);
        }
      }
      else
      {
        str += " ";
      }
    }
    gotoxy(x, y++);
    cout << str;
    str = "";
  }

  return y;
}

void DrawProgress(struct Rectangle rect, int max_value)
{
  gotoxy(rect.x + 1, rect.y + rect.height + 1);
  cout << 0;
  gotoxy(rect.x + (rect.width - to_string(max_value).length()) / 2, rect.y + rect.height + 1);
  cout << max_value / 2;
  gotoxy(rect.x + rect.width - to_string(max_value).length(), rect.y + rect.height + 1);
  cout << max_value;
}