#include <iostream>

using namespace std;

const string days[7]{"Monday", "Tuesday",  "Wednesday", "Thursday",
                     "Friday", "Saturday", "Sunday"};

const int months[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int d, m;
  cin >> d >> m;

  int doy = 0;
  for (int i = 1; i < m; ++i)
    doy += months[i - 1];
  doy += d;

  cout << days[(doy - 4) % 7];
  return 0;
}