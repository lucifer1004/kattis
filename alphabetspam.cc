#include <iostream>

using namespace std;

bool is_lower(char c) {
  int delta = c - 'a';
  return delta >= 0 && delta <= 25;
}

bool is_upper(char c) {
  int delta = c - 'A';
  return delta >= 0 && delta <= 25;
}

int main() {
  string s;
  cin >> s;
  double space = 0, lower = 0, upper = 0, symbol = 0;
  double n = s.size();
  for (const char &c : s) {
    if (c == '_')
      space++;
    else if (is_lower(c))
      lower++;
    else if (is_upper(c))
      upper++;
    else
      symbol++;
  }
  printf("%.8f\n%.8f\n%.8f\n%.8f", space / n, lower / n, upper / n, symbol / n);
  return 0;
}