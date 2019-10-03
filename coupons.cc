#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Ticket {
  int a, b, t, costs;
};

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  vector<int> pos, time;
  for (int i = 0; i < n; ++i) {
    int p, t;
    cin >> p >> t;
    pos.emplace_back(p);
    time.emplace_back(t);
  }
  if (n == 1) {
    cout << 2 + pos[0];
    return 0;
  }
  list<Ticket> tickets{Ticket{0, pos[0], time[0] + 10000, 2 + pos[0]}};

  for (int i = 1; i < n; ++i) {
    int min_costs = INT_MAX;
    for (auto ticket = tickets.begin(); ticket != tickets.end(); ++ticket) {
      min_costs = min(min_costs, ticket->costs);

      if (ticket->t < time[i]) {
        ticket = tickets.erase(ticket); // Ticket expires.
        ticket--;
      } else {
        if (pos[i] < ticket->a) {
          ticket->costs += ticket->a - pos[i];
          ticket->a = pos[i];
        }
        if (pos[i] > ticket->b) {
          ticket->costs += pos[i] - ticket->b;
          ticket->b = pos[i];
        }
        // This optimization is critical.
        while (ticket != tickets.begin()) {
          auto last = prev(ticket);
          if (ticket->costs <= last->costs && ticket->a <= last->a &&
              ticket->b >= last->b)
            tickets.erase(last);
          else
            break;
        }
      }
    }
    tickets.emplace_back(Ticket{min(pos[i - 1], pos[i]),
                                max(pos[i - 1], pos[i]), time[i] + 10000,
                                min_costs + 2 + abs(pos[i] - pos[i - 1])});
  }

  int ans = INT_MAX;
  for (const Ticket &ticket : tickets)
    ans = min(ans, ticket.costs);
  cout << ans;
  return 0;
}