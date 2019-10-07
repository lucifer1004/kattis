#include <iostream>

using namespace std;

void solve() {
  string question;
  cin >> question;
  if (question == "P=NP")
    cout << "skipped" << endl;
  else {
    int i = 0;
    while (question[i] != '+')
      i++;
    int a = stod(question.substr(0, i));
    int b = stod(question.substr(i + 1, question.size() - i - 1));
    cout << a + b << endl;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    solve();
  return 0;
}