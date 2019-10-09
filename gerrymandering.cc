#include <iostream>
#include <vector>

using namespace std;

int main() {
  int p, d;
  cin >> p >> d;
  vector<int> a(d + 1), b(d + 1);
  for (int i = 0; i < p; ++i) {
    int di, ai, bi;
    cin >> di >> ai >> bi;
    a[di] += ai;
    b[di] += bi;
  }
  int sum = 0, wa = 0, wb = 0;
  for (int i = 1; i <= d; ++i) {
    int votes = a[i] + b[i];
    int sa, sb;
    sum += votes;
    if (a[i] > b[i]) {
      sa = a[i] - (votes / 2 + 1);
      sb = b[i];
      cout << "A ";
    } else {
      sa = a[i];
      sb = b[i] - (votes / 2 + 1);
      cout << "B ";
    }
    cout << sa << " " << sb << endl;
    wa += sa;
    wb += sb;
  }
  cout << (double)abs(wa - wb) / sum;
  return 0;
}