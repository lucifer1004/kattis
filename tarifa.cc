#include <iostream>

using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  int ans = x * (n + 1);
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    ans -= d;
  }
  cout << ans;
  return 0;
}