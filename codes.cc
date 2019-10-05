#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

const int LEN = 15;

typedef bitset<LEN> bs;

int mul(vector<bs> mat, bs col) {
  int ans = 0;
  for (const bs &row : mat) {
    int res = 0;
    for (int j = 0; j < LEN; ++j)
      res += row[j] * col[j];
    ans += (res & 1);
  }
  return ans == 0 ? LEN : ans;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<bs> mat(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j) {
      int d;
      cin >> d;
      if (d)
        mat[i].set(k - j - 1);
    }

  int ans = n;
  for (int i = 0; i < (1 << k); ++i) {
    bs col(i);
    ans = min(ans, mul(mat, col));
    if (ans == 1)
      break;
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