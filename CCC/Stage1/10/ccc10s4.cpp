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

const int INF = 1<<20;
typedef pair<int,int> PII;
int n;
int dis[101][101];
map<PII,int> mpp;
map<PII,int> mpd;
int ie[9];

int prim(int tot)
{
	int v[101];
	memset(v,0,sizeof(v));
	int con = 1;
	int len = 0;
	v[0] = 1;
	while(con!=tot)
	{
		int md = INF;
		int pos;
		for(int i=0;i!=tot;i++)if(v[i])
		for(int j=0;j!=tot;j++)if(!v[j])
		if(dis[i][j] < md)
		{
			md = dis[i][j];
			pos =j;
		}
		v[pos] = 1;
		len += md;
		con++;
	}
	return len;
}

int main()
{
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			dis[i][j] = INF;
	cin >> n; 
	for(int pe=0;pe!=n;pe++)
	{
		int m,t,t1,t2;
		cin >> m;
		for(int i=0;i!=m;i++)
			cin >> ie[i];
		ie[m] = ie[0];
		for(int i=0;i!=m;i++)
		{
			cin >> t;
			t1 = ie[i];
			t2 = ie[i+1];
			if(t2<t1)swap(t1,t2);
			PII p = PII(t1,t2);
			if(mpp.count(p))
			{
				dis[mpp[p]][pe] = dis[pe][mpp[p]] = min(t,dis[pe][mpp[p]]);
				mpp.erase(p);
			} else {
				mpp[p] = pe;
				mpd[p] = t;
			}
		}
	}
	for(auto& it:mpp)
		if(mpd[it.first] < dis[it.second][n])
			dis[n][it.second] = dis[it.second][n] = mpd[it.first];
	cout << min(prim(n),prim(n+1)) << endl;
	return 0;
}