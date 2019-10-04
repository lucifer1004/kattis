#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    if (d != -1) {
      cnt++;
      sum += d;
    }
  }
  cout << (double)sum / cnt;
  return 0;
}