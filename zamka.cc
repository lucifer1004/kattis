#include <iostream>

using namespace std;

int sum(int x) {
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
  int l, d, x;
  cin >> l >> d >> x;
  while (sum(l) != x)
    l++;
  while (sum(d) != x)
    d--;
  cout << l << endl;
  cout << d << endl;
  return 0;
}