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

int N,M,Q;

int P[100001];
int P2[100001];

int main()
{
#ifndef LOCAL1
	freopen("shuffle.in","r",stdin);
	//freopen("shuffle.out","w",stdout);
#endif
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=M;i++)
	{
		scanf("%d",&P[i]);
		P2[P[i]] = i;
	}
	for(int i=0;i!=Q;i++)
	{
		int a;
		scanf("%d",&a);
		a = N-a+1;
		if(a<M-1)
		{
			int md = a;
			int p = 1;
			for(int j=0;j<md;j++)
			{
				p = P2[p]+1;
			}
			printf("%d\n",p-1);
		} else {
			int ip,p,d;
			ip = p= 1;
			d = 0;
			if(a+M-1 > N)
			{
				ip = p = M-(N-a);
			}
			while(p!=M+1 && a-d>1)
			{
				p = P2[p]+1;
				d++;
				//cout << p << endl;
			}
			printf("%d\n",a-d+1+(M-ip));
		}
	}
	return 0;
}