/*
 * HungryFox.cpp
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
  typedef long long ll;

  int N, W;
  assert(cin >> N >> W);
  assert(1 <= N && N <= 100000);
  assert(0 <= W && W <= 1000000000);
  vector<int> t(N);
  for (int i = 0; i < N; i++) {
    assert(cin >> t[i]);
    assert(0 <= t[i] && t[i] <= 1000000000);
  }
  sort(t.begin(), t.end());
  ll low;
  if (W < t[0])
    low = t[N - 1] - W;
  else if (W > t[N - 1])
    low = W - t[0];
  else
    low = t[N - 1] - t[0];
  ll high = low;
  for (int its = 0; its < 2; its++) {
    int prev = W;
    ll now = 0;
    reverse(t.begin(), t.end());
    for (int i = 0, l = 0, r = N - 1; l <= r; i++) {
      if (i & 1) {
        now += max(abs(t[l] - prev), abs(t[l] - W));
        prev = t[l++];
      } else {
        now += max(abs(t[r] - prev), abs(t[r] - W));
        prev = t[r--];
      }
    }
    high = max(high, now);
  }

  cout << low << " " << high << endl;

#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
  return 0;
}

