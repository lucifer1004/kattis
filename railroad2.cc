#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  cout << (y % 2 ? "impossible" : "possible");
  return 0;
}