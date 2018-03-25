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

int kmp(string s1, string s2)
{
	int T[100005];
	int k=0;
	memset(T,-1,sizeof(T));
	for(size_t i=1;i<=s2.size();i++)
	{
		int pos = T[i-1];
		while(pos != -1 && s2[pos] != s2[i-1]) pos = T[pos];
		T[i] = pos+1;
	}
	int i=0;
	int j=0;
	while(i+ s2.size() <= s1.size())
	{
		if(s1[i + j] == s2[j])
		{
			j++;
			if(j==s2.size())
			{
				return i;
			}
		} else {
			if(j != 0)
			{
				j = T[j];
				i += s2.size() - 1 - T[j];
			}
			else
				i++;
		}
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i!=t;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		cout << ((kmp(s1,s2)==-1)?"NO":"YES") << endl;
	}
	return 0;
}
