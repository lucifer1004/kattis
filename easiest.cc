#include <iostream>

using namespace std;

typedef long long ll;

int digit_sum(ll x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n)
      break;
    int target = digit_sum(n);
    ll i = 11;
    while (digit_sum(i * n) != target)
      i++;
    cout << i << endl;
  }
  return 0;
}