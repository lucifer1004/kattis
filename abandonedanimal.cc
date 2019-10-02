#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n, k, m;
  unordered_map<string, set<int>> items;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int idx;
    string s;
    cin >> idx >> s;
    items[s].insert(idx);
  }
  cin >> m;
  vector<int> ways(n);
  string last_s;
  int l = -1;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    int nl = *(items[s].begin());
    int nr = *(prev(items[s].end()));
    if (nr < l) {
      cout << "impossible";
      return 0;
    }
    if (last_s.empty()) {
      for (int j : items[s])
        ways[j] = 1;
    } else {
      set<int> &last = items[last_s];
      vector<int> acc{0};
      for (int j : last) {
        acc.emplace_back(acc[acc.size() - 1] + ways[j]);
        ways[j] = 0;
      }
      int delta = 0;
      auto it = last.begin();
      for (int j : items[s]) {
        while (it != last.end() && *it <= j) {
          it++;
          delta++;
        }
        ways[j] = min(acc[delta], 2);
      }
    }
    last_s = s;
    l = max(l, nl);
  }
  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += ways[i];
  if (sum == 0)
    cout << "impossible";
  else
    cout << (sum > 1 ? "ambiguous" : "unique");
  return 0;
}