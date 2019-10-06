#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class Heap {
  vector<T> a;

  int parent(int i) { return (i - 1) / 2; }
  int lchild(int i) { return i * 2 + 1; }
  int rchild(int i) { return i * 2 + 2; }

  void pop_up(int i) {
    int p = parent(i);
    if (a[i] < a[p]) {
      swap(a[i], a[p]);
      if (p > 0)
        pop_up(p);
    }
  }

  void push_down(int i) {
    int l = lchild(i);
    int r = rchild(i);
    if (l >= a.size())
      return;
    if (r < a.size() && a[r] < a[l]) {
      if (a[r] < a[i]) {
        swap(a[r], a[i]);
        push_down(r);
      }
    } else if (a[l] < a[i]) {
      swap(a[l], a[i]);
      push_down(l);
    }
  }

public:
  explicit Heap(vector<T> &v) {
    a = v;
    sort(a.begin(), a.end());
  }

  void decrease_key(int i, T t) {
    if (t < a[i])
      a[i] = t;
    pop_up(i);
  }

  T extract_min() {
    T res = a[0];
    a[0] = a[a.size() - 1];
    a.pop_back();
    push_down(0);
    return res;
  }

  bool empty() { return a.empty(); }

  vector<T> container() { return a; }
};

struct Edge {
  int to, dist, val;
  bool operator<(const Edge &e) const {
    return dist < e.dist || (dist == e.dist && val > e.val);
  }
};

class Graph {
  int n;
  vector<int> val;
  vector<vector<pair<int, int>>> adj;

public:
  explicit Graph(int n) {
    this->n = n;
    val = vector<int>(n + 1);
    adj = vector<vector<pair<int, int>>>(n + 1);
  }

  void set_val(int i, int val) { this->val[i] = val; }

  void add_edge(int a, int b, int dist) {
    adj[a].emplace_back(make_pair(b, dist));
    adj[b].emplace_back(make_pair(a, dist));
  }

  Edge shortest() {
    vector<Edge> e(n - 1, Edge{0, INT_MAX, 0});
    for (int i = 0; i < n - 1; ++i)
      e[i].to = i + 2;
    for (const auto &p : adj[1]) {
      e[p.first - 2].dist = p.second;
      e[p.first - 2].val = val[p.first];
    }
    Heap<Edge> heap(e);
    while (!heap.empty()) {
      Edge top = heap.extract_min();
      if (top.dist == INT_MAX)
        break;
      int from = top.to;
      if (from == n)
        return {top.to, top.dist, top.val + val[1]};
      vector<Edge> c = heap.container();
      for (int i = 0; i < c.size(); ++i) {
        int to = c[i].to;
        for (const auto &p : adj[from]) {
          if (p.first == to) {
            int new_dist = top.dist + p.second;
            int new_val = top.val + val[to];
            heap.decrease_key(i, Edge{to, new_dist, new_val});
          }
        }
      }
    }
    return {0, INT_MAX, 0};
  }
};

int main() {
  int n;
  cin >> n;
  Graph g(n);
  for (int i = 1; i <= n; ++i) {
    int val;
    cin >> val;
    g.set_val(i, val);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, dist;
    cin >> a >> b >> dist;
    g.add_edge(a, b, dist);
  }

  const auto &[to, dist, val] = g.shortest();

  if (dist < INT_MAX)
    cout << dist << " " << val;
  else
    cout << "impossible";
  return 0;
}