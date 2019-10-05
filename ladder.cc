#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int h, v;
  cin >> h >> v;
  cout << ceil((double)h / sin((double)v / 180 * M_PI));
  return 0;
}