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

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(it, xs) for (auto it = xs.begin(); it!=xs.end(); it++)
#define rirep(it, xs) for (auto it = xs.rbegin(); it!=xs.rend(); it++)
#define erep(e, xs) for (auto& e : (xs))
#define rint(x) scanf("%d", &(x))
#define rfloat(x) scanf("%lf", &(x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> II;

LL pm[5000005];
LL fn[5000005];
LL dp[5000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,a,b;
	rint(t);

	for(LL i=2;i!=5000001;i++)
	{
		if(!pm[i])
		{
			for(int j=i;j<=5000001;j+=i)
			{
				pm[j]=1;
				int k=j;
				while(k%i==0)
				{
					fn[j]++;
					k/=i;
				}
			}
		}
	}
	/*
	for(int i=0;i!=100;i++)
		cout << fn[i] << " ";
	cout << endl;
	*/
	rep(i, 1, 5000001)
	{
		dp[i] = dp[i-1] + fn[i];
	}
	/*
	cout << endl;
	for(int i=0;i!=100;i++)
		cout << dp[i] << " ";
	*/
	rep(i, 0, t)
	{
		rint(a);rint(b);
		cout << dp[a] - dp[b] << endl;
	}
	return 0;
}
