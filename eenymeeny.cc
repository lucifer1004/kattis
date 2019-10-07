#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
  string str;
  getline(cin, str);
  int p = 1;
  for (const char &c : str)
    p += c == ' ';

  int n;
  cin >> n;

  list<string> names;
  for (int i = 0; i < n; ++i) {
    string name;
    cin >> name;
    names.emplace_back(name);
  }

  vector<string> odd, even;
  for (int i = 1; i <= n; ++i) {
    int step = (p - 1) % (n - i + 1);
    auto it = names.begin();
    for (int j = 0; j < i; ++j)
      it++;
    if (i % 2)
      odd.emplace_back(*it);
    else
      even.emplace_back(*it);
    names.erase(it);
  }

  cout << odd.size() << endl;
  for (const string &s : odd)
    cout << s << endl;
  cout << even.size() << endl;
  for (const string &s : even)
    cout << s << endl;

  return 0;
}