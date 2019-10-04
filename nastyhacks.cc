#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (b - c > a)
      cout << "advertise";
    else if (b - c == a)
      cout << "does not matter";
    else
      cout << "do not advertise";
    cout << endl;
  }
  return 0;
}