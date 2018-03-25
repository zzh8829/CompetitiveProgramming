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

int n,m;
int xs[305];

/*
s = x-d+x-d-d+x-d-d-d

x+x1+x2 - d*1 - d*2 + d*3
*/

int dp[305][305][305][2];

int gol(int i,int j,int d);
int gor(int i,int j,int d);

int gol(int i,int j,int d)
{
	if(dp[i][j][d][0]==-1)
	{
		int l=1e9,r=1e9;
		if(i > 0)
			l = gol(i-1,j,d-1)  - (xs[i-1] - xs[i]);
		if(j < n)
			r = gor(i,j+1,d-1)  + (xs[j+1] - xs[i]);
		dp[i][j][d][0] = min(l,r);
		printf("%d %d %d %d %d\n",i,j,d,0,min(l,r));
	}
	return dp[i][j][d][0];
}

int gor(int i,int j,int d)
{
	if(dp[i][j][d][1]==-1)
	{
		int l=1e9,r=1e9;
		if(i > 0)
			l = gol(i-1,j,d-1)  - (xs[i-1] - xs[j]);
		if(j < n)
			r = gor(i,j+1,d-1)  + (xs[j+1] - xs[j]);
		dp[i][j][d][1] = min(l,r);
		printf("%d %d %d %d %d\n",i,j,d,1,min(l,r));
	}
	return dp[i][j][d][1];
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> xs[i];
	sort(xs,xs+n+1);
	int s=0;
	while(xs[s])s++;
	memset(dp,0xff,sizeof(dp));
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j][0][0] = dp[i][j][0][1] = 0;
	int maxn = 0;
	for(int i=1;i<=n;i++)
		maxn = max(maxn,i*m - gol(s,s,i));
	for(int k=0;k<=n;k++)
	{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout << dp[i][j][k][0] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout << dp[i][j][k][1] << " ";
		}
		cout << endl;
	}
	cout << endl;
	}
	cout << maxn << endl;
	return 0;
}

/*

-3 |0| 1 6

1 1
0 1 -3 1-> 3      
1 2 1 1 -> 1      14
1 2

1 5   9
14 10 1

1 5 14 

1 1 2 1 = 5
0 2 1 0 = 5
0 3 0 0 = 14









*/