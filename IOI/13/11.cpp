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

typedef pair<int,int> I2;

int N,M,L;
int dia[100001];
int rad[100001];

int vis[100001];
int vis2[100001];

vector<int> g[100001];

int fa[100001];
int next[100001];

int rec_dia(int cur,int from, int d)
{
	vis[cur]=1;
	int maxd = 0;
	int maxu;
	for(int i=0;i!=g[cur].size();i++)if(g[cur][i].first != from)
	{
		int dd = rec(g[cur][i].first,cur,d + g[cur][i].second);
		if(dd > maxd)
		{
			maxd = dd;
			maxu = g[cur][i].first;
		}
	}
	next[cur+1] = maxu+1;
	return maxd;
}

int main()
{
	freopn("in.txt","r",stdin);
	scanf("%d%d%d",&N,&M,&L);
	for(int i=0;i!=M;i++)
	{
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		g[A].push_back(I2(B,C));
		g[B].push_back(I2(A,C));
	}
	int tn = 0;
	for(int i=0;i!=N;i++)if(!vis[i])
	{
		rec_dia(i);
		int cur=i;
		while(next[cur])
		{
			cout << cur << " ";
			cur = next[cur];
		}
		cout << endl;
		memset(next,0,sizeof(next));
		dia[tn] = rec_dia(cur);



		tn++;
	}
	
	return 0;
}
