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

typedef long long LL;
typedef pair<int,int> II;

int n,m,b,mod;
int a[501];
int dp[501][501];

int main()
{
	cin >> n >> m >> b >> mod;
	rep(i, 0, n)
		cin >> a[i];
	// people, lines, bug

	for(int i=0;i!=m;i++)
	{
		dp[]
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j!=b;j++)
		{
			for(int k=0;k<=m;k++)
			{
				for(int l=0;l<=b;l++)
				{
					dp[i][j] += dp[k][k] * dp[n-k][b-l];
				}
			}
		}
	}
	cout << dp[n][b] << endl;
	return 0;
}
