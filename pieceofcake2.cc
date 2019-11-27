#include <iostream>

using namespace std;

int main() {
  int n, h, v;
  cin >> n >> h >> v;
  cout << max(n - h, h) * max(n - v, v) * 4;
  return 0;
}