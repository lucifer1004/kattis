#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

const char OPS[4]{'+', '-', '*', '/'};

int priority(char c) {
  switch (c) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '(':
    return 3;
  default:
    return 0;
  }
}

int operate(int a, char op, int b) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  default:
    return 0;
  }
}

int eval(string s) {
  s += ")";
  stack<int> nums;
  stack<char> ops;
  ops.push('(');
  int curr = 0;
  int digit = 0;
  for (int i = 0; i < s.size(); ++i) {
    switch (s[i]) {
    case ')':
      if (digit)
        nums.push(curr);
      curr = 0;
      digit = 0;
      while (ops.top() != '(') {
        char op = ops.top();
        ops.pop();
        if (nums.size() >= 2) {
          int b = nums.top();
          nums.pop();
          int a = nums.top();
          nums.pop();
          nums.push(operate(a, op, b));
        }
      }
      ops.pop();
      break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
      if (digit) {
        nums.push(curr);
        if (s[i] == '(')
          ops.push('*');
      }
      curr = 0;
      digit = 0;
      while (ops.top() != '(' && priority(ops.top()) >= priority(s[i])) {
        char op = ops.top();
        ops.pop();
        if (nums.size() >= 2) {
          int b = nums.top();
          nums.pop();
          int a = nums.top();
          nums.pop();
          nums.push(operate(a, op, b));
        }
      }
      ops.push(s[i]);
      break;
    case ' ':
      break;
    default:
      curr = curr * 10 + s[i] - '0';
      digit++;
    }
  }
  return nums.top();
}

int main() {
  unordered_map<int, string> solve;

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 4; ++k) {
        string expr = "4 " + string{OPS[i]} + " 4 " + string{OPS[j]} + " 4 " +
                      string{OPS[k]} + " 4";
        int val = eval(expr);
        solve[val] = expr + " = " + to_string(val);
      }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int n;
    cin >> n;
    cout << (solve[n] != "" ? solve[n] : "no solution") << endl;
  }

  return 0;
}