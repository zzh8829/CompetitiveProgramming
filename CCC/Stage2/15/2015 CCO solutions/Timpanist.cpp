/*
 * Timpanist.cpp
 *
 *  Created on: May 9, 2015
 *      Author: Andy Y.F. Huang (azneye)
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef AZN
  double start_t = clock();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, D;
  assert(cin >> N >> D);
  assert(1 <= N && N <= 100);
  assert(1 <= D && D <= 4);
  vector<int> t(N), p(N);
  for (int i = 0; i < N; i++) {
    assert(cin >> t[i] >> p[i]);
    assert(0 <= t[i] && t[i] <= 1000000000);
    if (i > 0)
      assert(t[i] > t[i - 1]);
    assert(1 <= p[i] && p[i] <= 12);
    p[i]--;
  }
  set<int> notes(p.begin(), p.end());
  if ((int) notes.size() <= D) {
    cout << "0.00\n";
    return 0;
  }
  static int tunes[555][555];
  static double dp[111][555];
  vector<int> vals;
  for (int mask = 0; mask < (1 << 12); mask++)
    if ((int) __builtin_popcount(mask) == D)
      vals.push_back(mask);
  const int V = vals.size();
  for (int a = 0; a < V; a++) {
    for (int b = 0; b < V; b++) {
      vector<int> x, y;
      for (int i = 0; i < 12; i++) {
        if (1 << i & vals[a])
          x.push_back(i);
        if (1 << i & vals[b])
          y.push_back(i);
      }
      tunes[a][b] = 0;
      for (int i = 0; i < D; i++)
        if (x[i] != y[i])
          tunes[a][b]++;
    }
  }
  for (int i = 0; i < N; i++)
    fill(dp[i], dp[i] + V, -1e10);
  for (int v = 0; v < V; v++)
    if (1 << p[0] & vals[v])
      dp[0][v] = 1e10;
  for (int i = 0; i + 1 < N; i++)
    for (int fr = 0; fr < V; fr++)
      for (int to = 0; to < V; to++)
        if (1 << p[i + 1] & vals[to])
          dp[i + 1][to] = max(dp[i + 1][to],
              min(dp[i][fr], tunes[fr][to] == 0 ? 1e10 : 1.0 * (t[i + 1] - t[i]) / tunes[fr][to]));
  const double res = *max_element(dp[N - 1], dp[N - 1] + V);
  cout << fixed << setprecision(2) << res << endl;

#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
  return 0;
}

