/*
 * Eggscavation.cpp
 *
 * O(M * sum(S_i * 2^(S_i)) + N*N + N^2 log^2 N + N^2 log M Q log M)
 *
 *  Created on: May 9, 2015
 *      Author: Andy Y.F. Huang (azneye)
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
struct Rect {
  int r1, c1, r2, c2;

  Rect(int r1 = -INF, int c1 = -INF, int r2 = INF, int c2 = INF)
      : r1(r1), c1(c1), r2(r2), c2(c2) {
  }

  Rect intersect(const Rect& r) const {
    return Rect(max(r1, r.r1), max(c1, r.c1), min(r2, r.r2), min(c2, r.c2));
  }

  bool empty() const {
    return r1 > r2 || c1 > c2;
  }

};

const int PW = 4096;
const int MAX_N = 4000;
const int MAX_M = 100000;
int N, K, M;
int cnt[PW][PW];
int bit[MAX_M + 1];
int tree[4 * PW * PW];
Rect zero_rect;

void update_bit(int pos, int val) {
  if (pos == 0)
    return;
  for (int i = pos; i <= M; i += i & -i)
    bit[i] += val;
}

int get_bit(int pos) {
  pos = min(pos, M);
  int res = 0;
  for (int i = pos; i > 0; i -= i & -i)
    res += bit[i];
  return res;
}

void build_quad(int at, int r1, int r2, int c1, int c2) {
  if (r1 == r2) {
    tree[at] = cnt[r1][c1];
    return;
  }
  const int rmid = (r1 + r2) >> 1;
  const int cmid = (c1 + c2) >> 1;
  build_quad(4 * at + 1, r1, rmid, c1, cmid);
  build_quad(4 * at + 2, r1, rmid, cmid + 1, c2);
  build_quad(4 * at + 3, rmid + 1, r2, c1, cmid);
  build_quad(4 * at + 4, rmid + 1, r2, cmid + 1, c2);
  tree[at] = max(max(tree[4 * at + 1], tree[4 * at + 2]), max(tree[4 * at + 3], tree[4 * at + 4]));
}

void update_quad(int at, int r1, int r2, int c1, int c2) {
  if (tree[at] == 0)
    return;
  if (zero_rect.intersect(Rect(r1, c1, r2, c2)).empty())
    return;
  if (r1 == r2) {
    update_bit(cnt[r1][c1], -1);
    tree[at] = 0;
    return;
  }
  const int rmid = (r1 + r2) >> 1;
  const int cmid = (c1 + c2) >> 1;
  update_quad(4 * at + 1, r1, rmid, c1, cmid);
  update_quad(4 * at + 2, r1, rmid, cmid + 1, c2);
  update_quad(4 * at + 3, rmid + 1, r2, c1, cmid);
  update_quad(4 * at + 4, rmid + 1, r2, cmid + 1, c2);
  tree[at] = max(max(tree[4 * at + 1], tree[4 * at + 2]), max(tree[4 * at + 3], tree[4 * at + 4]));
}

void update(int r1, int c1, int r2, int c2, int val) {
  if (r1 > r2 || c1 > c2)
    return;
  cnt[r1][c1] += val;
  cnt[r1][c2 + 1] -= val;
  cnt[r2 + 1][c1] -= val;
  cnt[r2 + 1][c2 + 1] += val;
}

void make_case() {
  srand(123456789);
  freopen("input.txt", "w", stdout);
  const int N = 40, K = 1, M = 10, Q = 20;
  printf("%d %d %d\n", N, K, M);
  for (int i = 0; i < M; i++) {
    const int S = rand() % 4 + 1;
    printf("%d ", S);
    for (int j = 0; j < S; j++) {
      const int r = rand() % N + 1, c = rand() % N + 1;
      printf("%d %d ", r, c);
    }
    printf("\n");
  }
  printf("%d\n", Q);
  for (int qq = 0; qq < Q; qq++) {
    const int type = rand() % 2 + 1;
    printf("%d ", type);
    if (type == 1) {
      const int r = rand() % N + 1, c = rand() % N + 1;
      printf("%d %d\n", r, c);
    } else {
      const int v = rand() % (M / 10) + 1;
      printf("%d\n", v);
    }
  }
  fflush(stdout);
}

int main() {
#ifdef AZN
  //make_case();
  double start_t = clock();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  assert(cin >> N >> K >> M);
  assert(1 <= N && N <= 2500);
  assert(1 <= K && K <= N);
  assert(0 <= M && M <= 100000);

  const Rect all(1, 1, N - K + 1, N - K + 1);
  memset(cnt, 0, sizeof(cnt));
  for (int qq = 0, S; qq < M; qq++) {
    assert(cin >> S);
    assert(1 <= S && S <= 4);
    static pair<int, int> loc[4];
    for (int j = 0; j < S; j++) {
      assert(cin >> loc[j].first >> loc[j].second);
      assert(1 <= loc[j].first && loc[j].first <= N);
      assert(1 <= loc[j].second && loc[j].second <= N);
    }
    static Rect poss[4];
    for (int i = 0; i < S; i++)
      poss[i] = Rect(loc[i].first - K + 1, loc[i].second - K + 1, loc[i].first, loc[i].second);
    for (int mask = 1; mask < (1 << S); mask++) {
      Rect cur(all);
      for (int i = 0; i < S; i++)
        if (mask >> i & 1)
          cur = cur.intersect(poss[i]);
      if (__builtin_popcount(mask) & 1)
        update(cur.r1, cur.c1, cur.r2, cur.c2, 1);
      else
        update(cur.r1, cur.c1, cur.r2, cur.c2, -1);
    }
  }

  memset(bit, 0, sizeof(bit));
  for (int r = 1; r < PW; r++) {
    for (int c = 1; c < PW; c++) {
      cnt[r][c] += cnt[r - 1][c] + cnt[r][c - 1] - cnt[r - 1][c - 1];
      update_bit(cnt[r][c], 1);
    }
  }

  build_quad(0, 0, PW - 1, 0, PW - 1);

  int Q;
  assert(cin >> Q);
  assert(1 <= Q && Q <= 10000);
  for (int qq = 0, type; qq < Q; qq++) {
    assert(cin >> type);
    assert(type == 1 || type == 2);
    if (type == 1) {
      int r, c;
      assert(cin >> r >> c);
      assert(1 <= min(r, c) && max(r, c) <= N);

      zero_rect = all.intersect(Rect(r - K + 1, c - K + 1, r, c));
      update_quad(0, 0, PW - 1, 0, PW - 1);
    } else {
      int v;
      assert(cin >> v);
      assert(1 <= v && v <= 1000000000);

      const double res = (get_bit(M) - get_bit(v - 1)) / (N - K + 1.0) / (N - K + 1.0);
      cout << fixed << setprecision(4) << res << endl;
    }
  }

#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
  return 0;
}

