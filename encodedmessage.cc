#include <cmath>
#include <iostream>

using namespace std;

void solve() {
  string encoded;
  cin >> encoded;
  int square = encoded.size();
  int n = sqrt(square);
  string decoded(encoded);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      decoded[n * (n - j - 1) + i] = encoded[n * i + j];
  cout << decoded << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    solve();
}