#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef pair<int,int> I2;
vector<I2> g[251];
int* p[251][251][2];
int M,N;
int dis[251];
int prev[251];
int iq[251];
int best;
int dif;


int main()
{
	ifstream cin("rblock.in");
	ofstream cout("rblock.out");
	cin >> N >> M;
	N--;
	for(int i=0;i!=N;i++)
		g[i].reserve(300);
	for(int i=0;i!=M;i++)
	{
		int a,b,l;
		cin >> a >> b >> l;
		a--;b--;
		g[a].push_back(I2(b,l));
		g[b].push_back(I2(a,l));
		p[a][b][0]=p[b][a][0]=(int*)(&g[a][g[a].size()-1].second);
		p[a][b][1]=p[b][a][1]=(int*)(&g[b][g[b].size()-1].second);
	}
	queue<int> q;
	memset(iq,0,sizeof(iq));
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.push(0);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		iq[u]=0;
		for(int i=0;i!=g[u].size();i++)
		{
			int v = g[u][i].first;
			int l = g[u][i].second;
			if(dis[v] > dis[u] + l)
			{
				dis[v] = dis[u]+l;
				prev[v] = u;
				if(!iq[v])
				{
					iq[v]=1;
					q.push(v);
				}
			}
		}
	}
	best = dis[N];
	int cur=N;
	int last=prev[cur];
	while(cur!=0)
	{
		int org = *(p[cur][last][0]);
		*p[cur][last][0]=*p[cur][last][1]=org*2;

		queue<int> qq;
		memset(iq,0,sizeof(iq));
		memset(dis,0x3f,sizeof(dis));
		dis[0]=0;
		qq.push(0);
		while(!qq.empty())
		{
			int u = qq.front();qq.pop();
			iq[u]=0;
			for(int i=0;i!=g[u].size();i++)
			{
				int v = g[u][i].first;
				int l = g[u][i].second;
				if(dis[v] > dis[u] + l)
				{
					dis[v] = dis[u]+l;
					if(!iq[v])
					{
						iq[v]=1;
						qq.push(v);
					}
				}
			}
		}
		dif = max(dif,dis[N]-best);

		*p[cur][last][0]=*p[cur][last][1]=org;
		cur = prev[last];
		swap(cur,last);
	}
	cout << dif << endl;
	return 0;
}