#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    cnt += (t < 0);
  }
  cout << cnt;
  return 0;
}