#include <cstdio>
#include <unordered_map>

using namespace std;
template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

int H[10000005];
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i)
    read(H[i]);
  unordered_map<int, int> cnt;
  for (int i = n; i >= 1; --i) {
    if (cnt[H[i] - 1] > 0)
      cnt[H[i] - 1]--;
    cnt[H[i]]++;
  }
  int ans = 0;
  for (auto p : cnt)
    ans += p.second;
  printf("%d", ans);
}