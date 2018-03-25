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

vector<I2> ts;

string m[6];

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int v[6][6][4];

void rec(int rr,int cc,int dir)
{
	if(rr < 0 || rr >5 || cc<0 || cc>5)
		return;
	if(v[rr][cc][dir])return;
	v[rr][cc][dir]=1;
	if(m[rr][cc]=='.' || m[rr][cc]=='T' || m[rr][cc]=='S') return;
	int r=rr,c=cc;
	if(dir==UP)
	{
		for(int r=rr-1;r>0;r--)
		{
			if(m[r][c]=='U')
				rec(rr-1,cc,dir);
			else if(m[r][c]=='D')
				rec(rr+1,cc,dir);
			else if(m[r][c]=='L')
				rec(rr,cc-1,dir);
			else if(m[r][c]=='R')
				rec(rr,cc+1,dir);
			else if(m[r][c]=='C')
				rec(rr,cc,(dir+1)%4);
			else if(m[r][c]=='B')
				rec(rr,cc,(dir+3)%4);
		}
	}
	else if(dir==DOWN)
	{
		for(int r=rr+1;r<6;r++)
		{
			if(m[r][c]=='U')
				rec(rr-1,cc,dir);
			else if(m[r][c]=='D')
				rec(rr+1,cc,dir);
			else if(m[r][c]=='L')
				rec(rr,cc-1,dir);
			else if(m[r][c]=='R')
				rec(rr,cc+1,dir);
			else if(m[r][c]=='C')
				rec(rr,cc,(dir+1)%4);
			else if(m[r][c]=='B')
				rec(rr,cc,(dir+3)%4);
		}
	}
	else if(dir==LEFT)
	{
		for(int c=cc-1;c>0;c--)
		{
			if(m[r][c]=='U')
				rec(rr-1,cc,dir);
			else if(m[r][c]=='D')
				rec(rr+1,cc,dir);
			else if(m[r][c]=='L')
				rec(rr,cc-1,dir);
			else if(m[r][c]=='R')
				rec(rr,cc+1,dir);
			else if(m[r][c]=='C')
				rec(rr,cc,(dir+1)%4);
			else if(m[r][c]=='B')
				rec(rr,cc,(dir+3)%4);
		}
	}
	else if(dir==RIGHT)
	{
		for(int c=cc+1;c<6;c++)
		{
			if(m[r][c]=='U')
				rec(rr-1,cc,dir);
			else if(m[r][c]=='D')
				rec(rr+1,cc,dir);
			else if(m[r][c]=='L')
				rec(rr,cc-1,dir);
			else if(m[r][c]=='R')
				rec(rr,cc+1,dir);
			else if(m[r][c]=='C')
				rec(rr,cc,(dir+1)%4);
			else if(m[r][c]=='B')
				rec(rr,cc,(dir+3)%4);
		}
	}
}

bool cmp(I2 a, I2 b)
{
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main()
{
	freopen("DATA41.txt","r",stdin);
	for(int c=0;c!=10;c++)
	{
		ts.clear();
		memset(v,0,sizeof(v));
		int sr,sc;
		for(int i=0;i!=6;i++)
		{
			getline(cin,m[i]);
			for(int j=0;j!=6;j++)
			{
				if(m[i][j]=='T')
				{
					ts.push_back(I2(i,j));
				}
				if(m[i][j]=='S')
				{
					sr=i;
					sc=j;
				}
			}
		}
		for(int i=sr-1;i>=1;i--)
		{
			if(m[i][sc]=='U')
			{
				rec(sr-1,sc,UP);
				break;
			}
		}
		for(int i=0;i!=ts.size();i++)
		{
			bool ok = false;
			for(int j=0;j!=4;j++)
			{
				if(v[ts[i].first][ts[i].second][j])
				{
					ok = true;
					break;
				}
			}
			if(ok)
			{
				cout << "T";
			} else {
				cout << "F";
			}
		}
		cout << endl;
	}
	return 0;
}