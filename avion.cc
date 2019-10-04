#include <iostream>
#include <string>

using namespace std;

int main() {
  bool found = false;
  for (int i = 1; i <= 5; ++i) {
    string s;
    cin >> s;
    if (s.find("FBI") != string::npos) {
      cout << i << " ";
      found = true;
    }
  }
  if (!found)
    cout << "HE GOT AWAY!";
  return 0;
}