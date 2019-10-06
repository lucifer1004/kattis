#include <iostream>

using namespace std;

int main() {
  int i = 0, maxp = 0, maxi = 0;
  int a;
  while (cin >> a) {
    i++;
    int sum = a;
    for (int j = 0; j < 3; ++j) {
      cin >> a;
      sum += a;
    }
    if (sum > maxp) {
      maxp = sum;
      maxi = i;
    }
  }
  cout << maxi << " " << maxp;
  return 0;
}