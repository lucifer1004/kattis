#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
  int x, y, d;
};

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, -1, 0, 1};

int main() {
  int r, c, n;
  cin >> r >> c >> n;
  vector<vector<bool>> used(c, vector<bool>(r));
  queue<Point> bfs;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> y >> x;
    if (!used[--x][--y]) {
      bfs.push(Point{x, y, 1});
      used[x][y] = true;
    }
  }
  int ans = 1;
  while (!bfs.empty()) {
    Point front = bfs.front();
    bfs.pop();
    ans = max(ans, front.d);
    for (int i = 0; i < 4; ++i) {
      int nx = front.x + dx[i];
      int ny = front.y + dy[i];
      if (nx < 0 || nx >= c || ny < 0 || ny >= r || used[nx][ny])
        continue;
      bfs.push(Point{nx, ny, front.d + 1});
      used[nx][ny] = true;
    }
  }
  cout << ans;
  return 0;
}