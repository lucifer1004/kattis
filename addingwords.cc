#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  unordered_map<string, int> dict;
  unordered_map<int, string> lookup;
  string command;
  string str;
  while (getline(cin, str)) {
    if (str.empty())
      break;
    stringstream sin(str);
    sin >> command;
    if (command == "def") {
      string var;
      sin >> var;
      int val;
      sin >> val;
      if (dict.find(var) != dict.end())
        lookup.erase(dict[var]);
      dict[var] = val;
      lookup[val] = var;
    } else if (command == "calc") {
      string res, s;
      vector<string> parts;
      do {
        sin >> s;
        parts.push_back(s);
        res += s + " ";
      } while (s != "=");
      bool unknown = false;
      bool plus = true;
      int ans = 0;
      for (int i = 0; i < parts.size() - 1; ++i) {
        if (parts[i] == "+")
          plus = true;
        else if (parts[i] == "-")
          plus = false;
        else {
          if (dict.find(parts[i]) == dict.end()) {
            unknown = true;
            break;
          } else
            ans += dict[parts[i]] * (plus ? 1 : -1);
        }
      }
      if (lookup.find(ans) == lookup.end())
        unknown = true;
      if (unknown)
        res += "unknown";
      else
        res += lookup[ans];
      cout << res << endl;
    } else {
      dict.clear();
      lookup.clear();
    }
  }
}