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
	int n;
	Ri(n);
	string s;
	cin >> s;
	for(int i=0;i!=n;i++)
	{
		for(int j=1;j!=n;j++)
		{
			int c = 0;
			for(int k=i;k<n;k+=j)
			{
				if(s[k]=='*')
				{
					c++;
					if(c==5)
					{
						cout << "yes" << endl;
						return 0;
					}
				} else {
					c = 0;
				}
			}
		}
	}
	cout << "no" << endl;
	return 0;
}