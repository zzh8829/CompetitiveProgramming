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
#include <iomanip>
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

double c[256];
int v[256];
double dp[101];

int K,L,S;
string key,tar;
int rp;
double base,inc,cur;

double rec(int l)
{
	if(l < L)
	{
		return 0;
	}
	//cout << "rec: " << l << endl;
	// AB B

	if(dp[l] == -1)
	{
		dp[l] = 0;
		cur = base;
		int k=1;
		for(int i=L;i<=S;i+=rp)
		{
			double x = cur * ( k + rec(l-i));
			dp[l] += x;
			if(l-i-rp >= 0)
				dp[l] -= k * cur * inc + rec(l-i-rp);
			cur *= inc;
			k++;
		}
	}
	return dp[l];
}

int main()
{
	int T;
	rint(T);
	rep(t, 0, T)
	{
		rint(K);rint(L);rint(S);
		cin >> key;
		cin >> tar;
		memset(c,0,sizeof(c));
		rep(i, 0, K)
		{
			c[key[i]]++;
		}
		rep(i, 0, 255)
			c[i]/=K;
		rp=L;
		for(int i=1;i!=L;i++)
		{
			int f=true;
			for(int j=i;j!=L;j++)
			{
				if(tar[j-i] != tar[j])
					f=false;
			}
			if(f)
			{
				rp=i;
				break;
			}
		}
		base = 1;
		rep(i, 0, rp)
		{
			base *= c[tar[i]];
		}
		inc = 1;
		rep(i, rp, L)
		{
			inc *= c[tar[i]];
		}
		if(rp == L)
			inc = base;
		int mx = 0;
		if(base * inc > 0)
		{
			mx = (S-L)/rp + 1;
		}
		//cout << base << " " << inc << endl;
		rep(i, 0, S+1)
			dp[i] = -1;
		dp[L] = 1;
		rep(i, 0, L)
			dp[L] *= c[tar[i]];
		double s = rec(S);
        cout << "Case #" << t+1 << ": " << setprecision(10) << (double)mx-s << endl;
	}
	return 0;
}
