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

typedef long long LL;
int n,s,t;

vector<int> vi;
multiset<int> mss;
multiset<int> ms;

LL tt[20005];

LL gett(int k)
{
	LL tt = 0;
	while(!ms.empty())
	{
		multiset<int>::iterator it = ms.lower_bound(k);
		if(it==ms.end())
		{
			tt += s-k;
			k = 0;
			continue;
		}
		tt += *it - k + t;
		k = (*it + t)%s;
		ms.erase(it);
	}
	return tt;
}


LL gcd(LL m, LL n)
{
   LL  r;

   while (n != 0) {
      r = m % n;
      m = n;
      n = r;
   }
   return m;
}


int main()
{
	scanf("%d %d %d\n",&n,&s,&t);
	for(int i=0;i!=n;i++)
	{
		int a;
		scanf("%d",&a);
		vi.push_back(a);
		mss.insert(a);
	}
	sort(vi.begin(),vi.end());
	for(int i=0;i!=n;i++)
	{
		ms = mss;
		tt[i] = gett(vi[i]);
	}
	int k = 0;
	LL maxi = 0;
	LL mini= LLONG_MAX;
	LL tot = 0;
	for(int i=0;i!=n;i++)
	{
		mini = min(mini,tt[i]);
		maxi = max(maxi,tt[i] + (vi[i]-k));
		tot += 1LL * (tt[i] + (vi[i]-k) + tt[i]) * (vi[i]-k+1)/2;
		k = vi[i]+1;
	}
	maxi = max(maxi,tt[0] + (s-k) + vi[0]);
	tot += 1LL * ((tt[0]+vi[0]) + (s-k) + (tt[0]+vi[0])+1) * (s-k)/2;
	cout << mini << endl << maxi << endl;
	LL g = gcd(tot,s);
	cout << tot/g << "/" << s/g << endl;
	return 0;
}