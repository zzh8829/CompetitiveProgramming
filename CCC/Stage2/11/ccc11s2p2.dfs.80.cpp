#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>
#include <list>
#include <algorithm>

using namespace std;

struct Edge
{
	Edge(int e,int d,int c):end(e),dis(d),cost(c)
	{
		if(cost)cost = dis;
	};
	int end,dis,cost;
};

int n,t,en;
int mind = 2e9;
vector<Edge> g[1605];

int v[1605];

void dfs(int pos,int dis,int cost)
{
	if(dis >= mind)return;
	if(cost > t)return;
	if(pos==n-1)
	{
		mind = dis;
		return;
	}
	for(int i=0;i!=g[pos].size();i++)
	{
		if(v[g[pos][i].end])continue;
		v[g[pos][i].end] = 1;
		dfs(g[pos][i].end,dis+g[pos][i].dis,cost+g[pos][i].cost);
		v[g[pos][i].end] = 0;
	}
}
bool cmp(Edge a,Edge b)
{
	return a.dis < b.dis;
}
int main()
{
	cin >> t >> n >> en;
	for(int i=0;i!=en;i++)
	{
		int beg,end,dis,cost;
		cin >> beg >> end >> dis >> cost;
		g[beg].push_back(Edge(end,dis,cost));
		g[end].push_back(Edge(beg,dis,cost));
	}

	for(int i=0;i!=n;i++)sort(g[i].begin(),g[i].end(),cmp);
	v[0]=1;
	dfs(0,0,0);
	cout << (mind==2e9?-1:mind) << endl;	
	system("pause");
	return 0;
}