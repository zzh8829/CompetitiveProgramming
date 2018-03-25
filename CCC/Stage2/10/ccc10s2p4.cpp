#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

int dp[6][3001];
int cost[1001];
int val[1001];
int typ[1001];

int main()
{
	int n,m,bgt;
	cin >> n >> m;
	for(int i=0;i!=m;i++)
	{
		cin >> cost[i] >> val[i] >> typ[i];
	}
	cin >> bgt;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=bgt;j++)
			for(int k=0;k!=m;k++)
			{
				if (typ[k] == i)
				{
					if(cost[k] < 10000)
					{
						if(j- cost[k]>=0 && dp[i-1][j-cost[k]]!=-1 && val[k]+dp[i-1][j-cost[k]] > dp[i][j])
						dp[i][j] = val[k]+dp[i-1][j-cost[k]];
					}
				}

			}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=bgt;j++)
			cout << dp[i][j] <<" ";
		cout << endl;
	}*/

	cout << dp[n][bgt] << endl;
	return 0;
}