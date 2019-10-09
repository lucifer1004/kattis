#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<string, string>> teams;
  unordered_set<string> universities;
  for (int i = 0; i < n; ++i) {
    string university, team;
    cin >> university >> team;
    if (universities.find(university) == universities.end()) {
      universities.insert(university);
      teams.emplace_back(make_pair(university, team));
      if (teams.size() == 12) {
        for (const auto &p : teams)
          cout << p.first << " " << p.second << endl;
        return 0;
      }
    }
  }
  return 0;
}