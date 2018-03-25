#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> I2;

int n;
I2 cow[10001];

int c,m;
set<int> si;

int main()
{
#ifndef LOCAL1
	freopen("msched.in","r",stdin);
	freopen("msched.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
		scanf("%d%d",&cow[i].second,&cow[i].first);
	sort(cow,cow+n);
	for(int t=0;t<=10001;t++)
	{
		m += cow[c].second;
		si.insert(cow[c].second );
		c++;
		while(c<n && cow[c].first <= t+1)
		{
			if( *si.begin() < cow[c].second )
			{
				m -= *si.begin();
				si.erase(si.begin());
				m += cow[c].second;
				si.insert(cow[c].second);
			}
			c++;
		}
		if(c==n) break;
	}
	printf("%d\n",m);
	return 0;
}
