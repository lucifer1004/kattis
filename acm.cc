#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int t;
  cin >> t;
  unordered_map<string, int> cnt;
  int ans = 0, num = 0;
  while (t != -1) {
    string title, res;
    cin >> title >> res;
    if (res == "right") {
      num++;
      ans += t + cnt[title] * 20;
    } else
      cnt[title]++;
    cin >> t;
  }
  cout << num << " " << ans;
}