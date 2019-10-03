#include <iostream>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  cout << (s.size() >= t.size() ? "go" : "no");
  return 0;
}