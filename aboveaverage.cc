#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<int> scores;
    double sum = 0;
    for (int j = 0; j < n; ++j) {
      int sj;
      cin >> sj;
      scores.emplace_back(sj);
      sum += sj;
    }
    double avg = sum / n;
    int cnt = 0;
    for (int j = 0; j < n; ++j)
      cnt += (scores[j] > avg);
    printf("%.3f", (double)cnt / n * 100);
    cout << "%" << endl;
  }
}