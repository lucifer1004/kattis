#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double eps = 1e-4;

double f(vector<double> &poly, double x) {
  double ans = 0;
  double d = 1;
  for (const double &i : poly) {
    ans += d * i;
    d *= x;
  }
  return ans;
}

int main() {
  string str;
  int case_num = 0;
  int n;
  while (cin >> n) {
    case_num++;
    vector<double> coeff;
    for (int i = 0; i <= n; ++i) {
      double d;
      cin >> d;
      coeff.emplace_back(d);
    }

    vector<double> square(2 * n + 1);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        square[i + j] += coeff[i] * coeff[j];

    coeff = vector<double>(2 * n + 2);
    for (int i = 1; i <= 2 * n + 1; ++i)
      coeff[i] = square[i - 1] / i * M_PI;

    double lo, hi, inc;
    cin >> lo >> hi >> inc;

    double flo = f(coeff, lo);
    double fhi = f(coeff, hi);
    double vol = fhi - flo;
    printf("Case %d: %.2f\n", case_num, vol);
    if (vol < inc)
      cout << "insufficient volume" << endl;
    else {
      double target = flo;
      for (int j = 0; j < 8; ++j) {
        target += inc;
        if (target > fhi)
          break;
        double l = lo;
        double r = hi;
        while (l < r) {
          double mid = (l + r) / 2;
          double fmid = f(coeff, mid);
          if (fabs(fmid - target) < eps) {
            printf("%.2f ", mid - lo);
            break;
          }
          if (fmid < target)
            l = mid;
          else
            r = mid;
        }
      }
      cout << endl;
    }
  }

  return 0;
}