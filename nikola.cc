#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
  int pos, step, sum;
};

class Solution {
  int ans = INT_MAX;

public:
  void solve() {
    int n;
    cin >> n;
    vector<int> fee(n + 1);
    for (int i = 1; i <= n; ++i)
      cin >> fee[i];
    queue<State> q;
    q.push({2, 1, fee[2]});
    vector<vector<int>> best(n + 1, vector<int>(n + 1, INT_MAX));
    best[2][1] = fee[2];
    while (!q.empty()) {
      State f = q.front();
      q.pop();
      if (f.pos == n && f.sum < ans) {
        ans = f.sum;
      } else {
        if (f.sum >= ans)
          continue;
        // Go back
        int bpos = f.pos - f.step;
        if (bpos >= 1) {
          int bfee = f.sum + fee[bpos];
          if (bfee < best[bpos][f.step]) {
            q.push({bpos, f.step, bfee});
            best[bpos][f.step] = bfee;
          }
        }

        // Go forward
        int fpos = f.pos + f.step + 1;
        if (fpos <= n) {
          int ffee = f.sum + fee[fpos];
          if (ffee < best[fpos][f.step + 1]) {
            q.push({fpos, f.step + 1, ffee});
            best[fpos][f.step + 1] = ffee;
          }
        }
      }
    }
    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}