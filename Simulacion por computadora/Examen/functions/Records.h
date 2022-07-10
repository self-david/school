string giant_nums(int number, int piece) {
  vector<vector<string>> numbers = {
    {
      "XXXX ",
      "X  X ",
      "X  X ",
      "X  X ",
      "XXXX "
    },
    {
      " XX  ",
      "  X  ",
      "  X  ",
      "  X  ",
      " XXX "
    },
    {
      "XXXX ",
      "   X ",
      "XXXX ",
      "X    ",
      "XXXX "
    },
    {
      " XXX ",
      "   X ",
      " XXX ",
      "   X ",
      " XXX "
    },
    {
      "X  X ",
      "X  X ",
      "XXXX ",
      "   X ",
      "   X "
    },
    {
      "XXXX ",
      "X    ",
      "XXXX ",
      "   X ",
      "XXXX "
    },
    {
      "XXXX ",
      "X    ",
      "XXXX ",
      "X  X ",
      "XXXX "
    },
    {
      "XXXX ",
      "   X ",
      "  XX ",
      "   X ",
      "   X "
    },
    {
      "XXXX ",
      "X  X ",
      "XXXX ",
      "X  X ",
      "XXXX "
    },
    {
      "XXXX ",
      "X  X ",
      "XXXX ",
      "   X ",
      "   X "
    }
  };

  return numbers[number][piece];
}




void Records(int n, int x, int y) {
  string str = to_string(n);

  for(int i = 0; i < str.length(); i++) {
    int number = (int)str[i] - 48;
    for(int j = 0; j < 5; j++) {
      gotoxy(x, y+j);
      // cout << "giant_nums(number, j)}";
      cout << giant_nums(number, j);
      // cout << number << " " << j << endl;
    }
    // cout << str;
    x += 5;
  }
}
