#include <iostream>

using namespace std;

int main() {
  int l, x;
  cin >> l >> x;
  int cnt = 0, curr = 0;
  for (int i = 0; i < x; ++i) {
    string s;
    int p;
    cin >> s >> p;
    if (s == "leave")
      curr -= p;
    else if (curr + p <= l)
      curr += p;
    else
      cnt++;
  }
  cout << cnt;
  return 0;
}