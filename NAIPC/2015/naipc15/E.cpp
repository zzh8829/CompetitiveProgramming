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
typedef pair<int,int> I2;

int pb[1000005];
int ab[1000005];
vector<int> pv;
vector<int> pa[20001];
int a[20001];
int dp[20001][100];

int main()
{
	freopen("E.in","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i!=n;i++)
	{
		scanf("%d",&a[i]);
		ab[i] = 1;
	}
	pb[0] = pb[1] = 1;
	for(int i=2;i<=1000001;i++)
	{
		if(!pb[i])
		{
			if(ab[i]) pa[i].push_back(i);
			for(int k=i+i;k<=1000001;k+=i)
			{
				if(ab[k]) pa[k].push_back(i);
				pb[k]=1;
			}
		}
	}
	for(int i=0;i<=1000000;i++)
	{
		pb[i] = 1-pb[i];
		if(pb[i]) pv.push_back(i);
	}
	for(int i=0;i!=n;i++)
	{
		for(int )
	}
	return 0;
}