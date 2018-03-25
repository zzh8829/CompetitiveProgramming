#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
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
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int,int> I2;

vector<I2> g[1001];
int d[1001];

map<I2, int> mi;

int main()
{
  int N,M,A,B,K,G;
  cin >> N >> M;
  cin >> A >> B >> K >> G;

  vector<int> vg;
  for (int i = 0; i < G; i++)
  {
    int x;
    cin >> x;
    vg.push_back(x);
  }

  for (int i = 0; i< M; i++)
  {
    int a,b,l;
    cin >> a >> b >> l;
    g[a].push_back(I2(l,b));
    g[b].push_back(I2(l,a));

    mi[I2(a,b)] = l;
    mi[I2(b,a)] = l;
  }

  map<int, I2> mi2;

  int t = 0;
  for(int i = 1; i < G; i++)
  {
    t += mi[I2(vg[i-1], vg[i])];
    mi2[t] = I2(vg[i-1], vg[i]);
  }

  priority_queue<I2> q;

  for(int i = 0; i < 1001; i++)
    d[i] = 99999999;

  d[A] = K;
  q.push(I2(K, A));

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

      map<int, I2>::iterator git = mi2.lower_bound(d1);

      cout << d1 << endl;
      cout << git->second.first << " " << git->second.second << endl;

      if(I2(u,v) == git->second ||
        I2(v,u) == git->second)
      {
        int t1 = git->first;
        d3 += (++git)->first - t1;
      }

      if(d3 < d[v])
      {
        q.push(I2(d3, v));
        d[v] = d3;
      }
    }
  }

  cout << d[B] << endl;

  return 0;
}
