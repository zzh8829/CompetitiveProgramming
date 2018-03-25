/*
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

typedef long long LL;

const LL INF = 4000000000000000000LL;

int n,m,K,q;
LL dis[202][202];
int totn;
LL totd;

int main()
{
	freopen("vacation.in","r",stdin);
	freopen("vacation.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&K,&q);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)if(i!=j)
			dis[i][j] = INF;
	for(int i=0;i!=m;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		dis[u][v] = min(dis[u][v],(LL)d);
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=0;i!=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		LL best = INF;
		for(int j=1;j<=K;j++)
			best = min(best,dis[a][j] + dis[j][b]);
		if(best < INF)
		{
			totn ++;
			totd +=  best;
		}
	}
	cout << totn << endl << totd << endl;
	return 0;
}
*/
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <iterator>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 

typedef long long LL;
const LL INF = 400000000000000000LL;
bool connected[205][205];
LL shortest[205][205];
int main()
{
    freopen("vacation.in", "r", stdin);
    freopen("vacation.out", "w", stdout);
    int N, M, K, Q;
    cin>>N>>M>>K>>Q;
    int u, v, d;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i==j)
            {
                shortest[i][j]=0;
                connected[i][j]=true;
            }
            else
                shortest[i][j]=INF;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v>>d;
        shortest[u][v]=d;
        connected[u][v]=true;
    }
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(connected[i][j] && connected[j][k] && shortest[i][j]+shortest[j][k]<shortest[i][k])
                    shortest[i][k]=shortest[i][j]+shortest[j][k];
    int possible=0;
    int suma=0;
    for(int i=0; i<Q; i++)
    {
        cin>>u>>v;
        int shortsofar=0x3f3f3f3f;
        for(int j=1; j<=K; j++)
        {
            if(connected[u][j] && connected[j][v] && shortest[u][j]+shortest[j][v]<shortsofar)
                shortsofar=shortest[u][j]+shortest[j][v];
        }
        if(shortsofar!=0x3f3f3f3f)
        {
            possible++;
            suma+=shortsofar;
        }
    }
    cout<<possible<<'\n';
    cout<<suma<<'\n';
 
    return 0;
}