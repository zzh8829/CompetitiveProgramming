#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

vector<I2> g[1001];
int d[1001];
int tt[1001];
int t[1001];

map<I2, int> mi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N,M,A,B,K,G;
  cin >> N;

  for(int i = 1; i <= N; i++)
  {
    cin >> t[i];
  }

  cin >> M;

  for (int i = 0; i< M; i++)
  {
    int a,b,l;
    cin >> a >> b >> l;
    g[a].push_back(I2(l,b));
    g[b].push_back(I2(l,a));

    mi[I2(a,b)] = l;
    mi[I2(b,a)] = l;
  }

  priority_queue<I2, vector<I2>, greater<I2> > q;

  for(int i = 0; i < 1001; i++)
    d[i] = 0x3f3f3f3f;

  d[1] = 0;
  tt[1] = t[1];
  q.push(I2(0, 1));

  while(!q.empty())
  {
    int d1 = q.top().first;
    int u = q.top().second;
    q.pop();

    if(d1 > d[u]) continue;

    for(int i = 0; i < g[u].size(); i++)
    {
      int v = g[u][i].second;
      int d2 = g[u][i].first;

      int d3 = d1 + d2;

      if(d3 < d[v])
      {
        q.push(I2(d3, v));
        d[v] = d3;
        tt[v] = tt[u] + t[v];
      }
      else if(d3 == d[v])
      {
        q.push(I2(d3, v));
        d[v] = d3;
        tt[v] = max(tt[v], tt[u] + t[v]);
      }
    }
  }

  if(d[N] == 0x3f3f3f3f) 
  {
    cout << "impossible" << endl;
  }
  else
  {
    cout << d[N] << " " << tt[N] << endl;
  }
  return 0;
}
