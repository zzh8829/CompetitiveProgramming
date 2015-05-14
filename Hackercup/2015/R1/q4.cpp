#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <sys/resource.h>
using namespace std;

typedef pair<int,int> I2;

int u[200001];
vector<int> d[200001];
I2 s[200001];


void rec(int n)
{
	//cout << n << endl;
	if(d[n].size() == 0)
	{
		s[n] = I2(1,1);
		return;
	}

	int tot = 0;
	set<int> si;
	for(int i=0;i!=d[n].size();i++)
	{
		rec(d[n][i]);
		I2 r = s[d[n][i]];
		tot += r.second;
		si.insert(r.first);
	}
	int c = 1;
	for(set<int>::iterator it = si.begin();it!=si.end();it++)
	{
		//cout << c << " " << *it << endl;
		if(c < *it)
			break;
		c++;
	}
	s[n] = I2(c,tot + c);
}

int main()
{
	int T;
	cin >> T;
	for(int t=0;t!=T;t++)
	{
		int N;
		cin >> N;
		for(int i=0;i!=N;i++)
		{
			cin >> u[i];
			d[i].clear();
		}
		d[N].clear();
		for(int i=0;i!=N;i++)
			d[u[i]].push_back(i+1);
		rec(1);
		cout << "Case #" << t+1 << ": " << s[1].second << endl;
	}

	return 0;
}