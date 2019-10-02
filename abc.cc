#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> d(3);
  for (int i = 0; i < 3; ++i)
    scanf("%d", &d[i]);
  sort(d.begin(), d.end());
  string s;
  cin >> s;
  for (int i = 0; i < 3; ++i)
    cout << d[s[i] - 'A'] << " ";
  return 0;
}