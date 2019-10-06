#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  int ans = max(a, c);
  int day = 1;
  for (int i = 3; i < n; ++i) {
    int d;
    cin >> d;
    a = b;
    b = c;
    c = d;
    if (ans > max(a, c)) {
      ans = max(a, c);
      day = i - 1;
    }
  }
  cout << day << " " << ans;
  return 0;
}