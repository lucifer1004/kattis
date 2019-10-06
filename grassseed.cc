#include <iostream>

using namespace std;

int main() {
  double c;
  int l;
  cin >> c >> l;
  double area = 0;
  for (int i = 0; i < l; ++i) {
    double x, y;
    cin >> x >> y;
    area += x * y;
  }
  printf("%.10f", c * area);
  return 0;
}