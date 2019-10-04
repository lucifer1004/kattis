#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vb> vvb;

const ll modulo = 1e9 + 7;

enum OPERATION {
  FLIP,
  ISOLATE,
};

struct Operation {
  OPERATION type;
  int op1, op2;
};

class Graph {
  int v_;
  bool transposed, flipped;
  vll ref;
  vvb mat[2]; // Using double matrices to make flip a lot easier.
  vector<Operation> cached_operations;

  void update() {
    ll last = ref[ref.size() - 1];
    ll next = last * 7 % modulo;
    ref.emplace_back(next);
  }

  void do_isolate(int a) {
    for (int i = 0; i < v_; ++i) {
      mat[flipped][i][a] = false;
      mat[1 - flipped][i][a] = true;
    }
    mat[flipped][a] = vb(v_, false);
    mat[1 - flipped][a] = vb(v_, true);
  }

  void do_flip(int a, int b) {
    if (transposed)
      swap(a, b);
    mat[0][a][b] = !mat[0][a][b];
    mat[1][a][b] = !mat[1][a][b];
  }

  void cache_operation(OPERATION type, int op1, int op2) {
    cached_operations.emplace_back(Operation{type, op1, op2});
  }

  void perform_cached_operations() {
    for (const Operation &operation : cached_operations) {
      switch (operation.type) {
      case (OPERATION::FLIP):
        do_flip(operation.op1, operation.op2);
        break;
      case (OPERATION::ISOLATE):
        do_isolate(operation.op1);
        break;
      }
    }
    cached_operations.clear();
  }

  void regularize() {
    perform_cached_operations();

    if (transposed) {
      for (int i = 0; i < v_ - 1; ++i)
        for (int j = i + 1; j < v_; ++j) {
          swap(mat[0][i][j], mat[0][j][i]);
          swap(mat[1][i][j], mat[1][j][i]);
        }
      transposed = false;
    }
  }

public:
  explicit Graph(int v) {
    v_ = v;
    mat[0] = vvb(v, vb(v));
    mat[1] = vvb(v, vb(v, true));
    transposed = false;
    flipped = false;
    ref = vll{1};
    for (int i = 1; i < v; ++i)
      update();
  }

  void add_vertex() {
    for (int i = 0; i < v_; ++i) {
      mat[flipped][i].emplace_back(false);
      mat[1 - flipped][i].emplace_back(true);
    }
    mat[flipped].emplace_back(vb(++v_));
    mat[1 - flipped].emplace_back(vb(v_, true));
    update();
  }

  void isolate(int a) { cache_operation(OPERATION::ISOLATE, a, 0); }

  void transpose() {
    perform_cached_operations();
    transposed = !transposed;
  }

  void flip() {
    perform_cached_operations();
    flipped = !flipped;
  }

  void flip(int a, int b) { cache_operation(OPERATION::FLIP, a, b); }

  void summary() {
    regularize();

    cout << v_ << endl;
    for (int i = 0; i < v_; ++i) {
      int out_degree = 0;
      ll ans = 0;
      for (int j = 0; j < v_; ++j) {
        if (j == i)
          continue;
        if (mat[flipped][i][j]) {
          ans += j * ref[out_degree];
          ans %= modulo;
          out_degree++;
        }
      }
      cout << out_degree << " " << ans << endl;
    }
  }
};

int main() {
  int v, e, q;
  cin >> v >> e >> q;

  Graph g(v);
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    g.flip(a, b);
  }

  for (int i = 0; i < q; ++i) {
    int cmd, a, b;
    cin >> cmd;
    switch (cmd) {
    case 1:
      g.add_vertex();
      break;
    case 2:
    case 4:
      cin >> a >> b;
      g.flip(a, b);
      break;
    case 3:
      cin >> a;
      g.isolate(a);
      break;
    case 5:
      g.transpose();
      break;
    case 6:
      g.flip();
    default:
      break;
    }
  }

  g.summary();

  return 0;
}