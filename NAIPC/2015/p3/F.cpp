#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef pair<int,int> I2;

char m[1002][1002];
int mf[1002][1002];
int mr[1002][1002];

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int main()
{
	int cc;
	scanf("%d",&cc);
	for(int c=0;c!=cc;c++)
	{
		int R,C;
		scanf("%d %d\n",&C,&R);
		queue<I2> qf;
		queue<I2> qr;
		memset(mf,-1,sizeof(mf));
		memset(mr,-1,sizeof(mr));
		int step = -1;
		for(int i=0;i!=R;i++)
		{
			scanf("%s",m[i]);
			for(int j=0;j!=C;j++)
			{
				if(m[i][j] == '*')
				{
					qf.push(I2(i,j));
					mf[i][j] = 0;
				}
				if(m[i][j] == '@')
				{
					qr.push(I2(i,j));
					mr[i][j] = 0;
					if(i == 0 || j == 0 || i == R-1 || j == C-1)
						step = 1;
				}
			}
		}
		if(step!=-1)
		{
			cout << step << endl;
			continue;
		}
		while(!qf.empty())
		{
			I2 p = qf.front();qf.pop();
			int s = mf[p.first][p.second];
			for(int d=0;d!=4;d++)
			{
				int tr = p.first + dr[d];
				int tc = p.second + dc[d];
				if(tr >= 0 && tc >=0 && tr < R && tc < C &&
					m[tr][tc]!='#' && mf[tr][tc]==-1)
				{
					mf[tr][tc] = s+1;
					qf.push(I2(tr,tc));
				}
			}
		}
		while(!qf.empty())
		{
			I2 p = qf.front();qf.pop();
			int s = mf[p.first][p.second];
			for(int d=0;d!=4;d++)
			{
				int tr = p.first + dr[d];
				int tc = p.second + dc[d];
				if(tr >= 0 && tc >=0 && tr < R && tc < C &&
					m[tr][tc]!='#' && mf[tr][tc]==-1)
				{
					mf[tr][tc] = s+1;
					qf.push(I2(tr,tc));
				}
			}
		}
		while(!qr.empty() && step == -1)
		{
			I2 p = qr.front();qr.pop();
			int s = mr[p.first][p.second];
			for(int d=0;d!=4;d++)
			{
				int tr = p.first + dr[d];
				int tc = p.second + dc[d];
				if(tr >= 0 && tc >=0 && tr < R && tc < C &&
					m[tr][tc]!='#' && mr[tr][tc] == -1 &&
					(mf[tr][tc]==-1 || mf[tr][tc] > s+1))
				{
					if(tr == 0 || tc == 0 || tr == R-1 || tc == C-1)
					{
						step = s+2;
						break;
					}
					mr[tr][tc] = s+1;
					qr.push(I2(tr,tc));
				}
			}
		}
		if(step==-1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << step << endl;
	}
	return 0;
}