#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n)
      break;
    vector<pair<int, int>> a;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      int ai;
      cin >> ai;
      a.emplace_back(make_pair(ai, i));
    }
    sort(a.begin(), a.end(), [](pair<int, int> &p, pair<int, int> &q) {
      return p.first < q.first;
    });

    for (int i = 0; i < n; ++i) {
      int bi;
      cin >> bi;
      b.emplace_back(bi);
    }
    vector<int> c(n);
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i)
      c[a[i].second] = b[i];

    for (int i = 0; i < n; ++i)
      cout << c[i] << endl;
    cout << endl;
  }
  return 0;
}