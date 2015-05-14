#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>

using namespace std;

int dp[101][101];
int n,w,p;

int main()
{
	cin >> n >> w >> p;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
		dp[i][j]=i==j?0:1e9;
	int a,b,c;
	for(int i=0;i!=w;i++)
	{
		cin >> a >> b >> c;
		dp[a][b] = dp[b][a] = c;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(dp[i][k]+dp[k][j] < dp[i][j])
		dp[i][j] = dp[i][k]+dp[k][j];
	for(int i=0;i!=p;i++)
	{
		cin >> a >> b;
		cout << dp[a][b] << endl;
	}
	return 0;
}