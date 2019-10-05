#include <iostream>

using namespace std;

int main() {
  int n;
  for (int i = 0; i < n; ++i) {
    string s, t;
    cin >> s >> t;
    cout << s << endl;
    cout << t << endl;
    for (int i = 0; i < s.size(); ++i)
      cout << (s[i] == t[i] ? '.' : '*');
    cout << endl << endl;
  }
  return 0;
}