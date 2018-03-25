/*
 * Artskjid.cpp
 *
 *  Created on: May 8, 2015
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

  int N, M;
  assert(cin >> N >> M);
  assert(1 <= N && N <= 18);
  assert(1 <= M && M <= N * (N - 1));
  vector<vector<pair<int, int> > > g(N);
  for (int i = 0, s, d, l; i < M; i++) {
    assert(cin >> s >> d >> l);
    assert(s != d);
    assert(0 <= min(s, d) && max(s, d) <= N - 1);
    assert(1 <= l && l <= 10000);
    g[s].push_back(make_pair(d, l));
  }
  vector<vector<int> > dp(N, vector<int>(1 << N, int(-1e9)));
  dp[0][1 << 0] = 0;
  for (int mask = 1; mask < (1 << N); mask++)
    for (int fr = 0; fr < N; fr++)
      if (1 << fr & mask)
        for (int e = 0; e < (int) g[fr].size(); e++)
          if (1 << g[fr][e].first & ~mask)
            dp[g[fr][e].first][1 << g[fr][e].first | mask] = max(
                dp[g[fr][e].first][1 << g[fr][e].first | mask], dp[fr][mask] + g[fr][e].second);
  const int res = *max_element(dp[N - 1].begin(), dp[N - 1].end());
  cout << res << endl;

#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
  return 0;
}

