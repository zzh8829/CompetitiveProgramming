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

#define Fx(x, n) for (int x = 0; x < (n); x++)
#define Fi(n) Fx(i, n)
#define Fj(n) Fx(j, n)
#define Fij(ni, nj) Fi(ni) Fj(nj)
#define Frx(x, n) for (int x = (n)-1; x >= 0; x--)
#define Fri(n) Frx(i, n)
#define Frj(n) Frx(j, n)
#define Fitx(x, xs) for (auto x = xs.begin(); x!=xs.end(); x++)
#define Fit(xs) Fitx(it, xs)
#define Fritx(x, xs) for (auto x = xs.rbegin(); x!=xs.rend(); x++)
#define Frit(xs) Fritx(it, xs)
#define Fe(x, xs) for (auto& x : (xs))
#define Ri(x) scanf("%d", &(x))
#define Rf(x) scanf("%lf", &(x))

typedef long long LL;
typedef pair<int,int> I2;

int mult[4][4] = {
	{1,2,3,4},
	{2,1,4,3},
	{3,4,1,2},
	{4,3,2,1}
};

int sign[4][4] = {
	{1,1,1,1},
	{1,-1,1,-1},
	{1,-1,-1,1},
	{1,1,-1,-1}
};

struct Q
{
	int v,s;
	Q(int _v =0, int _s=1):v(_v),s(_s){}
	Q mul(Q b)
	{
		return Q(mult[v-1][b.v-1],s * b.s * sign[v-1][b.v-1]);
	}
	void print()
	{
		cout << (s==1?"":"-") << (v==1?"1":v==2?"i":v==3?"j":"k");
	}
};

int ss[20005];
Q dp[20005];

int main()
{
	int T;
	Ri(T);
	Fx(t,T)
	{
		int L,X;
		Ri(L);Ri(X);
		char c;
		Fi(L)
		{
			cin >> c;
			ss[i] = ss[i+L] = c=='i'?2:c=='j'?3:4;
		}
		dp[0].v = ss[0];
		Fi(L*2)
		{
			dp[i+1] = dp[i].mul(Q(ss[i]));
		}
		Fi(L*2)
		{
			dp[i].print();
			cout << " ";
		}
		cout << endl;

	}

	return 0;
}