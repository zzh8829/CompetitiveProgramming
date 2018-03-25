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

int a[100005];
int lup[100005];
int ldn[100005];
vector<int> vup;
vector<int> vdn;

LL f(LL n)
{
	return n*(n+1)/2;
}

int main()
{
	int N,K;
	rint(N);
	rint(K);
	rep(i,0,N) rint(a[i]);

	for(int i=1;i!=N;i++)
	{
		if(a[i] >= a[i-1])
			lup[i] = lup[i-1] + 1;
		else
		{
			lup[i] = 0;
			vup.push_back(i);
		}
		if(a[i] <= a[i-1])
			ldn[i] = ldn[i-1] + 1;
		else
		{
			ldn[i] = 0;
			vdn.push_back(i);
		}
	}
	vup.push_back(N);
	vdn.push_back(N);

	LL cnt = 0;

	for(int i=0;i<K-1;i++)
	{
		if(lup[i+1] == 0)
			cnt += f(lup[i]);
		if(ldn[i+1] == 0)
			cnt -= f(ldn[i]);
	}
	cnt += f(lup[K-1]);
	cnt -= f(ldn[K-1]);
	cout << cnt << endl;

	vector<int>::iterator it;
	int len;

	for(int i=1;i<N-K+1;i++)
	{
		it = lower_bound(vup.begin(),vup.end(),i);
		if(*it > i+K)
			len = K;
		else
			len = *it-i;

		cnt -= f(len);
		cnt += f(len-1);

		it = lower_bound(vup.begin(),vup.end(),i+K-1);
		it--;
		if(*it < i)
			len = K;
		else
			len = i+K-1-*it;

		if(lup[i+K-1])
		{
			cnt -= f(len-1);
			cnt += f(len);
		}

		it = lower_bound(vdn.begin(),vdn.end(),i);
		if(*it > i+K)
			len = K;
		else
			len = *it-i;

		cnt += f(len);
		cnt -= f(len-1);

		it = lower_bound(vdn.begin(),vdn.end(),i+K-1);
		it--;
		if(*it < i)
			len = K;
		else
			len = i+K-1-*it;

		if(ldn[i+K-1])
		{
			cnt += f(len-1);
			cnt -= f(len);
		}

		cout << cnt << endl;
	}
	return 0;
}
