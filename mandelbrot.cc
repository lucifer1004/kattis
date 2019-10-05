#include <cmath>
#include <iostream>

using namespace std;

struct Comp {
  double real, imag;
  Comp operator*(Comp a) {
    return Comp{real * a.real - imag * a.imag, real * a.imag + imag * a.real};
  }

  Comp operator+(Comp a) { return Comp{real + a.real, imag + a.imag}; }

  double radius() { return sqrt(real * real + imag * imag); }
};

int main() {
  double x, y, r;
  int case_num = 0;
  while (cin >> x >> y >> r) {
    case_num++;
    Comp c{x, y}, z{x, y};
    bool diverge = false;
    for (int i = 0; i < r; ++i) {
      if (z.radius() > 2) {
        diverge = true;
        break;
      }
      z = z * z + c;
    }
    cout << "Case " << case_num << ": " << (diverge ? "OUT" : "IN") << endl;
  }
  return 0;
}