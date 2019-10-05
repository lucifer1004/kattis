#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, int> cnt;
  int best = 0;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      best = max(best, ++cnt[i + j]);

  for (const auto &p : cnt)
    if (p.second == best)
      cout << p.first << endl;

  return 0;
}