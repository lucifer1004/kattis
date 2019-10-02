#include <iostream>

using namespace std;

int flip(string &s) {
  int n = s.size();
  for (int i = 0; i < n / 2; ++i)
    swap(s[i], s[n - 1 - i]);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = ans * 10 + s[i] - '0';
  return ans;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << max(flip(a), flip(b));
}