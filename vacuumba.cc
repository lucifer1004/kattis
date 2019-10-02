#include <cmath>
#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  double x = 0, y = 0, ang = 0;
  for (int i = 0; i < n; ++i) {
    double rotation, dist;
    cin >> rotation >> dist;
    ang -= rotation;
    double dx = dist * sin(ang / 180 * M_PI);
    double dy = dist * cos(ang / 180 * M_PI);
    x += dx;
    y += dy;
  }
  printf("%.6f %.6f\n", x, y);
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
  return 0;
}