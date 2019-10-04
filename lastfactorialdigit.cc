#include <iostream>

using namespace std;

const int f[11]{1, 1, 2, 6, 4, 0, 0, 0, 0, 0, 0};

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    cout << f[n] << endl;
  }
  return 0;
}