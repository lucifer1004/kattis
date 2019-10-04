#include <iostream>

using namespace std;

int main() {
  int a = 0, b = 0;
  for (int i = 0; i < 3; ++i) {
    int x, y;
    cin >> x >> y;
    a ^= x;
    b ^= y;
  }
  cout << a << " " << b;
  return 0;
}