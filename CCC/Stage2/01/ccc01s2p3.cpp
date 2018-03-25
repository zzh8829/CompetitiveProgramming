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

int dp[101][101];

int recdp(int maxn,int a)
{
	if(dp[maxn][a]) return dp[maxn][a];
	for(int i=1;i<=maxn;i++)
		dp[maxn][a] += recdp(min(i,a-i),a-i);
	return dp[maxn][a];
}

void recans(int maxn,int num)
{
	for(int i=1;i<=maxn;i++)
	if(dp[i][maxn]>=num)
	{
		cout << i;
		if(maxn-i!=0) cout << ",";
		else return;
		recans(maxn-i,num-dp[i-1][maxn]);
		break;
	}
}

int main()
{
	dp[0][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=i;j<=100;j++)
			recdp(i,j);
	int cs;
	cin >> cs;
	while(cs--)
	{
		int k,a;
		cin >> k >> a;
		if(a>dp[k][k])
		{
			cout << "Too big\n"; 
			continue;
		}
		cout << "(";
		recans(k,a);
		cout << ")\n";
	}
	return 0;
}