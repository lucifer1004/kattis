#include <iostream>
#include <vector>

using namespace std;

int main() {
  int rank = 25;
  int streak = 0;
  int star = 0;
  vector<int> stars(26);
  for (int i = 1; i <= 5; ++i) {
    stars[i] = 5;
    stars[i + 5] = 5;
    stars[i + 10] = 4;
    stars[i + 15] = 3;
    stars[i + 20] = 2;
  }
  string record;
  cin >> record;
  for (const char &c : record) {
    if (c == 'W') {
      streak++;
      star++;
      if (streak >= 3 && rank > 5)
        star++;
      if (star > stars[rank])
        star -= stars[rank--];
    } else {
      streak = 0;
      if (rank <= 20)
        star--;
      if (star < 0 && rank > 0) {
        if (rank == 20)
          star = 0;
        else
          star = stars[++rank] - 1;
      }
    }
  }
  if (rank > 0)
    cout << rank;
  else
    cout << "Legend";
  return 0;
}