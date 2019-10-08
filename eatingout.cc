#include <iostream>

using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  cout << (a + b + c > n * 2 ? "impossible" : "possible");
  return 0;
}