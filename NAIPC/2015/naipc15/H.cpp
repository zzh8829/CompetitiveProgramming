#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int,int> I2;

int fs[1000005];
int ps[1000005];
int ms[1000005];
int ss[1000005];
int mm[1000005];

vector<int> gr[1000005];

int ns=0;
int vb[1000005];
int cn;
int tc;

void dfs(int x, int n)
{
	vb[x] = n;
	for(int i=0;i!=gr[x].size();i++)
	{
		if(!vb[x])
		{
			dfs(gr[x][i],n);
		} else {
			cn = gr[x][i];
			continue;
		}
	}
}

void dfs2(int x, int n)
{
	vb[x] = n;
	if(ps[i] < ms[fs[i]])
	{
		if(!vb[x])
		{
			dfs(fs[i],n);
		} else {
			cn = fs[i];
			continue;
		}
	}
}



int main()
{
	LL tot = 0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&fs[i]);
		scanf("%d",&ps[i]);
		scanf("%d",&ms[i]);
		scanf("%d",&ss[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(ps[i] < ms[fs[i]])
		{
			gr[fs[i]].push_back(i);
			if(!mm[fs[i]] || ps[i] < mm[fs[i]])
			{
				mm[fs[i]] = ps[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mm[i])
			tot += 1LL * (ms[i] - mm[i]) * (ss[i] - 1);
	}
	cout << tot << endl;
	for(int i=1;i<=n;i++) if(!vb[i])
	{
		cn = 0;
		tc = 0;
		dfs(i,++ns);
		if(cn)
		{

		} else {
			tot += tc;
		}
	}
	cout << tot << endl;
	return 0;
}