#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  unordered_map<string, unordered_map<string, bool>> lookup;
  unordered_map<string, int> cnt;
  for (int i = 0; i < n; ++i) {
    string pizza;
    cin >> pizza;
    int s, t;

    cin >> s;
    unordered_set<string> f;
    for (int j = 0; j < s; ++j) {
      string foreign;
      cin >> foreign;
      f.insert(foreign);
    }

    cin >> t;
    unordered_set<string> l;
    for (int j = 0; j < t; ++j) {
      string local;
      cin >> local;
      l.insert(local);
      cnt[local]++;
    }

    for (const string &j : f) {
      if (lookup.find(j) == lookup.end()) {
        for (const string &k : l)
          if (cnt[k] == 1)
            lookup[j][k] = true;
      } else
        for (auto &it : lookup[j])
          if (it.second && l.find(it.first) == l.end())
            it.second = false;
    }

    for (auto &p : lookup)
      if (f.find(p.first) == f.end())
        for (const string &k : l)
          p.second.erase(k);
  }

  vector<string> ans;

  for (const auto &p : lookup)
    for (const auto &l : p.second)
      if (l.second)
        ans.emplace_back("(" + p.first + ", " + l.first + ")\n");

  sort(ans.begin(), ans.end());
  for (const string &item : ans)
    cout << item;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}