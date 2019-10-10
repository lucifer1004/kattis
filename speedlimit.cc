#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == -1)
      break;
    int time = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      int s, t;
      cin >> s >> t;
      cnt += s * (t - time);
      time = t;
    }
    cout << cnt << " miles" << endl;
  }
  return 0;
}