/*
 * CarsonIce.cpp
 *
 *  Created on: May 8, 2015
 *      Author: Andy Y.F. Huang (azneye)
 */

#include <bits/stdc++.h>

using namespace std;

void make_case() {
  const int N = 200;
  freopen("input.txt", "w", stdout);
  printf("%d %d\n", N, N);
  for (int r = 0; r < N; r++)
    printf("%s\n", string(N, r % 2 ? 'S' : 'E').c_str());
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

  int N, M;
  assert(cin >> N >> M);
  assert(1 <= min(N, M) && max(N, M) <= 2000);
  vector<string> grid(N);
  for (int r = 0; r < N; r++) {
    assert(cin >> grid[r]);
    assert((int )grid[r].size() == M);
    for (int c = 0; c < M; c++)
      assert(string("NSEW.").find(grid[r][c]) != string::npos);
  }
  vector<vector<int> > id(N, vector<int>(M, -1));
  vector<pair<int, int> > loc;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (grid[r][c] != '.') {
        loc.push_back(make_pair(r, c));
        id[r][c] = loc.size() - 1;
      }
    }
  }
  const int V = loc.size();
  vector<vector<int> > adj(V);
  vector<int> deg(V, 0);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (grid[r][c] == '.')
        continue;
      const int at = id[r][c];
      if (grid[r][c] == 'N') {
        for (int rr = r - 1; rr >= 0; rr--) {
          if (grid[rr][c] != '.') {
            adj[id[rr][c]].push_back(at);
            deg[at]++;
            if (grid[rr][c] == grid[r][c])
              break;
          }
        }
      } else if (grid[r][c] == 'S') {
        for (int rr = r + 1; rr < N; rr++) {
          if (grid[rr][c] != '.') {
            adj[id[rr][c]].push_back(at);
            deg[at]++;
            if (grid[rr][c] == grid[r][c])
              break;
          }
        }
      } else if (grid[r][c] == 'E') {
        for (int cc = c + 1; cc < M; cc++) {
          if (grid[r][cc] != '.') {
            adj[id[r][cc]].push_back(at);
            deg[at]++;
            if (grid[r][cc] == grid[r][c])
              break;
          }
        }
      } else if (grid[r][c] == 'W') {
        for (int cc = c - 1; cc >= 0; cc--) {
          if (grid[r][cc] != '.') {
            adj[id[r][cc]].push_back(at);
            deg[at]++;
            if (grid[r][cc] == grid[r][c])
              break;
          }
        }
      }
    }
  }

  srand(time(NULL));
  queue<int> q;
  vector<int> temp;
  vector<pair<int, int> > res;
  for (int v = 0; v < V; v++)
    random_shuffle(adj[v].begin(), adj[v].end());
  for (int v = 0; v < V; v++)
    if (deg[v] == 0)
      temp.push_back(v);
  random_shuffle(temp.begin(), temp.end());
  for (int i = 0; i < (int) temp.size(); i++)
    q.push(temp[i]);
  while (!q.empty()) {
    const int at = q.front();
    q.pop();
    res.push_back(loc[at]);
    for (int i = 0; i < (int) adj[at].size(); i++)
      if (--deg[adj[at][i]] == 0)
        q.push(adj[at][i]);
  }
  if (V != (int) res.size()) {
    cerr << "Error: Cycle in graph" << endl;
    return 1;
  }
  for (int i = 0; i < (int) res.size(); i++)
    cout << '(' << res[i].first << ',' << res[i].second << ")\n";

#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
  return 0;
}

