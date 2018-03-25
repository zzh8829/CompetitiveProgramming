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

int a1[10];
int a2[10];

set<pair<string,string>> mpll;

int main()
{
	int n;
	cin >> n;
	int k1,k2;
	cin >> k1;
	rep(i,0,k1)
	{
		cin >> a1[i];
	}
	cin >> k2;
	rep(i,0,k2)
	{
		cin >> a2[i];
	}
	int b1=0;
	int b2=0;
	int step = 0;
	while(k1 && k2)
	{
		step ++ ;
		if(a1[b1] > a2[b2])
		{
			a1[(b1+k1)%10] = a2[b2];
			a1[(b1+k1+1)%10] = a1[b1];
			k1++;
			k2--;
			b1 = (b1+1)%10;
			b2 = (b2+1)%10;
		} else {
			a2[(b2+k2)%10] = a1[b1];
			a2[(b2+k2+1)%10] = a2[b2];
			k2++;
			k1--;
			b1 = (b1+1)%10;
			b2 = (b2+1)%10;
		}
		string s1="",s2="";
		rep(i,0,k1)
			s1 += (char)a1[(b1+i)%10];
		rep(i,0,k2)
			s2 += (char)a2[(b2+i)%10];
		if(mpll.count(make_pair(s1,s2)))
		{
			cout << -1 << endl;
			return 0;
		}
		mpll.insert(make_pair(s1,s2));
	}
	cout << step << " ";
	if(k1) cout << 1;
	else cout << 2;
	cout << endl;
	return 0;
}
