#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << 1 + ceil(log2(n));
  return 0;
}