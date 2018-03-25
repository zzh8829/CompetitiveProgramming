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

int n;
int k;
int maxd;

struct Cow
{
	int x,b;
	int st[8];
	bool operator<(const Cow& c) const
	{
		return x < c.x;
	}
} cow[100001];

bool operator<(const Cow& c,const int x)
{
	return c.x < x;
}

bool ok(int a, int b)
{
	int cnt = 0;
	int num = -1;
	for(int i=0;i!=8;i++)
	{
		int v = cow[b].st[i]-cow[a].st[i];
		if(v)
		{
			if(num < 0)
				num = v;
			else if(num == v)
				cnt++;
			else
				return false;
		}
	}
	return cnt >= k;
}

int find(int x)
{
	Cow* c = lower_bound(cow,cow+n,x);
	return c-cow;
}

int dis(int a,int b)
{
	int x = cow[a].x;
	if(a > 0)
		x = cow[a-1].x+1;
	if(b < n-1)
		return cow[b+1].x - x;
	return cow[b].x - x;
}

int main()
{
	freopen("fairphoto.in","r",stdin);
	freopen("fairphoto.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=0;i!=n;i++)
		scanf("%d %d",&cow[i].x,&cow[i].b);
	sort(cow,cow+n);
	for(int i=0;i!=n;i++)
	{
		for(int j=0;i && j!=8;j++)
			cow[i].st[j] += cow[i-1].st[j];
		cow[i+1].st[cow[i].b-1]++;
	}	
	for(int i=0;i!=n;i++)
	{
		for(int j=find(cow[i].x+maxd);j!=n;j++)
		{
			if(ok(i,j+1))
			{
				maxd = max(maxd,cow[j-1].x-cow[i].x+1);
			}
		}
	}
	cout << (maxd?maxd:-1) << endl;
	return 0;
}