#include <iostream>
#include <unordered_set>

using namespace std;

void solve() {
  int n;
  cin >> n;
  unordered_set<string> cities;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cities.insert(s);
  }
  cout << cities.size() << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}