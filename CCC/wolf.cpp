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
#include <sstream>

using namespace std;

#define MOD 1000000007

int N,W,M;

vector<int> adj[201];
int rel[201][201];
int par[201];

int dp[201][201][201][2];
long long rec(int u, size_t x, int w, bool wolf)
{
	if(dp[u][x][w][wolf]==-1)
	{
		if(x==adj[u].size())
			dp[u][x][w][wolf] = w < 2 && w==wolf;
		else
		{
			int v=adj[u][x];
			dp[u][x][w][wolf] = 0;
			if(wolf)
			for(int i=0; i<w; i++)
			{
				dp[u][x][w][wolf] += (rec(v, 0, i, rel[u][v]!='A')%MOD * rec(u, x+1, w-i, wolf)%MOD)%MOD;
				dp[u][x][w][wolf] %= MOD;
			}
			else
			for(int i=0; i<=w; i++)
			{
				dp[u][x][w][wolf] += rec(u, x+1, w-i, wolf)%MOD * ((rec(v,0,i,0) + rec(v,0,i,1)) % MOD)%MOD;
				dp[u][x][w][wolf] %= MOD;
			}
		}
	}
	return dp[u][x][w][wolf];
}

int main()
{
	memset(dp,0xff,sizeof(dp));
	memset(rel,'D',sizeof(rel));
	cin >> N >> W >> M;
	for(int i=0;i!=M;i++)
	{
		char c;
		int x,y;
		cin >> c >> x >> y;
		rel[x][y] = c;
		adj[x].push_back(y);
		par[y] = 1;
	}
	for(int i=1;i<=N;i++)
		if(!par[i])
			adj[0].push_back(i);	
	cout << rec(0,0,W,0)%MOD << endl;
	return 0;
}