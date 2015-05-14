#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

struct P
{
	P(int _s,int _n):s(_s),n(_n){}
	int s,n;
};
vector<P> m[30];
int n,n2,cs;

P mmax(P a,P b) {
	if(a.s > b.s) return a;
	return b;
}

int main()
{
	scanf("%d%d",&n,&cs);
	n2 = pow(2.0,n);
	for(int i=0;i<=n;i++)
		m[i].push_back(P(-1,-1));
	for(int i=0;i!=n2;i++)
	{
		int t;
		scanf("%d",&t);
		m[0].push_back(P(t,i+1));
	}
	for(int i=0;i!=n;i++)
		for(int j=1;j<= pow(2.0,n-i-1);j++)
			m[i+1].push_back(mmax(m[i][j*2-1],m[i][j*2]));
	int t1,t2,cnt;
	for(int c=0;c!=cs;c++)
	{
		getchar();
		char cmd = getchar();
		switch(cmd)
		{
			case 'R':
				scanf("%d%d",&t1,&t2);
				m[0][t1].s=t2;
				for(int i=0;i!=n;i++)
				{
					if(t1%2)t1++;
					m[i+1][t1/2] = mmax(m[i][t1],m[i][t1-1]);
					t1/=2;
				}
				break;
			case 'W':
				printf("%d\n", m[n][1].n);
				break;
			case 'S':
				scanf("%d",&t1);
				t2 = t1,cnt= 0;
				for(int i=0;i!=n;i++)
				{
					if(t1%2)t1++;
					if(m[i+1][t1/2].n == t2) cnt++;
					else break;
					t1/=2;
				}
				printf("%d\n",cnt);
				break;
		}
	}
	return 0;
}	