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

typedef long long LL;
typedef pair<int,int> I2;

int N,W,H;

struct NJ
{
	int x,y,d;
	bool dead;
}njs[100001];

LL ans;

set<int> sx;
map<int,int> xtoi;
LL itox[200001];
int mx,my;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int grid[4000][4000];
int cur[4000][4000];

void display(int grid[4000][4000])
{
	for(int i=0;i!=my;i++)
	{
		for(int j=0;j!=mx;j++)
		{
			cout << grid[i][j] << " "; 
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&W,&H,&N);
	sx.insert(W-1);
	sx.insert(H-1);
	sx.insert(0);
	for(int i=0;i!=N;i++)
	{
		scanf("%d%d%d",&njs[i].x,&njs[i].y,&njs[i].d);
		njs[i].x--;
		njs[i].y--;
		sx.insert(njs[i].x);
		sx.insert(njs[i].y);
	}
	int x = 0;
	for(set<int>::iterator it = sx.begin();it!=sx.end();it++)
	{
		xtoi[*it] = x;
		itox[x++] = *it;
	}
	mx = xtoi[W-1]+1;
	my = xtoi[H-1]+1;
	for(int i=0;i!=N;i++)
	{
		njs[i].x = xtoi[njs[i].x];
		njs[i].y = xtoi[njs[i].y];
	}
	if(N > 1000) 
	{
		cout << "GAVE UP" << endl;
		return 0;
	}
	for(int i=0;i!=N;i++)
		grid[njs[i].y][njs[i].x] = 1;
	for(int t=0;t!=4;t++)
	{
		map<I2,vector<int> > next;
		for(int i=0;i!=N;i++)
		{
			if(!njs[i].dead)
				cur[njs[i].y][njs[i].x] = i+1;
		}
		//display(cur);

		for(int i=0;i!=N;i++)
		{
			if(njs[i].dead) continue;
			int nx = njs[i].x + dx[njs[i].d];
			int ny = njs[i].y + dy[njs[i].d];
			if(nx < 0 || ny < 0 || nx > mx || ny > my)
			{
				njs[i].dead = true;
				continue;
			}
			if(cur[ny][nx]>0)
			{
				if((njs[cur[nx][ny]-1].d + njs[i].d)%2==0)
				{
					njs[i].dead = true;
					njs[cur[nx][ny]-1].dead = true;
					continue;
				}
			}
			grid[ny][nx]=true;
			I2 p(nx,ny);
			if(!next.count(p))
				next[p] = vector<int>();
			next[p].push_back(i);
		}

		for(map<I2,vector<int> >::iterator it=next.begin();it!=next.end();it++)
		{
			for(int i=0;i!=it->second.size();i++)
			{
				if(it->second.size() > 1) 
					njs[it->second[i]].dead = true;
				njs[it->second[0]].x = it->first.first;
				njs[it->second[0]].y = it->first.second;
			}
		}
	}
	LL tot = 0;
	for(int i=0;i!=my;i++)
	{
		for(int j=0;j!=mx;j++)
		{
			cout << grid[i][j] << " "; 
			if(grid[i][j])
			{
				tot += (itox[i+1] - itox[i]) * (itox[j+1]-itox[j]);
			}
		}
		cout << endl;
	}
	cout << tot << endl;
	return 0;
}