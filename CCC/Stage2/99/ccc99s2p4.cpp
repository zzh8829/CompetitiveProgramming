#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

struct P
{
	P(int _x=0,int _y=0):x(_x),y(_y){};
	int x,y;
	bool operator<(const P& p) const
	{
		return x < p.x || (x==p.x && y <p.y);
	}
	double distance(const P& p)
	{
		return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	}
};

P ps[101];
P tps[202];

double cross_product(P a,P o,P b)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int main()
{
	int cs,n;
	cin >> cs;
	while(cs--)
	{
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			cin >> ps[i].x >> ps[i].y;
		}
		sort(ps,ps+n);
		int k =0;
		double dis = 0;
		for(int i=0;i!=n;i++)
		{
			while(k>=2&& cross_product(tps[k-2],tps[k-1],ps[i])<=0)k--;
			tps[k++] = ps[i];
		}
		int t = k+1;
		for(int i=n-2;i>=0;i--)
		{
			while(k>=t && cross_product(tps[k-2],tps[k-1],ps[i])<=0)k--;
			tps[k++] = ps[i];
		}
		for(int i=0;i!=k-1;i++)
		{
			if(!i)dis+=tps[k-1].distance(tps[0]);
			dis+=tps[i].distance(tps[i+1]);
		}

		printf("%.2f\n",dis);
	}
	
	return 0;
}