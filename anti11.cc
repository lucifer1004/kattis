#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll modulo = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
}

int main() {
  vector<ll> f0{1}, f1{1};
  for (int i = 1; i <= 10000; ++i) {
    f0[i] = (f0[i - 1] + f1[i - 1]) % modulo;
    f1[i] = f0[i - 1];
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    cout << (f0[n] + f1[n]) % modulo << endl;
  }
  return 0;
}