#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int t = 1 << n;
  cout << (t + 1) * (t + 1);
  return 0;
}