#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> cnt;
  for (const char &c : s)
    cnt[c]++;
  int odd = 0;
  for (const auto &p : cnt)
    odd += p.second % 2;
  cout << max(0, odd - 1);
  return 0;
}