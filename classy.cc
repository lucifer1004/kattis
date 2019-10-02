#include <iostream>
#include <vector>

using namespace std;

struct Person {
  string name, klass;
};

string simplify(string klass) {
  klass += '-';
  vector<string> rank;
  int last = 0;
  for (int i = 0; i < klass.size(); ++i)
    if (klass[i] == '-') {
      rank.emplace_back(klass.substr(last, i - last));
      last = i + 1;
    }
  string ans;
  for (int i = rank.size() - 1; i >= 0; --i) {
    int r;
    if (rank[i] == "upper")
      r = 0;
    else if (rank[i] == "middle")
      r = 1;
    else
      r = 2;
    ans += to_string(r);
  }
  return ans;
}

int compare_klass(string a, string b) {
  int la = a.size();
  int lb = b.size();
  if (la > lb)
    return -compare_klass(b, a);
  while (la++ < lb)
    a += "1";
  if (a == b)
    return 0;
  if (a < b)
    return 1;
  return -1;
}

bool compare(Person &a, Person &b) {
  int res = compare_klass(a.klass, b.klass);
  return (res == 1 || (res == 0 && a.name < b.name));
}

void solve() {
  int n;
  cin >> n;
  vector<Person> people;
  for (int i = 0; i < n; ++i) {
    string name, klass, _;
    cin >> name >> klass >> _;
    name = name.substr(0, name.size() - 1);
    klass = simplify(klass);
    people.emplace_back(Person{name, klass});
  }
  sort(people.begin(), people.end(), compare);
  for (const Person &person : people)
    cout << person.name << endl;
  cout << "==============================" << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}