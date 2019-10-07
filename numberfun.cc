#include <iostream>

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b)
    swap(a, b);
  if (a + b == c || a - b == c || a * b == c || (a % b == 0 && a / b == c))
    cout << "Possible";
  else
    cout << "Impossible";
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    solve();
  return 0;
}