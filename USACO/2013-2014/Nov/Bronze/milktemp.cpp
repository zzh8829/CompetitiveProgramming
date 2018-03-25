/*
ID: zzh8829
PROG: milktemp
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> eq;
pair<int,int> ps[20001];
int tot;
int maxn;
int N,X,Y,Z;

int main()
{
#ifndef LOCAL1
	freopen("milktemp.in","r",stdin);//ifstream cin("milktemp.in");
	freopen("milktemp.out","w",stdout);//ofstream cout("milktemp.out");
#endif
	scanf("%d %d %d %d",&N,&X,&Y,&Z);
	for(int i=0;i!=N;i++)
		scanf("%d %d",&ps[i].first,&ps[i].second);
	sort(ps,ps+N);
	tot = N*X;
	for(int i=0;i!=N;i++)
	{
		int temp = ps[i].first;
		while(!eq.empty() && eq.top() < temp)
		{
			eq.pop();
			tot = tot - Y + Z;
		}
		tot = tot + Y - X;
		maxn = max(tot,maxn);
		eq.push(ps[i].second);
	}
	cout << maxn << endl;
	return 0;
}