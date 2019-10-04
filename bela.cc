#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<char, int> dom{{'A', 11}, {'K', 4},  {'Q', 3}, {'J', 20},
                               {'T', 10}, {'9', 14}, {'8', 0}, {'7', 0}};
  unordered_map<char, int> nondom{{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 2},
                                  {'T', 10}, {'9', 0}, {'8', 0}, {'7', 0}};

  int n;
  char trump;
  cin >> n >> trump;
  int cnt = 0;
  for (int i = 0; i < 4 * n; ++i) {
    char card, color;
    cin >> card >> color;
    if (color == trump)
      cnt += dom[card];
    else
      cnt += nondom[card];
  }
  cout << cnt;
  return 0;
}