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

int dp[501][501][26];
char table[501][501];
int vr[501];
int vc[501];
int R,C,V,X,Y;

int main()
{
	cin >> R >> C;
	for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
			cin >> table[i][j];

	for(int k=0;k!=26;k++)
	for(int i=1;i<=R;i++) 
	for(int j=1;j<=C;j++) 
		dp[i][j][k] = (table[i-1][j-1]-'a'==k) + dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
	
	int rmin=600,rmax=0,cmin=600,cmax=0;
	int rminc=600;
	cin >> V;
	for(int i=0;i!=V;i++)
	{
		cin >> vc[i] >> vr[i];
		if(vr[i] == rmin)
			if(vc[i] < rminc)
				rminc = vc[i];
		if(vr[i] < rmin)
			rminc = vc[i];
		rmin = min(rmin,vr[i]);
		rmax = max(rmax,vr[i]);
		cmin = min(cmin,vc[i]);
		cmax = max(cmax,vc[i]);
	}
	int tot = 0;
	int sign = 1;
	for(int i=0;i!=V;i++)
	{
		tot += sign * (vr[i]*vc[i]);
		sign = -sign;
	}
	int cnt = 0;
	for(int i=0;i<=R-rmax+rmin;i++)
	for(int j=0;j<=C-cmax+cmin;j++)
	{
		int k = table[i+rmin][j+rminc]-'a';
		int area = 0;
		for(int v=0;v!=V;v++)
		{
			area += sign * dp[i+vr[v]][j+vc[v]][k];
			sign = -sign;
		}
		if(abs(area) == abs(tot))
			cnt ++;
	}
	cout << cnt << endl;
	return 0;
}