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

char m[501][501];
int t[501][501],r[501][501],d[501][501];
int bt[501][501],br[501][501],bd[501][501];
int T,R,C,best;

int main()
{
	//freopen("3.txt","r",stdin);
	//freopen("3.out","w",stdout);
	cin >> T;
	for(int cs=1;cs<=T;cs++)
	{
		cin >> R >> C;
		for(int i=0;i!=R;i++)
			for(int j=0;j!=C;j++)
				cin >> m[i][j];
		for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
		{
			t[i][j] = bt[i][j] = -1;
			r[i][j] = d[i][j] = br[i][j] = bd[i][j] = 0;
		}
		best = 0;
		t[0][0] = bt[R-1][C-1] = 0;
		for(int cr=R-1;cr>=0;cr--)
		for(int cc=C-1;cc>=0;cc--) 
		if(m[cr][cc]=='.')
		{
			if(cr!=R-1) bt[cr][cc] = max(bt[cr][cc],bt[cr+1][cc]);
			if(cc!=C-1) bt[cr][cc] = max(bt[cr][cc],bt[cr][cc+1]);
			if(bt[cr][cc]>=0) bt[cr][cc]++;
		}
		for(int cr=0;cr!=R;cr++)
		for(int cc=0;cc!=C;cc++) 
		if(m[cr][cc]=='.')
		{
			if(cr!=R-1) bd[cr][cc] = bt[cr+1][cc];
			if(cc!=C-1) br[cr][cc] = bt[cr][cc+1];
		}
		for(int cr=0;cr!=R;cr++)
		for(int cc=0;cc!=C;cc++) 
		if(m[cr][cc]=='.')
		{
			if(cr) t[cr][cc] = max(t[cr][cc],t[cr-1][cc]);
			if(cc) t[cr][cc] = max(t[cr][cc],t[cr][cc-1]);
			if(t[cr][cc]>=0) t[cr][cc]++;
		}
		for(int cr=R-1;cr>=0;cr--)
		for(int cc=C-1;cc>=0;cc--) 
		if(m[cr][cc]=='.')
		{
			if(cr)d[cr][cc] = t[cr-1][cc];
			if(cc)r[cr][cc] = t[cr][cc-1];
		}
		for(int cr=0;cr!=R;cr++)
		for(int cc=0;cc!=C;cc++)
		if(m[cr][cc]=='.')
		{
			int up = d[cr][cc];
			int left = r[cr][cc];
			for(int i=0;cc-i>=0;i++)
			{
				if(m[cr][cc-i]=='#')break;
				best = max(best,up+i+bd[cr][cc-i]+1);
			}
			for(int i=0;cr-i>=0;i++)
			{
				if(m[cr-i][cc]=='#')break;
				best = max(best,left+i+br[cr-i][cc]+1);
			}
		}		
		cout << "Case #" << cs << ": " << best << endl;
	}
	return 0;
}