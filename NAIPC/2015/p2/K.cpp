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

int C,n;

int main()
{
	scanf("%d %d",&C,&n);
	long long c=0;
	for(int i=0;i!=n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		c-=x;
		if(c < 0)
		{
			printf("impossible\n");
			return 0;
		}
		c+=y;
		if(c > C)
		{
			printf("impossible\n");
			return 0;
		}
		if(z && (i==n-1 || c!=C))
		{
			printf("impossible\n");
			return 0;
		}
	}
	if(c!=0)
	{
		printf("impossible\n");
		return 0;
	}
	printf("possible\n");
	return 0;
}