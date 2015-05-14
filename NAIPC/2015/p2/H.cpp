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

int n;
int c1[200001];
int c2[200001];

int d1[200001];
int d2[500001];
int t[200001];

int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
		scanf("%d",&c1[i]);
	for(int i=0;i!=n;i++)
		scanf("%d",&c2[i]);
	sort(c1,c1+n);
	sort(c2,c2+n);
	c1[n] = c1[0] + 360000;
	c2[n] = c2[0] + 360000;
	for(int i=0;i!=n;i++)
	{
		d1[i] = c1[i+1]-c1[i];
		d2[i+n] = d2[i] = c2[i+1]-c2[i];
	}
	memset(t,-1,sizeof(t));
	for(int i=1;i<=n;i++)
	{
		int p = t[i-1];
		while(p != -1 && d1[p] != d1[i-1]) p = t[p];
		t[i] = p+1;
	}
	int p1=0,p2=0;
	while(p2 < 2*n)
	{
		while(p1 != -1 && (p1 == n || d1[p1] != d2[p2])) p1 = t[p1];
		p1++;
		p2++;
		if(p1 == n)
		{
			printf("possible\n");
			return 0;
		}
	}
	printf("impossible\n");
	return 0;
}