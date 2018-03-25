#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 1<<30;

typedef pair<int,int> PII;

int n,m;
vector<PII> g[20001];
vector<PII> rg[20001];

int cntkpath[20001], kpath[20001];

int dis[20001];

void dijkstra()
{
	for(int i=0;i!=n;i++)
		dis[i] = INF;
	dis[n-1]=0;
	priority_queue<PII> q;
	q.push(PII(0,n-1));
	vis[n-1]=1;
	while(!q.empty())
	{
		int p = q.top().second;q.pop();
		for(int i=0;i!=rg[p].size();i++)
		{
			if(dis[rg[p][i].first] > dis[p] + rg[p][i].second)
			{
				dis[rg[p][i].first] = dis[p] + rg[p][i].second;
				q.push(PII(dis[rg[p][i].first],rg[p][i].first));
			}
		}
	}
}

struct E {
	int p, d, h;
	E(int _p,int _d,int _h):p(_p),d(_d),h(_h){}
	bool operator<(const E &e) const {
		return d + h > e.d + e.h;
	}
};

void astar()
{
	for(int i = 0; i < n; i++)
		kpath[i] = -1;
	priority_queue<E> q;
	q.push(E(0,0,dis[0]));
	while(!q.empty()) 
	{
		E e = q.top();q.pop();
		if(cntkpath[e.p] >= 2 || kpath[e.p] == e.d+e.h)
		   continue;
		cntkpath[e.p]++;
		kpath[e.p] = e.d+e.h;
		if(e.p == n-1 && cntkpath[e.p] == 2) 
		{
			printf("%d\n", e.d);
			return;
		}
		for(int i=0;i!=g[e.p].size();i++)
			q.push(E(g[e.p][i].first, e.d + g[e.p][i].second, dis[g[e.p][i].first]));
	}
	printf("-1\n");
}

int main() 
{
	scanf("%d%d",&n,&m);
	int a,b,c;
	for(int i=0;i!=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		g[a-1].push_back(PII(b-1, c));
		rg[b-1].push_back(PII(a-1, c));
	}
	dijkstra();
	astar();
	return 0;
}