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

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(it, xs) for (auto it = xs.begin(); it!=xs.end(); it++)
#define rirep(it, xs) for (auto it = xs.rbegin(); it!=xs.rend(); it++)
#define erep(e, xs) for (auto& e : (xs))
#define rint(x) scanf("%d", &(x))
#define rfloat(x) scanf("%lf", &(x))

typedef long long LL;
typedef pair<int,int> II;

int n,m;

map<II, int> em;
map<II, int> im;
vector<II> g[300005];
LL d[300005];
II pre[300005];

int main()
{
	rint(n), rint(m);
	rep(i, 0, m)
	{
		int u,v,w;
		rint(u);rint(v);rint(w);
		if(u > v) swap(u,v);
		if(em.count(II(u,v)))
		{
			if(em[II(u,v)] > w)
			{
				em[II(u,v)] = w;
				im[II(u,v)] = i;
			}
		} else {
			em[II(u,v)] = w;
			im[II(u,v)] = i;
		}
	}
	irep(it, em)
	{
		g[it->first.first].push_back(II(it->first.second,it->second));
		g[it->first.second].push_back(II(it->first.first,it->second));
	}
	int u;
	rint(u);
	priority_queue<II, vector<II>, greater<II>> pq;
	pq.push(II(0,u));
	fill_n(d, 300005, (LL)1e18);
	d[u] = 0;
	while(!pq.empty())
	{
		II cur = pq.top();pq.pop();
		int x = cur.second;
		erep(e, g[x])
		{
			if(d[e.first] > d[x] + e.second || (d[e.first] == d[x] + e.second && pre[e.first].second > e.second))
			{
				d[e.first] = d[x] + e.second;
				pre[e.first] = II(x,e.second);
				pq.push(II(e.second, e.first));
			}
		}
	}
	vector<int> vi;
	LL tot = 0;
	rep(i, 1, n+1) if(i!=u)
	{
		tot += pre[i].second;
		vi.push_back(im[II(min(i,pre[i].first),max(i,pre[i].first))]);
	}
	cout << tot << endl;
	erep(e, vi)
	{
		cout << e+1 << " ";
	}
	cout << endl;
	return 0;
}
