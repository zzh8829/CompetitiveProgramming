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

int N;
int dp[10000011];

int reverse(int i)
{
	int r=0;
	while(i!=0)
	{
		r *=10;
		r +=i%10;
		i/=10;
	}
	return r;
}

int mains()
{
	dp[1]=1;
	queue<int> qi;
	qi.push(1);
	while(!qi.empty())
	{
		int i = qi.front();qi.pop();
		//cout << i << endl;
		if(i > 10000010) continue;

		int r = i+1;

		if(dp[r]==0 || dp[r] > dp[i]+1)
		{
			dp[r] = dp[i]+1;
			qi.push(r);
		}

		r = reverse(i);
		if(r > 10000010) continue;
		if(dp[r]==0 || dp[r] > dp[i]+1)
		{
			dp[r] = dp[i]+1;
			qi.push(r);
		}
	}
	int T;
	rint(T);
	rep(t, 0, T)
	{
		rint(N);
		printf("Case #%d: %d\n",t+1, dp[N]);
	}
	return 0;
}

vector<int> vi[10001100];

int main2()
{
	dp[1]=1;
	queue<int> qi;
	qi.push(1);
	while(!qi.empty())
	{
		int i = qi.front();qi.pop();
		//cout << i << endl;
		if(i > 1000100) continue;

		int r = i+1;

		if(dp[r]==0 || dp[r] > dp[i]+1)
		{
			dp[r] = dp[i]+1;
			vi[r].clear();
			rep(j, 0, vi[i].size())
			{

					vi[r].push_back(vi[i][j]);
			}
			vi[r].push_back(i);
			qi.push(r);
		}

		r = reverse(i);
		if(r > 1000100) continue;
		if(dp[r]==0 || dp[r] > dp[i]+1)
		{
			dp[r] = dp[i]+1;
			vi[r].clear();
			rep(j, 0, vi[i].size())
			{

					vi[r].push_back(vi[i][j]);
			}
			vi[r].push_back(i);
			qi.push(r);
		}
	}
	rep(i, 0, 1000100)
	{
		cout << i << ": ";
		vi[i].push_back(i);
		rep(j, 1, vi[i].size())
		{
			if(vi[i][j]-vi[i][j-1]!=1)
			{
				cout << vi[i][j-1] << "->" << vi[i][j] << " ";
			}
		}
		cout << endl;
	}
	int T;
	rint(T);
	rep(t, 0, T)
	{
		rint(N);
		printf("Case #%d: %d\n",t+1, dp[N]);
	}
	return 0;
}

int length(int i)
{
	int r=0;
	while(i!=0)
	{
		i/=10;
		r++;
	}
	return r;
}

LL lpow(LL a, int b)
{
	LL r=1;
	while(b--)
	{
		r*=a;
	}
	return r;
}

int ending(LL a, int b)
{
	return a%lpow(10,b)==1;
}

int rec(LL n)
{
	int c=0;
	int e=0;
	if(n < 21LL)
	{
		e = 1;
	}
	else if(n < 201LL)
	{
		e = 1;
	}
	else if(n < 1101LL)
	{
		e = 2;
	}
	else if(n < 11001LL)
	{
		e = 2;
	}
	else if(n < 101001LL)
	{
		e = 3;
	}
	else if(n < 1010001LL)
	{
		e = 3;
	}
	else if(n < 10010001LL)
	{
		e = 4;
	}
	else if(n < 100100001LL)
	{
		e = 4;
	}
	else if(n < 1000100001LL)
	{
		e = 5;
	}
	else if(n < 10001000001LL)
	{
		e = 5;
	}
	else if(n < 100001000001LL)
	{
		e = 6;
	}
	else if(n < 1000010000001LL)
	{
		e = 6;
	}
	else if(n < 10000010000001LL)
	{
		e = 7;
	}
	else if(n < 100000100000001LL)
	{
		e = 7;
	}
	else if(n < 1000001000000001LL)
	{
		e = 8;
	}
	else if(n < 10000001000000001LL)
	{
		e = 8;
	}
	else if(n < 100000010000000001LL)
	{
		e = 9;
	}
}

int main()
{

	cout << ending(999999000001,6);

	int T;
	rint(T);
	rep(t, 0, T)
	{
		LL n;
		cin >> n;




		printf("Case #%d: %d\n",t+1, c);
	}

	return 0;
}