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

typedef pair<int,int> I2;

vector<int> tree[10005];
I2 col[10005];
int cc;

void rec(int n, int c)
{
	col[n].first = ++cc;
	col[n].second = c;
	if(tree[n].size() == 0)
	{
		return;
	}
	for(int i=0;i!=tree[n].size();i++)
	{
		rec(tree[n][i],col[n].first);
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n-1;i++)
	{
		int x,y;
		cin >> x >> y;
		tree[x-1].push_back(y-1);
	}
	rec(0,1);
	col[0].second = col[tree[0][0]].second = ++cc;
	if(n==2)
	{
		col[0].first = col[tree[0][0]].first;
	}
	for(int i=0;i!=n;i++)
	{
		cout << col[i].first << " " << col[i].second << endl;
	}
	return 0;
}