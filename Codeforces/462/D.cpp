#include <algorithm>
#include <iostream>
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

const int MOD = 1000000007;

int n;
vector<int> G[100001];
int C[100001];
int vis[100001];
vector<int> gp[100001][2];
int gn;

void dfs(int v,int gi)
{
	gn = max(gn,gi+1);
	gp[gi][C[v]].push_back(v);
	for(int u:G[v]) if(!vis[u])
	{
		vis[u]=1;
		if(C[v] && C[u])
		{
			dfs(u,gi+1);
		} else {
			dfs(u,gi);
		}
	}
}

int main()
{
	cin >> n;
	for(int i=0;i!=n-1;i++)
	{
		int a;
		cin >> a;
		G[a].push_back(i+1);
		G[i+1].push_back(a);
	}
	for(int i=0;i!=n;i++)
		cin >> C[i];

	vis[0]=1;
	dfs(0,0);

	LL tot = 1;

	for(int i=0;i!=gn;i++)
	{
		cout << gp[i][1].size() << endl;
		if(gp[i][1].size() > 1)
		{
			for(int v : gp[i][1])
			{
				dfs2(v);
			}
		}
	}
	return 0;
}