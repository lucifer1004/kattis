#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  cout << (s.find("ss") == string::npos ? "no hiss" : "hiss");
  return 0;
}