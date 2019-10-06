#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n;

struct Student {
  string name, surname;
};

int main() {
  cin >> n;
  vector<Student> students;
  vector<vector<string>> f(n);
  for (int i = 0; i < n; ++i) {
    string name, surname;
    cin >> name >> surname;
    for (char &c : name)
      c = tolower(c);
    for (char &c : surname)
      c = tolower(c);
    students.emplace_back(Student{name, surname});
  }
  stable_sort(students.begin(), students.end(), [](Student a, Student b) {
    return a.surname + a.name < b.surname + b.name;
  });
  for (int i = 0; i < n; ++i) {
    string name = students[i].name;
    string surname = students[i].surname;
    int j = -1;
    while (++j < surname.size()) {
      string s = surname.substr(0, j + 1) + name[0];
      f[i].emplace_back(s);
    }
    j = 0;
    while (++j < name.size()) {
      string s = f[i][f[i].size() - 1] + name[j];
      f[i].emplace_back(s);
    }
  }

  vector<vector<int>> memo(n);
  for (int i = 0; i < n; ++i)
    memo[i] = vector<int>(f[i].size(), INT_MAX);

  for (int i = 0; i < f[n - 1].size(); ++i)
    memo[n - 1][i] = i;

  for (int i = n - 2; i >= 0; --i) {
    int m = f[i].size();
    int p = f[i + 1].size();
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < p; ++k) {
        if (f[i][j] >= f[i + 1][k] || memo[i + 1][k] == INT_MAX)
          continue;
        memo[i][j] = min(memo[i][j], memo[i + 1][k] + j);
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < f[0].size(); ++i)
    ans = min(ans, memo[0][i]);

  cout << (ans == INT_MAX ? -1 : ans);
}