#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int INF = 1e8;

struct Edge {
  int from, to, len, id;
};

class Graph {
  int n, e;
  vector<vector<Edge>> adj;
  vector<Edge> edges;

  void dfs(vector<vector<int>> &pre, vector<bool> &used, vector<bool> &visited,
           int current) {
    if (visited[current])
      return;
    visited[current] = true;
    for (const int &i : pre[current]) {
      used[i] = true;
      dfs(pre, used, visited, edges[i].from);
    }
  }

public:
  explicit Graph(int num) {
    n = num;
    e = 0;
    adj = vector<vector<Edge>>(n);
  }

  void add_edge(int a, int b, int l) {
    Edge forward{a, b, l, e++};
    Edge backward{b, a, l, e++};
    edges.emplace_back(forward);
    adj[a].emplace_back(forward);
    edges.emplace_back(backward);
    adj[b].emplace_back(backward);
  }

  int shortest(int source, int target) {
    vector<vector<int>> pre(n);
    vector<int> dist(n, INF);
    unordered_set<int> to_extend;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    dist[source] = 0;

    for (int i = 0; i < n; ++i) {
      q.push({dist[i], i});
      to_extend.insert(i);
    }

    while (!to_extend.empty()) {
      auto top = q.top();
      q.pop();
      int mid = top.second;
      to_extend.erase(mid);
      for (const Edge &edge : adj[mid]) {
        int new_dist = dist[mid] + edge.len;
        int old_dist = dist[edge.to];
        if (new_dist == old_dist)
          pre[edge.to].emplace_back(edge.id);
        else if (new_dist < old_dist) {
          pre[edge.to].clear();
          pre[edge.to].emplace_back(edge.id);
          dist[edge.to] = new_dist;
          q.push({new_dist, edge.to});
        }
      }
    }

    vector<bool> used(e), visited(n);
    dfs(pre, used, visited, target);
    int ans = 0;
    for (int i = 0; i < e; ++i)
      if (used[i])
        ans += edges[i].len;

    return ans;
  }
};

int main() {
  int p, t;
  cin >> p >> t;
  Graph g(p);
  for (int i = 0; i < t; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    g.add_edge(a, b, l);
  }
  cout << g.shortest(0, p - 1) * 2;
}