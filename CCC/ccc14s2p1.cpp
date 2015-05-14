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

int N;
int m[2001][2001];
int dp[2001][2001];

int main()
{
	cin >> N;
	for(int i=0;i!=N;i++)
		for(int j=0;j!=N;j++)
			cin >> m[i][j];
	for(int i=N-1;i>=0;i--)
	for(int j=0;j!=n;j	++)
	{
		if(m[i][j]=='#')
		{
			dp[i][j] = 1;
			if(m[i-1][j]==1)
		}
	}
	
	return 0;
}