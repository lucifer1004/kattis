#include <iostream>

using namespace std;

const string upper = "PER", lower = "per";

int main() {
  string s;
  cin >> s;
  int curr = 0;
  int cnt = 0;
  for (const char &c : s) {
    cnt += (c != upper[curr] && c != lower[curr]);
    curr = (curr + 1) % 3;
  }
  cout << cnt;
  return 0;
}