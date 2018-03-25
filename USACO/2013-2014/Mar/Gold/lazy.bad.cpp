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

int n,k,x,y;

vector<vector<int> > grid;
 
int ct[100001];
int cb[100001];
int cl[100001];
int cr[100001];
int cg[100001];

set<int> sx,sy;
int nx,ny;
unordered_map<int,int> mx,my;

int main()
{
	freopen("lazy.hard.in","r",stdin);
	freopen("lazy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i!=n;i++)
	{
		scanf("%d%d%d",&cg[i],&x,&y);
		ct[i] = y-k;
		cb[i] = y+k;
		cl[i] = x-k;
		cr[i] = x+k;
	}
	sy.insert(ct,ct+n);
	sy.insert(cb,cb+n);
	sx.insert(cl,cl+n);
	sx.insert(cr,cr+n);
	for(set<int>::iterator it=sy.begin();it!=sy.end();it++)
		my[*it]=ny++;
	for(set<int>::iterator it=sx.begin();it!=sx.end();it++)
		mx[*it]=nx++;

	cout << ny*(long long)nx << endl;

	grid.resize(ny);
	for(int i=0;i!=ny;i++)
		grid[i].resize(nx);
	for(int i=0;i!=n;i++)
	for(int j=my[ct[i]];j!=my[cb[i]];j++)
	{
		grid[j][mx[cl[i]]] += cg[i];
		grid[j][mx[cr[i]]] -= cg[i];
	}
	int best = 0;
	for(int i=0;i!=ny-1;i++)
	for(int j=0;j!=nx-1;j++)
	{
		grid[i][j+1] = grid[i][j] + grid[i][j+1];
		best = max(best,grid[i][j]);
	}
	cout << best << endl;
	return 0;
}