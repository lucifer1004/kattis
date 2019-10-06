#include <iostream>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int n = stoi(s.substr(2, s.size() - 2));
    int ans = 0;
    for (int i = n + 1; i <= 2 * n; ++i)
      if (n * i % (i - n) == 0)
        ans++;
    cout << ans << endl;
  }
  return 0;
}