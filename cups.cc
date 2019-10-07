#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Cup {
  int diameter;
  string color;
};

int main() {
  int n;
  cin >> n;
  vector<Cup> cups;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s[0] - '0' <= 9) {
      int diameter = stoi(s);
      cin >> s;
      cups.emplace_back(Cup{diameter, s});
    } else {
      int radius;
      cin >> radius;
      cups.emplace_back(Cup{radius * 2, s});
    }
  }
  sort(cups.begin(), cups.end(), [](Cup &a, Cup &b) {
    return a.diameter < b.diameter ||
           (a.diameter == b.diameter && a.color < b.color);
  });
  for (const Cup &cup : cups)
    cout << cup.color << endl;
  return 0;
}