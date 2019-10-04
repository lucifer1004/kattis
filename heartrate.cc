#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    double b, p;
    cin >> b >> p;
    cout << (b - 1) * 60 / p << " " << b * 60 / p << " " << (b + 1) * 60 / p
         << endl;
  }
  return 0;
}