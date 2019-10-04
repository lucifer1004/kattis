#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int l = 0;
  char curr = s[0];
  for (int i = 1; i < s.size(); ++i)
    if (s[i] != curr) {
      s[++l] = s[i];
      curr = s[i];
    }

  cout << s.substr(0, l + 1);
  return 0;
}