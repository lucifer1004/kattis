#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

bool parallel(Point &a, Point &b, Point &c) {
  return (b.y - a.y) * (c.x - a.x) == (b.x - a.x) * (c.y - a.y);
}

int main() {
  int n;
  cin >> n;
  vector<Point> points{};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      if (c != '.')
        points.emplace_back(Point{i, j});
    }
  }
  int p = points.size();

  // Since no letter will occur more than once,
  // brute-force is enough for this problem.
  int ans = 0;
  for (int i = 0; i < p - 2; ++i)
    for (int j = i + 1; j < p - 1; ++j)
      for (int k = j + 1; k < p; ++k)
        ans += parallel(points[i], points[j], points[k]);

  cout << ans;
  return 0;
}