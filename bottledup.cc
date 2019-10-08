#include <iostream>

using namespace std;

int main() {
  int s, a, b;
  cin >> s >> a >> b;
  int na = s / a, nb = 0;
  for (int i = s / a; i >= 0; --i)
    if ((s - i * a) % b == 0) {
      cout << i << " " << (s - i * a) / b;
      return 0;
    }
  cout << "Impossible";
  return 0;
}