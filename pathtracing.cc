#include <iostream>
#include <vector>

using namespace std;

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, -1, 0, 1};

int direction(string cmd) {
  if (cmd == "left")
    return 0;
  if (cmd == "up")
    return 1;
  if (cmd == "right")
    return 2;
  return 3;
}

int main() {
  string cmd;
  vector<pair<int, int>> path;
  int x = 0, y = 0;
  int minx = 0, miny = 0, maxx = 0, maxy = 0;
  while (getline(cin, cmd)) {
    if (cmd.empty())
      break;
    int i = direction(cmd);
    x += dx[i];
    y += dy[i];
    path.push_back({x, y});
    minx = min(minx, x);
    miny = min(miny, y);
    maxx = max(maxx, x);
    maxy = max(maxy, y);
  }
  int r = maxy - miny + 3;
  int c = maxx - minx + 3;
  vector<vector<char>> mat(r, vector<char>(c, ' '));
  for (int i = 0; i < r; ++i) {
    mat[i][0] = '#';
    mat[i][c - 1] = '#';
  }
  for (int i = 0; i < c; ++i) {
    mat[0][i] = '#';
    mat[r - 1][i] = '#';
  }
  int n = path.size();
  for (int i = 0; i < n - 1; ++i) {
    int x = path[i].first;
    int y = path[i].second;
    mat[1 + y - miny][1 + x - minx] = '*';
  }
  mat[1 - miny][1 - minx] = 'S';
  mat[1 + y - miny][1 + x - minx] = 'E';
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j)
      cout << mat[i][j];
    cout << endl;
  }
  return 0;
}