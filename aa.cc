#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string last;
  for (int i = 0; i < n; i++) {
    string s, t;
    cin >> s;
    int ptr = 0;
    bool done = false;
    for (int j = 0; j < s.size(); j++) {
      if (ptr >= last.size() || s[j] > last[ptr]) {
        t += s.substr(j, s.size() - j);
        break;
      }

      if (s[j] == last[ptr]) {
        t.push_back(s[j]), ptr++;
      } else {
        if (s[j] == 'a' && j + 1 < s.size() && s[j + 1] == 'a') {
          t.push_back('z' + 1);
          if (last[ptr] < 'z' + 1) {
            t += s.substr(j + 2, s.size() - j - 2);
            break;
          } else {
            ptr++;
            j++;
          }
        } else {
          t.push_back(s[j]);
          break;
        }
      }
    }

    if (t <= last) {
      int k = (int)t.size() - 1;
      while (k >= 1 && (t[k - 1] != 'a' || (t[k] != 'a' && t[k] != 'z' + 1)))
        k--;

      if (k >= 1) {
        bool flag = t[k] == 'a';
        t = t.substr(0, k - 1);
        t.push_back('z' + 1);
        if (!flag)
          t.push_back('a');
        int m = 0;
        for (char ch : t)
          m += 1 + (ch == 'z' + 1);
        t += s.substr(m, s.size() - m);
      }

      if (t <= last) {
        cout << "no" << endl;
        return 0;
      }
    }

    last = t;
  }

  cout << "yes" << endl;
}