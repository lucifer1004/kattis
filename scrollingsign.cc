#include <iostream>

using namespace std;

void solve() {
  int k, w;
  cin >> k >> w;
  int ans = 0;
  string last;
  for (int i = 0; i < w; ++i) {
    string s;
    cin >> s;
    ans += k;
    if (i > 0) {
      for (int j = 0; j < k; ++j) {
        if (last[j] != s[0])
          continue;
        if (last.substr(j, k - j) == s.substr(0, k - j)) {
          ans -= k - j;
          break;
        }
      }
    }
    last = s;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}