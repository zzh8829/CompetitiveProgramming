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
int B,N;

LL f(LL mi)
{
	LL n = 0;
	rep(i, 0, B)
	{
		n += mi/ms[i] + 1;
	}
	return n;
}

int main()
{
	int T;
	rint(T);
	rep(t, 0, T)
	{
		rint(B),rint(N);
		rep(i, 0, B)
			rint(ms[i]);
		LL lo = 0;
		LL hi = 1e17;
		while(lo < hi)
		{
			LL mi = (lo + hi)/2;
			if(f(mi) < N)
			{
				lo = mi+1;
			} else {
				hi = mi;
			}
 		}
		vector<int> vi;
		LL l = 0;
		rep(i, 0, B)
		{
			l += lo/ms[i] + 1;
			if(lo%ms[i]==0)
			{
				vi.push_back(i);
			}
		}
		printf("Case #%d: %d\n", t+1, vi[vi.size()-1 - l + N] + 1);
	}
	return 0;
}