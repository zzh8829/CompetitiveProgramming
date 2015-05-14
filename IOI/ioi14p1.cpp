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

#ifdef EVAL
#include "square.h"
#endif

int findMaxSquare(int material[1000][1000], int materialSize)
{
	static int dp[1000][1000];
	memset(dp,0,sizeof(dp));
	int maxn=0;
	int cntn=0;
	for(int i=0;i!=materialSize;i++)
	{
		for(int j=0;j!=materialSize;j++) 
		{
			if(i && j && material[i][j])
				dp[i][j]= min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
			else
				dp[i][j] = material[i][j];
			if(dp[i][j] > maxn) 
			{
				maxn = dp[i][j];
				cntn = 0;
			}
			if(dp[i][j] == maxn) {
				cntn ++;
			}
		}
	}
	return maxn*cntn;
}

#ifndef EVAL

int m[1000][1000];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
		for(int j=0;j!=n;j++)
			cin >> m[i][j];
	cout << findMaxSquare(m,n) << endl;
	return 0;
}

#endif