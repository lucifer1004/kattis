#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    cout << d << " is " << (d % 2 == 0 ? "even" : "odd") << endl;
  }
  return 0;
}