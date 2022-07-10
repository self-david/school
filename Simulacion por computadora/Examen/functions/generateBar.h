#include <vector>
using namespace std;


vector<vector<int>> Bars(vector<vector<string>> content, int width) {
  vector<vector<int>> bars;
  int max_length = 0;

  // obtener lalongitud maxima de la barra
  for (int i = 0; i < content.size(); i++) {
    int begin = stoi(content[i][1]);
    int duracion = stoi(content[i][2]);
    if(begin + duracion > max_length) {
      max_length = begin + duracion;
    }
  }
  
  for (int i = 0; i < content.size(); i++) {
    int begin = stoi(content[i][1]);
    int duracion = stoi(content[i][2]);
    vector<int> bar;
    for (int j = 0; j < width; j++) {
      int nj = j*max_length/width;
      if(nj >= begin and nj < begin + duracion) {
        bar.push_back(1);
      } else {
        bar.push_back(0);
      }
    }
      cout << endl;
    bars.push_back(bar);
  }

  return bars;
}