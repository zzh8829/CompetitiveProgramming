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

int n,k;

char m[101][101];


int main()
{
	rint(n);rint(k);

	int sn=0;

	rep(i, 0, n)
	rep(j, 0, n)
	{
		if(((i%2==0 && j%2==1)||(i%2==1 && j%2==0)) && sn<k)
		{
			m[i][j] = 'L';
			sn++;
		}
		else
			m[i][j] = 'S';
	}
	if(sn == k)
	{
		cout << "YES" << endl;
		rep(i, 0, n)
		{
			rep(j, 0, n)
				cout << m[i][j];
			cout << endl;
		}
		return 0;
	}

	sn=0;

	rep(i, 0, n)
	rep(j, 0, n)
	{
		if((!((i%2==0 && j%2==1)||(i%2==1 && j%2==0))) && sn<k)
		{
			m[i][j] = 'L';
			sn++;
		}
		else
			m[i][j] = 'S';
	}
	if(sn == k)
	{
		cout << "YES" << endl;
		rep(i, 0, n)
		{
			rep(j, 0, n)
				cout << m[i][j];
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}


	return 0;
}
