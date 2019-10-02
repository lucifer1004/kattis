#include <iostream>
#include <vector>

using namespace std;

struct Node {
  double val, pos, newpos, enter;
  double p[5];
};

const int di[4]{-1, -1, 1, 1};
const int dj[4]{-1, 0, 0, 1};
const int id[4]{0, 1, 2, 3};

int main() {
  int n;
  cin >> n;
  vector<vector<Node>> nodes(n + 1, vector<Node>(n + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      scanf("%lf", &nodes[i][j].val);

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      scanf("%lf%lf%lf%lf%lf", &nodes[i][j].p[0], &nodes[i][j].p[1],
            &nodes[i][j].p[2], &nodes[i][j].p[3], &nodes[i][j].p[4]);

  nodes[1][1].pos = 1;

  for (int t = 1; t <= 1000000 / n; ++t) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= i; ++j) {
        // Adding the short-circuit condition reduces
        // running time from 1.97s to 0.04s.
        if (nodes[i][j].pos < 1e-30)
          continue;
        nodes[i][j].enter += nodes[i][j].pos * nodes[i][j].p[4];
        for (int k = 0; k < 4; ++k) {
          int pi = i + di[k];
          int pj = j + dj[k];
          if (pi <= 0 || pi > n || pj <= 0 || pj > pi)
            continue;
          nodes[pi][pj].newpos += nodes[i][j].pos * nodes[i][j].p[id[k]];
        }
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= i; ++j) {
        nodes[i][j].pos = nodes[i][j].newpos;
        nodes[i][j].newpos = 0;
      }
  }

  double ans = 0;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      ans += nodes[i][j].enter * nodes[i][j].val;

  printf("%.12f", ans);
  return 0;
}