#include <iostream>

using namespace std;

int main() {
  int a = 1, b = 0, c = 0;
  string ops;
  cin >> ops;
  for (const char &op : ops) {
    if (op == 'A')
      swap(a, b);
    if (op == 'B')
      swap(b, c);
    if (op == 'C')
      swap(a, c);
  }
  if (a)
    cout << 1;
  if (b)
    cout << 2;
  if (c)
    cout << 3;
  return 0;
}