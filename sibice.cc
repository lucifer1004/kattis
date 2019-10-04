#include <iostream>

using namespace std;

int main() {
  int n, w, h;
  cin >> n >> w >> h;
  int limit = w * w + h * h;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    cout << (d * d <= limit ? "DA" : "NE") << endl;
  }
  return 0;
}