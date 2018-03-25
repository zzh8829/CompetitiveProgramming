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
typedef long long ULL;

int m;
int T;

struct G
{
	int l,t,r,b,k;
};

vector<G> vg;
set<int> sx;
set<int> sy;
unordered_map<int,int> mx;
int mrx[4001];
unordered_map<int,int> my;
int mry[4001];

ULL gd[2601][2601];

int main()
{
	cin >> m >> T;
	for(int i=0;i!=m;i++)
	{
		G g;
		cin >> g.l >> g.t >> g.r >> g.b >> g.k;

		sx.insert(g.l);
		sy.insert(g.t);
		sx.insert(g.r);
		sy.insert(g.b);

		vg.push_back(g);
	}
	int nx = 0;
	for(set<int>::iterator it=sx.begin();it!=sx.end();it++)
	{
		mx[*it] = nx;
		mrx[nx] = *it;
		nx++;
	}
	int ny = 0;
	for(set<int>::iterator it=sy.begin();it!=sy.end();it++)
	{
		my[*it] = ny;
		mry[ny] = *it;
		ny++;
	}

	for(int i=0;i!=m;i++)
	{
		for(int j=mx[vg[i].l];j!=mx[vg[i].r];j++)
		{
			gd[j][my[vg[i].t]] += vg[i].k;
			gd[j][my[vg[i].b]] -= vg[i].k;
		}	
	}

	ULL tot = 0;
	for(int i=0;i!=nx-1;i++)
	{
		for(int j=0;j!=ny-1;j++)
		{
			gd[i][j+1] = gd[i][j] + gd[i][j+1];
			if(gd[i][j] >= T)
			{
				tot += ULL(mrx[i+1] - mrx[i]) * ULL(mry[j+1] - mry[j]);
			}
		}
	}
	cout << tot << endl;
	return 0;
}