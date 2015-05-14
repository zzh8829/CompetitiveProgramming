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

int dp[10005];

int main()
{
	int n,m;
	cin >> m >> n;

	double tot=1;
	int last = 1;
	for(int i=2;i<=m;i++)
	{
		for(int i=1;i!=n;i++)
		{

		}
		dp[i+1] += dp[i];
	}
	
	return 0;
}