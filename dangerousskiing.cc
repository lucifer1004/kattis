#include <iostream>
#include <vector>

using namespace std;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

int main() {
  int n, m;
  cin >> n >> m;
  vvvd mat(n, vvd(n, vd(n, -1)));
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < n; ++k)
      mat[i][i][k] = 1;

  for (int i = 0; i < m; ++i) {
    int u, v;
    double p;
    cin >> u >> v >> p;
    if (u > v)
      swap(u, v);
    mat[u][v][0] = 1.0 - p;
    for (int k = 1; k < n; ++k) {
      mat[u][v][k] = 1;
      mat[v][u][k] = 1;
    }
  }

  for (int k = 0; k < n; ++k) {
    vector<bool> expanded(n);
    for (int i = 0; i < n - 2; ++i) {
      double max_p = -1;
      int max_j = -1;
      for (int j = 1; j < n; ++j)
        if (!expanded[j] && mat[0][j][k] > max_p) {
          max_p = mat[0][j][k];
          max_j = j;
        }
      if (max_p < -0.5)
        break;
      expanded[max_j] = true;
      for (int t = 1; t < n; ++t) {
        if (max_j == t)
          continue;
        for (int j = 0; j <= min(n - k, 1); ++j) {
          if (mat[max_j][t][j] < -0.5)
            continue;
          double new_p = max_p * mat[max_j][t][j];
          mat[0][t][k + j] = max(mat[0][t][k + j], new_p);
        }
      }
    }
  }

  double best = -1;
  for (int i = 0; i < n; ++i) {
    best = max(best, mat[0][n - 1][i]);
    printf("%.12f ", best);
  }
  return 0;
}