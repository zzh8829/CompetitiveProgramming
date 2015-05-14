#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>

using namespace std;

#define INF (1<<30)

int bx[751],by[751];
int dist[751][751];
int done[751];
int n,m;

int SQDIST(int i,int j){
	return (bx[i]-bx[j])*(bx[i]-bx[j]) + (by[i]-by[j])*(by[i]-by[j]);
}

int ans[751][2];
int ansn;
int a,b;

deque<int> deq;

int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
		scanf("%d %d",&bx[i],&by[i]);
	for(int i=0;i!=n;i++)
		for(int j=i;j!=n;j++)
		{
			dist[i][j]= dist[j][i] =  SQDIST(i,j);
			if(i==j)dist[i][j]=INF;
		}
	scanf("%d",&m);
	for(int i=0;i!=m;i++)
	{		
		scanf("%d %d",&a,&b);
		--a;--b;
		dist[a][b] = dist[b][a] = 0;
	}
	double len = 0;
	done[0] = 1;
	deq.push_back(0);
	int min;
	int p,s,t;
	for(int c=1;c!=n;c++)
	{
		min = INF;
		for(int i=0;i!=deq.size();++i)
		{
			t = deq[i];
			for(int j=0;j!=n;++j) if(!done[j] && dist[t][j]<min)
			{
				min = dist[t][j];
				p = j;
				s = t;
			}
		}
		if(min){
			ans[ansn][0] = s;
			ans[ansn++][1] = p;
		}
		done[p] = 1;
		deq.push_back(p);
		len += sqrt(min);
	}
	printf("%.2f\n",len);
	for(int i=0;i!=ansn;i++)
		printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
	return 0;
}