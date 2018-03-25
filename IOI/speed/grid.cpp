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

int R,C,L;
char m[201][201];
long long dp[201][201][8][101];
string word;

int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int main()
{
	cin >> R >> C >> L;
	for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
			cin >> m[i][j];
	cin >> word;
	for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
			if(m[i][j]==word[0])
				dp[i][j][0][0]=1;
	for(int l=1;l!=L;l++)
	for(int i=0;i!=R;i++)
	for(int j=0;j!=C;j++) if(m[i][j] == word[l])
	for(int d=0;d!=8;d++)
	{
		int nr = i + dr[d];
		int nc = j + dc[d];
		if(nr >= 0 && nc >=0 && nr < R && nc < C &&
			m[nr][nc] == word[l-1])
			for(int d2=0;d2!=8;d2++)
				dp[i][j][d][l] += dp[nr][nc][d2][l-1];
	}
	long long ans = 0;
	for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
			for(int d=0;d!=8;d++)
				ans+= dp[i][j][d][L-1];
	cout << ans << endl;
	return 0;
}