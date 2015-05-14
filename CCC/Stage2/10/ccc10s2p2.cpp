#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

int INF = 1<<30;

int dp[402][802];

#define P(x) (x)+350

int n;
int d;
struct Node
{
	int child[2];
	int type;
	int cn;
}ns[400];

int tot ;

int dfs(int i)
{
	int maxn[2] = {0,0};
	dp[i][P(0)] = 1;
	for(int j=0;j!=ns[i].cn;j++)
	{
		maxn[j] = dfs(ns[i].child[j]);
	}
	dp[i][P(maxn[0]+maxn[1]+ns[i].type)] = 0;
	if(ns[i].cn == 0)
	{
		dp[i][P(ns[i].type)] = 0;
		dp[i][P(0)] = 1;
	} else if(ns[i].cn == 1)
	{
		for(int j=-310;j!=310;j++)
			dp[i][P(j+ns[i].type)] = min(dp[ns[i].child[0]][P(j)],dp[i][P(j+ns[i].type)]);
		
	} else if(ns[i].cn == 2)
	{
		for(int j=-310;j!=310;j++)
			for(int k=-310;k!=310;k++)
			{
				if(-310<=j+k && j+k <= 310 && dp[ns[i].child[0]][P(j)]!=INF && dp[ns[i].child[1]][P(k)]!=INF)
					dp[i][P(j+k+ns[i].type)] = min( dp[ns[i].child[0]][P(j)]+dp[ns[i].child[1]][P(k)],dp[i][P(j+k+ns[i].type)]);

			}
	}
	return maxn[0]+maxn[1]+ns[i].type;
}

void out(int i)
{
	for(int j=0;j!=ns[i].cn;j++)
	{
		out(ns[i].child[j]);
	}
	cout << i << endl;
}

int main()
{
	for(int i=0;i!=400;i++)
		for(int j=0;j!=800;j++)
			dp[i][j] = INF;
	cin >> n >> d;
	int a,b;
	for(int i=0;i!=n;i++)
	{
		cin >> a;
		cin >> ns[a].type >> ns[a].cn;
		ns[a].type = ns[a].type?1:-1;
		for(int i=0;i!=ns[a].cn;i++)
		{
			cin >>  ns[a].child[i];
		}
	}
//	cout << tot << endl;

//	out(0);

	dfs(0);
	if(dp[0][P(d)]==INF)
		cout << -1 << endl;
	else
		cout << dp[0][P(d)] << endl;
	return 0;
}