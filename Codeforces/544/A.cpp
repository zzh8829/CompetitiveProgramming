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

int k;
int c[26];
int v[26];
int cn;

int main()
{
	rint(k);
	string s;
	cin >> s;
	rep(i, 0, s.size())
	{
		c[s[i]-'a'] ++ ;
		if(c[s[i]-'a'] == 1) cn++;
	}
	if(cn >= k)
	{
		cout << "YES" << endl;
		int cnt=0;
		rep(i, 0, s.size())
		{
			if(!v[s[i]-'a'])
			{
				if(cnt) cout << endl;
				if(cnt == k-1)
				{
					cout << s.substr(i) << endl;
					break;
				}
				v[s[i]-'a'] ++;
				cnt ++;
				cout << s[i];
			} else {
					cout << s[i];
			}
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
