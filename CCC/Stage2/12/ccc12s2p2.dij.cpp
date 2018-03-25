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
#include <climits>
using namespace std;

const int INF = 1<<30;

typedef pair<int,int> PII;

int n,m;
int dis[20001][2];
vector< PII > r[20001];
priority_queue< int > q;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i!=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		r[a].push_back(PII(b,c));
	}
	for(int i=0;i<=n;i++)
		dis[i][0] = dis[i][1] = INF;
	dis[1][0] = 0;
	q.push(1);
	while(!q.empty())
	{
		int p = q.top();q.pop();
		for(int i=0;i!=r[p].size();i++)
		{
			int p2 = r[p][i].first;
			int d2 = r[p][i].second;
			if(dis[p][0] + d2 < dis[p2][0]) {
				dis[p2][1] = dis[p2][0];
				dis[p2][0] = dis[p][0] + d2;
			} else if(dis[p][0] + d2 < dis[p2][1] &&
					  dis[p][0] + d2 > dis[p2][0]) {
				dis[p2][1] = dis[p][0] + d2;
			} else if(dis[p][1] + d2 < dis[p2][1]) {
				dis[p2][1] = dis[p][1] + d2;
			} else 
				continue;
			q.push(p2);
		}
	}
	if(dis[n][1]!=INF)
		cout << dis[n][1] << endl;
	else
		cout << -1 << endl;
	return 0;
}