#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int T = 0, C = 0, G = 0;
  for (const char &c : s) {
    C += c == 'C';
    T += c == 'T';
    G += c == 'G';
  }
  int ans = T * T + C * C + G * G + min(T, min(C, G)) * 7;
  cout << ans;
  return 0;
}