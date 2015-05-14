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

typedef pair<int,int> I2;
I2 g[200005];
int dp[200005];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
	{
		int x,w;
		scanf("%d %d",&x,&w);
		g[i].second = x - w;
		g[i].first = x + w;
	}
	sort(g,g+n);
	int r = INT_MIN;
	int maxd = 0;
	for(int i=0;i!=n;i++)
	{
		if(g[i].second >= r)
		{
			maxd+=1;
			r = g[i].first;
		}
	}
	cout << maxd << endl;
	return 0;
}