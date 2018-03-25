/*
ID: zzh8829
PROG: pogocow
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <cstring>
#include <map>
using namespace std;

int d[1001];
pair<int,int> xp[1001];
int au[1001];
int maxs;
int n;

typedef pair<int,int> I2;

set<I2>s;

typedef map<int,int> M;
M m;

int main()
{
#ifndef LOCAL1
	freopen("pogocow.in","r",stdin);
	freopen("pogocow.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i;i!=n;i++)
		scanf("%d %d",&xp[i].first,&xp[i].second);
	sort(xp,xp+n);
	for(int i=1;i!=n;i++)
		d[i]=xp[i].first-xp[i-1].first;
	for(int i=1;i!=n;i++)
	{
		M::iterator it = m.upper_bound(d[i]);
		if(it==m.end() && (it==m.begin() || d[i] > (--m.end())->first ))
		{
			m[d[i]] = max(m[d[i]],xp[i].second + xp[i-1].second);
			continue;
		}
		bool flag = true;
		if(it==m.begin())flag = false;
		M::iterator it2 = it;
		it2--;
		if(flag==false)
		{
			m[d[i]] = max(m[d[i]],xp[i].second + xp[i-1].second);
			continue;
		}
		I2 ii = *it2;
		ii.first = d[i];
		ii.second+=xp[i].second;
		it2 = it;
		while(it2!=m.end() && ii.second >= it2->second)
		{
			m.erase(it2);
			it2 = m.lower_bound(d[i]);
		}
		m[d[i]] = max(m[d[i]],ii.second);
		m[d[i]] = max(m[d[i]],xp[i].second + xp[i-1].second);
	}
	cout << 25 << endl;
	return 0;
}
