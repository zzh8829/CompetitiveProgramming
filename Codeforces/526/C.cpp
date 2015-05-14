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

int main()
{
	ios_base::sync_with_stdio(false);
	LL C, Hr, Hb, Wr, Wb;
	cin >> C >> Hr >> Hb >> Wr >> Wb;
	if(Hr/(double)Wr < Hb/(double)Wb)
	{
		swap(Hr,Hb);
		swap(Wr,Wb);
	}
	LL mj = 0;
	if(Wr > sqrt(C))
	{
		for(int r=0;r<=1000000;r++)
		{
			if(C < r * Wr) continue;
			LL b = (C - r * Wr) / Wb;
			mj = max(mj, r * Hr + b * Hb);
		}
	} else {
		for(int b=0;b<=1000000;b++)
		{
			if(C < b * Wb) continue;
			LL r = (C - b * Wb) / Wr;
			mj = max(mj, b * Hb + r * Hr);
		}
	}
	cout << mj << endl;
	return 0;
}