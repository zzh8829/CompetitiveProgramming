#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef pair<int,int> I2;

#define x1 first
#define x2 second

struct CX1
{
	bool operator()(I2 a,I2 b) {
		return a.x1 < b.x1;
	}
};

struct CX2
{
	bool operator()(I2 a,I2 b) {
		return a.x2 < b.x2;
	}
};

int N;
I2 xs[100001];
int dp[100001];

int main()
{
	cin >> N;
	for(int i=0;i!=N;i++)
		cin >> xs[i].first >> xs[i].second;
	sort(xs,xs+N,CX1());
	set<I2,CX2> si;
	si.insert(xs[0]);
	for(int i=1;i!=N;i++)
	{
		set<I2>::iterator it = si.lower_bound(xs[i]);
		if(it!=si.begin())
		{
			it--;
			si.erase(it);
		}
		si.insert(xs[i]);
	}
	cout << si.size() << endl;
	return 0;
}