#include <iostream>

using namespace std;

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  for (int i = 1; i <= n; ++i) {
    bool dx = i % x;
    bool dy = i % y;
    if (!dx && !dy)
      cout << "FizzBuzz";
    else if (!dx)
      cout << "Fizz";
    else if (!dy)
      cout << "Buzz";
    else
      cout << i;
    cout << endl;
  }
  return 0;
}