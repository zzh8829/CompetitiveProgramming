/*
 * SolarFlight.cpp
 *
 *  Created on: May 9, 2015
 *      Author: Andy Y.F. Huang (azneye)
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct Interval {
  double st, ed;
  int val;

  Interval(double st, double ed, int val)
      : st(st), ed(ed), val(val) {
  }

  bool operator<(const Interval& i) {
    return st < i.st;
  }
};
int y_st[2222], y_ed[2222], cost[2222];
vector<Interval> event[2222];
const double EPS = 1e-8;

int main() {
#ifdef AZN
  double start_t = clock();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int X, K, N, Q;
  assert(cin >> X >> K >> N >> Q);
  assert(1 <= X && X <= 1000000000);
  assert(1 <= K && K <= 1000000000);
  assert(1 <= N && N <= 2000);
  assert(1 <= Q && Q <= 800000);
  for (int i = 1; i <= N; i++) {
    assert(cin >> y_st[i] >> y_ed[i] >> cost[i]);
    assert(1 <= y_st[i] && y_st[i] <= 1000000000);
    assert(1 <= y_ed[i] && y_ed[i] <= 1000000000);
    assert(1 <= cost[i] && cost[i] <= 1000000000);
  }
  assert(N == (int ) set<int>(y_st + 1, y_st + N + 1).size());
  assert(N == (int ) set<int>(y_ed + 1, y_ed + N + 1).size());

  static pair<int, int> query[800111];
  for (int q = 0; q < Q; q++) {
    assert(cin >> query[q].first >> query[q].second);
    assert(1 <= query[q].first && query[q].first <= N);
    assert(0 <= query[q].second && query[q].second <= X - K);
  }

  vector<ll> res(Q, 0);
  vector<vector<pair<int, int> > > quests(N + 1);
  for (int q = 0; q < Q; q++)
    quests[query[q].first].push_back(make_pair(query[q].second, q));

  vector<pair<double, int> > st, ed;
  vector<pair<double, ll> > vals; //(x value, interference value)
  deque<int> dq;
  for (int i = 1; i <= N; i++) {
    st.clear();
    ed.clear();
    vals.clear();
    for (int j = 1; j <= N; j++) {
      if (i == j)
        continue;
      if (y_st[i] > y_st[j] && y_ed[i] > y_ed[j])
        continue;
      if (y_st[i] < y_st[j] && y_ed[i] < y_ed[j]) {
        st.push_back(make_pair(-1, cost[j]));
        ed.push_back(make_pair(X - EPS, cost[j]));
        continue;
      }
      const double bi = y_st[i], bj = y_st[j];
      const double mi = (double) (y_ed[i] - y_st[i]) / X, mj = (double) (y_ed[j] - y_st[j]) / X;
      const double x = (bi - bj) / (mj - mi);
      if (y_st[i] < y_st[j]) {
        st.push_back(make_pair(-1, cost[j]));
        st.push_back(make_pair(x, 0));
        ed.push_back(make_pair(x - EPS, cost[j]));
      } else {
        st.push_back(make_pair(x + EPS, cost[j]));
        ed.push_back(make_pair(X + 1, cost[j]));
      }
    }
    st.push_back(make_pair(-1, 0));
    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end());

    ll now = 0;
    for (int a = 0, b = 0; a < (int) st.size(); a++) {
      for (; b < (int) ed.size() && ed[b].first <= st[a].first; b++)
        now -= ed[b].second;
      now += st[a].second;
      vals.push_back(make_pair(st[a].first, now));
    }
    vector<pair<int, int> >& cur_q = quests[i];
    sort(cur_q.begin(), cur_q.end());
    dq.clear();
    for (int j = 0, k = 0; j < (int) cur_q.size(); j++) {
      for (; k < (int) vals.size() && vals[k].first <= cur_q[j].first + K; k++) {
        while (!dq.empty() && vals[k].second >= vals[dq.back()].second)
          dq.pop_back();
        dq.push_back(k);
      }
      while (!dq.empty() && vals[dq.front()].first < cur_q[j].first)
        dq.pop_front();
      const ll prev_val = (--lower_bound(vals.begin(), vals.end(),
          make_pair((double) cur_q[j].first, -1LL)))->second;
      if (dq.empty())
        res[cur_q[j].second] = prev_val;
      else if (cur_q[j].first < vals[dq.front()].first)
        res[cur_q[j].second] = max(prev_val, vals[dq.front()].second);
      else
        res[cur_q[j].second] = vals[dq.front()].second;
    }
  }

  for (int q = 0; q < Q; q++)
    cout << res[q] << '\n';

#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
  return 0;
}

