/*
ID: zzh8829
PROG: crowded
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int,int> I2;
I2 cows[50001];
char cro[50001];
int n,d,cnt;

int main()
{
#ifndef LOCAL1
	freopen("crowded.in","r",stdin);
	freopen("crowded.out","w",stdout);
#endif
	scanf("%d%d",&n,&d);
	for(int i=0;i!=n;i++)
		scanf("%d%d",&cows[i].second,&cows[i].first);
	sort(cows,cows+n);
	for(int i=n-1;i>=0;i--)
	{
		int h = cows[i].first>>1;
		int idx = upper_bound(cows,cows+i,I2(h,INT_MAX))-cows;
		if(idx<n&&idx>0&&cows[idx].first == cows[idx-1].first)idx++;
		for(int j=0;j!=idx;j++)if(cro[j]!=3)
		{
			int dif = cows[j].second-cows[i].second;
			if(dif>=0) cro[j]|=1;
			if(dif<=0) cro[j]|=2;
			if(cro[j]==3)cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
