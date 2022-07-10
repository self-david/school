#include <iostream>
#include <vector>
using namespace std;

string getStringPreformat(string str, int length)
{
  string ret = "";
  for (size_t i = 0; i <= length; i++)
  {
    if (str.size() < i)
    {
      ret += " ";
      // cout << str[i];
    }
    else
    {
      ret += str[i];
    }
  }
  return ret;
}

int table(string title, vector<string> header, vector<vector<string>> content, int x, int y, int aux)
{
  string lineText = title + "\n";
  string lineTop = "";
  string lineCenter = "";
  string lineBottom = "";

  // entregar valores iniciales
  lineTop += char(218);
  lineCenter += char(195);
  lineBottom += char(192);

  // imprimir Titulo
  gotoxy(x, y++);
  cout << lineText;
  lineText = char(179);

  for (size_t i = 0; i < header.size(); i++)
  {
    for (size_t j = 0; j < header[i].size(); j++)
    {
      lineTop += char(196);
      lineCenter += char(196);
      lineBottom += char(196);
    }
    lineTop += i == header.size() - 1 ? char(191) : char(194);
    lineCenter += i == header.size() - 1 ? char(180) : char(197);
    lineBottom += i == header.size() - 1 ? char(217) : char(193);
    lineText += header[i] + char(179);
  }

  // imprimir linea superior
  gotoxy(x, y++);
  cout << lineTop;
  // imprimir encabezado
  gotoxy(x, y++);
  cout << lineText;
  gotoxy(x, y++);
  cout << lineCenter;
  lineText = char(179);

  // imprimir contenido
  for (size_t i = 0; i < content.size(); i++)
  {

    for (size_t j = 0; j < aux; j++)
    {
      int length = header[j].size();
      lineText += getStringPreformat(content[i][j], length) + char(179);
    }
    gotoxy(x, y++);
    cout << lineText;
    if (i < content.size() - 1)
    {
      gotoxy(x, y++);
      cout << lineCenter;
    }
    lineText = char(179);
  }

  gotoxy(x, y++);
  cout << lineBottom;

  return y;
}
