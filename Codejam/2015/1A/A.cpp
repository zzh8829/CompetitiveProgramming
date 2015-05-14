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

int ms[1005];

int main()
{
	int T;
	rint(T);
	rep(t, 0, T)
	{
		int N;
		rint(N);
		rep(i, 0 , N)
		{
			rint(ms[i]);
		}
		int c = ms[0];
		int ans = 0;
		rep(i, 1, N)
		{
			if(c > ms[i])
			{
				ans += c-ms[i];
			}
			c = ms[i];
		}
		int md = 0;
		rep(i, 0, N-1)
		{
			if(ms[i] > ms[i+1])
			{
				md = max(md,ms[i] - ms[i+1]);
			}
		}
		int ans2 = 0;
		rep(i, 0, N-1)
		{
			int eat = min(ms[i], md);
			ans2 += eat;
		}
		printf("Case #%d: %d %d\n",t+1, ans, ans2);
	}
	return 0;
}