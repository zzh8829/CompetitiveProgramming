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

typedef long long LL;
int T,N,M;
int x1,a1,b1,c1,r1;
int x2,a2,b2,c2,r2;

LL n1[1000001];
LL n2[1000001];

LL tot;

int main()
{
	freopen("magic.in","r",stdin);
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d%d",&N,&M);
		scanf("%d%d%d%d%d",&x1,&a1,&b1,&c1,&r1);
		scanf("%d%d%d%d%d",&x2,&a2,&b2,&c2,&r2);
		n1[0] = x1;
		n2[0] = x2;
		for(int i=1;i!=max(N,M);i++)
		{
			if(i<N)
			n1[i] =  (a1 * n1[(i-1) % N] + b1 * n2[(i-1) % M] + c1) % r1;
			if(i<M)
			n2[i] =  (a2 * n1[(i-1) % N] + b2 * n2[(i-1) % M] + c2) % r2;
		}
		set<int> s1;
		set<int> s2;
		s1.insert(n1[0]);
		tot = 0;
		int g1 = 1;
		int g2 = 0;
		while(true)
		{
			int cnt1 = 1;
			while(g1<N && s1.count(n1[g1]))
			{
				cnt1++;
				g1++;
			}
			while(g2<M && s1.size()!=s2.size())
			{
				if(g2<M) s2.insert(n2[g2++]);
				if(s1.size()==s2.size() && s1==s2)
				{
					tot+=cnt1;
					while(g2<M && s2.count(n2[g2]))
					{
						g2++;
						tot+=cnt1;
					}
				}
			}
			if(g1<N)
				s1.insert(n1[g1++]);
			else 
				break;
		}
		cout << "Case #" << cs << ": " << tot << endl;
	}
	return 0;
}