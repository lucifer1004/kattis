#include <iostream>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char csx, ctx;
    int sy, ty;
    cin >> csx >> sy >> ctx >> ty;
    int sx = csx - 'A' + 1, tx = ctx - 'A' + 1;
    if ((sx - tx + sy - ty) % 2 != 0)
      cout << "Impossible" << endl;
    else {
      if (sx == tx && sy == ty)
        cout << "0 " << csx << " " << sy << endl;
      else if (sx - sy == tx - ty || sx + sy == tx + ty)
        cout << "1 " << csx << " " << sy << " " << ctx << " " << ty << endl;
      else {
        bool found = false;
        for (int mx = 1; mx <= 8; ++mx) {
          for (int my = 1; my <= 8; ++my) {
            if ((sx - sy == mx - my && tx + ty == mx + my) ||
                (sx + sy == mx + my && tx - ty == mx - my)) {
              cout << "2 " << csx << " " << sy << " " << (char)(mx + 'A' - 1)
                   << " " << my << " " << ctx << " " << ty << endl;
              found = true;
              break;
            }
          }
          if (found)
            break;
        }
      }
    }
  }
}