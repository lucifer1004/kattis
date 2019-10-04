#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    bitset<32> known, ans;
    for (int i = 0; i < n; ++i) {
      string cmd;
      cin >> cmd;
      if (cmd == "SET") {
        int val;
        cin >> val;
        known.set(val);
        ans.set(val);
      }
      if (cmd == "CLEAR") {
        int val;
        cin >> val;
        known.set(val);
        ans.reset(val);
      }
      if (cmd == "OR") {
        int a, b;
        cin >> a >> b;
        if ((known[a] && ans[a]) || (known[b] && ans[b])) {
          known.set(a);
          ans.set(a);
          continue;
        }
        if ((known[a] && !ans[a] && !known[b])) {
          known.reset(a);
          continue;
        }
        if (known[a] && known[b])
          ans[a] = ans[a] || ans[b];
      }
      if (cmd == "AND") {
        int a, b;
        cin >> a >> b;
        if ((known[a] && !ans[a]) || (known[b] && !ans[b])) {
          known.set(a);
          ans.reset(a);
          continue;
        }
        if ((known[a] && ans[a] && !known[b])) {
          known.reset(a);
          continue;
        }
        if (known[a] && known[b])
          ans[a] = ans[a] && ans[b];
      }
      for (int i = 31; i >= 0; --i)
        if (!known[i])
          cout << "?";
        else
          cout << ans[i];
      cout << endl;
    }
  }
  return 0;
}