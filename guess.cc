#include <iostream>

using namespace std;

int main() {
  int l = 1;
  int r = 1000;
  while (l <= r) {
    int mid = (l + r) / 2;
    cout << mid << endl;
    string ans;
    cin >> ans;
    if (ans == "correct")
      break;
    if (ans == "lower")
      r = mid - 1;
    if (ans == "higher")
      l = mid + 1;
  }
  return 0;
}