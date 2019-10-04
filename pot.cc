#include <iostream>

using namespace std;

int pow(int x, int y) {
  int ans = 1;
  for (int i = 0; i < y; ++i)
    ans *= x;
  return ans;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    ans += pow(d / 10, d % 10);
  }
  cout << ans;
  return 0;
}