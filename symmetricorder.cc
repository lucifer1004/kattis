#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int cnt = 0;
  while (cin >> n) {
    if (!n)
      break;
    cnt++;
    vector<string> ans(n);
    string str;
    for (int i = 0; i < n / 2; ++i) {
      cin >> str;
      ans[i] = str;
      cin >> str;
      ans[n - i - 1] = str;
    }
    if (n % 2) {
      cin >> str;
      ans[n / 2] = str;
    }
    cout << "SET " << cnt << endl;
    for (const string &s : ans)
      cout << s << endl;
  }
  return 0;
}