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
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

int pm[10000001];
int cm[10000001];

int main()
{
	for(int i=2;i<=10000000;i++)
	{
		if(pm[i] == 0)
		{
			for(int j=1;;j++)
			{
				int k = j*i;
				if(k > 10000000) break;
				pm[k]+=1;
			}
		}
	}
	int tt,a,b,k;
	cin >> tt;
	for(int t=0;t!=tt;t++)
	{
		cin >> a >> b >> k;
		int ans = 0;
		for(int i=a;i<=b;i++)
			if(pm[i]==k)
				ans++;
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	return 0;
}