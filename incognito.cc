#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
  int n;
  cin >> n;

  unordered_map<string, int> cnt;
  for (int i = 0; i < n; ++i) {
    string item, category;
    cin >> item >> category;
    cnt[category]++;
  }
  int ans = 1;
  for (const auto &p : cnt)
    ans *= p.second + 1;
  cout << ans - 1 << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}