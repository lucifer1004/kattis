#include <iostream>

using namespace std;

const int chess[6]{1, 1, 2, 2, 2, 8};

int main() {
  for (int i = 0; i < 6; ++i) {
    int d;
    cin >> d;
    cout << chess[i] - d << " ";
  }
  return 0;
}