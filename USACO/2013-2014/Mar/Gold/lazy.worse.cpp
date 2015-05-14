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
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

int n,k,g,x,y;
 
struct Seg
{
	int x,t,b,g; 
};

bool cmp(const Seg& a, const Seg& b)
{
	return a.x!=b.x?a.x<b.x:a.t!=b.t?a.t<b.t:a.b!=b.b?a.b<b.b:a.g<b.g;
}

Seg ss[200005];
int vy[100001];
int ct[100001];
int cb[100001];

set<int> sy;
int ny;
unordered_map<int,int> my;

int main()
{
	freopen("lazy.hard.in","r",stdin);
	freopen("lazy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i!=n;i++)
	{
		scanf("%d%d%d",&g,&x,&y);
		ss[i*2].t = ss[i*2+1].t = ct[i] = y-k;
		ss[i*2].b = ss[i*2+1].b = cb[i] = y+k;
		ss[i*2].x = x-k;
		ss[i*2].g = g;
		ss[i*2+1].x = x+k;
		ss[i*2+1].g = -g;
	}
	sy.insert(ct,ct+n);
	sy.insert(cb,cb+n);

	for(set<int>::iterator it=sy.begin();it!=sy.end();it++)
		my[*it]=ny++;

	cout << ny << endl;

	sort(ss,ss+n,cmp);

	int best = 0;
	for(int i=0;i!=2*n;i++)
	{
		for(int j=0;j!=ny;j++)
			best = max(best,vy[j]);
		for(int j=my[ss[i].t];j!=my[ss[i].b];j++)
			vy[j] += ss[i].g;
	}
	cout << best << endl;
	return 0;
}