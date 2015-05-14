#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

bool bm[12];
int n1,n2,n3,n4;
int best = INT_MAX;
int a[12];

void combinations(int pos,int k,void (*callback)(),int& nt)
{
	if(k==0) {
		callback();
		return ;
	}
	for(int i=pos;i<12-k+1;i++)if(!bm[i])
	{
		nt += a[i];
		bm[i]=1;
		combinations(i+1,k-1,callback,nt);
		bm[i]=0;
		nt -= a[i];
	}
}

void combo4()
{
	best = min(best,max(max(max(n1,n2),n3),n4) - min(min(min(n1,n2),n3),n4));
}

void combo3()
{
	if(max(max(n1,n2),n3) - min(min(n1,n2),n3) >= best )return;
	combinations(0,3,combo4,n4);
}

void combo2()
{
	if(max(n1,n2) - min(n1,n2) >=best ) return;
	combinations(0,3,combo3,n3);
}

void combo1()
{
	combinations(0,3,combo2,n2);
}

int main()
{
#ifndef LOCAL
	freopen("bteams.in","r",stdin);
	freopen("bteams.out","w",stdout);
#endif
	for(int i=0;i!=12;i++)
		cin >> a[i];
	combinations(0,3,combo1,n1);
	cout << best << endl;
	return 0;
}
