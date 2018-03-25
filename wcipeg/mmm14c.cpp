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
#include <bitset>
using namespace std;

typedef bitset<16> Mask;

const int MOD = 1000000007;

int R,C;

int g[16][16];
int dp[16][1<<16][2];

vector<int> all;

int main()
{
	cin >> R >> C;
	for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
			cin >> g[i][j];

	for(int i=0;i!=(1<<C);i++)
	{
		Mask m=i;
		bool f = 1;
		for(int j=0;j!=C;j++) if(m[j] && j && m[j-1])
		{
			f = 0;
			break;
		}
		if(f) all.push_back(i);
	}
	for(int i=0;i!=R;i++) for(int j:all)
	{
		int tot = 0;
		Mask m=j;
		for(int k=0;k!=C;k++) if(m[k])
			tot += g[i][k];	
		if(i)
		{
			for(int k:all)
			{ 
				Mask mm=k;
				bool f=1;
				for(int l=0;l!=C;l++) if(mm[l] && m[l])
				{
					f=0;
					break;
				}
				if(!f) continue;
				if(dp[i-1][k][0] > dp[i][j][0])
				{
					dp[i][j][0] = dp[i-1][k][0];
					dp[i][j][1] = 0;
				}
				if(dp[i-1][k][0] == dp[i][j][0])
				{
					dp[i][j][1] = (dp[i][j][1] + dp[i-1][k][1])%MOD;
				}
			}
			dp[i][j][0] = (dp[i][j][0] + tot)%MOD;
		} else {
			dp[i][j][0] = tot;
			dp[i][j][1] = 1;
		}
	}
	int maxn = 0;
	int numn = 0;
	for(int j:all)
	{
		if(dp[R-1][j][0] > maxn)
		{
			maxn = dp[R-1][j][0];
			numn = 0;
		}
		if(dp[R-1][j][0] == maxn)
		{
			numn = (numn + dp[R-1][j][1])%MOD;
		}
	}
	cout << maxn << " " << numn << endl;	
	return 0;
}