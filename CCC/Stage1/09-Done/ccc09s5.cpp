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

int maxR,maxC,k;
int cnt,maxb;
int row,col,rad,b;

int g[1002][30002];

int main()
{
	scanf("%d%d%d",&maxC,&maxR,&k);
	for(int i=0;i!=k;i++)
	{
		scanf("%d%d%d%d",&row,&col,&rad,&b);
		for(int r = max(1,row-rad);r<=min(maxR,row+rad);r++)
		{
			int len = sqrt(rad*rad-(r-row)*(r-row));
			g[r][max(1,col-len)] += b;
			g[r][min(maxC,col+len)+1] -= b; 
		}
	}
	for(int i=1;i<=maxR;i++)
	for(int j=1;j<=maxC;j++)
	{
		g[i][j] += g[i][j-1];
		if(g[i][j] > maxb)
		{
			maxb = g[i][j];
			cnt = 1;
		} else if(g[i][j] == maxb) {
			cnt ++;
		}
	}	
	printf("%d\n%d\n",maxb,cnt);
	return 0;
}