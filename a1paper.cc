#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; ++i)
    scanf("%d", &a[i]);
  double ans = 0;
  int req = 2;
  double exp = -0.75;
  for (int i = 0; i < n - 1; ++i) {
    ans += (req / 2) * pow(2, exp);
    exp -= 0.5;
    if (a[i] < req)
      req = (req - a[i]) * 2;
    else {
      printf("%.10f", ans);
      return 0;
    }
  }
  cout << "impossible";
  return 0;
}