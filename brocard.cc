#include <cmath>
#include <iostream>

using namespace std;

const double eps = 1e-12;

struct Point {
  double x, y;

  void debug() { cout << "(" << x << ", " << y << ")"; }
};

struct Segment {
  Point a, b;
  void debug() {
    a.debug();
    cout << " ";
    b.debug();
    cout << endl;
  }
};

Point mid_point(Segment s) {
  return Point{(s.a.x + s.b.x) / 2, (s.a.y + s.b.y) / 2};
}

Segment vert(Segment s, Point p) {
  if (fabs(s.a.x - s.b.x) < eps)
    return Segment{p, Point{p.x + 1, p.y}};
  else if (fabs(s.a.y - s.b.y) < eps) {
    return Segment{p, Point{p.x, p.y + 1}};
  } else {
    double k = (s.b.y - s.a.y) / (s.b.x - s.a.x);
    k = -1 / k;
    return Segment{p, Point{p.x + 1, p.y + k}};
  }
}

Segment mid_vert(Segment s) { return vert(s, mid_point(s)); }

Point intersect(Segment s, Segment t) {
  double x1 = s.a.x, x2 = s.b.x, x3 = t.a.x, x4 = t.b.x, y1 = s.a.y, y2 = s.b.y,
         y3 = t.a.y, y4 = t.b.y;
  double y = ((y2 - y1) * (y4 - y3) * (x3 - x1) + (x2 - x1) * (y4 - y3) * y1 -
              (x4 - x3) * (y2 - y1) * y3) /
             ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
  double x;
  if (fabs(x1 - x2) < eps)
    x = x1;
  else if (fabs(x3 - x4) < eps)
    x = x3;
  else if (fabs(y1 - y2) < eps)
    x = (y - y3) * (x4 - x3) / (y4 - y3) + x3;
  else
    x = (y - y1) * (x2 - x1) / (y2 - y1) + x1;

  return Point{x, y};
}

Point mirror(Segment s, Point p) {
  Segment v = vert(s, p);
  Point o = intersect(s, v);
  return Point{o.x * 2 - p.x, o.y * 2 - p.y};
}

Point brocard(Point &A, Point &B, Point &C) {
  Segment a{B, C};
  Segment b{A, C};
  Segment c{A, B};
  Segment va = vert(c, A);
  Segment vb = vert(a, B);
  Segment mb = mid_vert(b);
  Segment mc = mid_vert(c);
  Point P = intersect(mc, vb);
  Point Q = intersect(mb, va);
  Segment s{P, Q};
  return mirror(s, A);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int idx;
    cin >> idx;
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    Point a{ax, ay};
    Point b{bx, by};
    Point c{cx, cy};
    Point in = brocard(a, b, c);
    printf("%d %.8f %.8f\n", idx, in.x, in.y);
  }
  return 0;
}