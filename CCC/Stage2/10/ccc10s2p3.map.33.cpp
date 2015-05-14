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

int xtoi[1000001];
int ni;
int itox[1000001];

typedef map<int,int> MII;
MII mii;

int main()
{
	int cs;
	scanf("%d",&cs);
	char cmd;
	int a,b;
	while(cs--)
	{
		cmd = getchar();
		while(cmd==' '||cmd=='\n')cmd = getchar();
		switch(cmd)
		{
		case 'N':
			scanf("%d%d",&a,&b);
			xtoi[a] = ni;
			itox[ni] = a;
			ni++;
			mii.insert(make_pair(b,xtoi[a]));
			break;
		case 'M':
			scanf("%d%d",&a,&b);
			for(MII::iterator it = mii.begin();it!=mii.end();it++)
			{
				if(it->second == xtoi[a])
				{
					mii.erase(it);
					mii.insert(make_pair(b,xtoi[a]));
					break;
				}
			}
			break;
		case 'Q':
			scanf("%d",&a);
			MII::iterator it = mii.end();
			advance(it,-a);
			printf("%d\n",itox[it->second]);
			break;
		}
	}
	return 0;
}