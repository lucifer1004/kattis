#include <iostream>

using namespace std;
int main() {
  int h;
  string path;
  cin >> h >> path;
  int curr = 1;
  for (char c : path) {
    if (c == 'L')
      curr <<= 1;
    else
      curr = (curr << 1 | 1);
  }
  cout << (1 << (h + 1)) - curr;
}