#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    ans += x * y;
  }
  cout << ans;
  return 0;
}