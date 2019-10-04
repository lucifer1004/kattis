#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double eps = 1e-12;

bool equal(double a, double b) { return fabs(a - b) < eps; }

struct Segment {
  double x1, y1, x2, y2;
};

bool cross(Segment &a, Segment &b) {
  double mat[2][3];
  vector<Segment> seg{a, b};
  for (int i = 0; i < 2; ++i) {
    mat[i][0] = seg[i].y2 - seg[i].y1;
    mat[i][1] = seg[i].x1 - seg[i].x2;
    mat[i][2] = seg[i].x1 * seg[i].y2 - seg[i].x2 * seg[i].y1;
  }

  if (equal(mat[0][0], 0))
    swap(mat[0], mat[1]);

  if ((equal(mat[0][0], 0) && equal(mat[1][0], 0)) ||
      (equal(mat[0][1], 0) && equal(mat[1][1], 0)) ||
      (equal(mat[0][1] * mat[1][0], mat[0][0] * mat[1][1])))
    return false;

  double y = (mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]) /
             (mat[0][1] * mat[1][0] - mat[0][0] * mat[1][1]);

  double x = (mat[0][2] - mat[0][1] * y) / mat[0][0];

  double l = max(min(a.x1, a.x2), min(b.x1, b.x2));
  double r = min(max(a.x1, a.x2), max(b.x1, b.x2));
  if (equal(l, r)) {
    if (!equal(l, x))
      return false;
  } else {
    if (l - x > eps || x - r > eps)
      return false;
  }

  double u = min(max(a.y1, a.y2), max(b.y1, b.y2));
  double d = max(min(a.y1, a.y2), min(b.y1, b.y2));
  if (equal(u, d)) {
    if (!equal(u, y))
      return false;
  } else {
    if (d - y > eps || y - u > eps)
      return false;
  }

  return true;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n)
      break;
    vector<Segment> seg(n);
    vector<vector<bool>> check(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &seg[i].x1, &seg[i].y1, &seg[i].x2, &seg[i].y2);
      for (int j = 0; j < i; ++j)
        if (cross(seg[j], seg[i]))
          check[j][i] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n - 2; ++i)
      for (int j = i + 1; j < n - 1; ++j)
        for (int k = j + 1; k < n; ++k)
          if (check[i][j] && check[i][k] && check[j][k])
            cnt++;
    cout << cnt << endl;
  }
}