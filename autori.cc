#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  s = "-" + s;
  string ans;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '-')
      ans += s[i + 1];
  cout << ans;
  return 0;
}