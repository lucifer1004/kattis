#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  if (n == 1) {
    cout << 1;
    return 0;
  }

  vector<int> prices(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &prices[i]);
  sort(prices.begin(), prices.end());
  for (int i = 0; i < n - 1; ++i)
    if (prices[i] + prices[i + 1] > x) {
      cout << i + 1;
      return 0;
    }
  cout << n;
  return 0;
}