#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  ll a, b;
  while (cin >> a >> b)
    cout << abs(a - b) << endl;
  return 0;
}