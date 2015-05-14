#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

int R,C;
int wn;
int rw,cw;
bool v[501][501];
bool w[501][501];
int h[501][501];
int cnt;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

typedef pair<int,int> I2;

void go(int r,int c,int d)
{
	queue<I2> q;
	q.push(I2(r,c));
	v[r][c] = 1;
	while(!q.empty())
	{
		I2 i2 = q.front();q.pop();
		int rr = i2.first;
		int cc = i2.second;
		if(w[rr][cc])cnt++;
		for(int i=0;i!=4;i++)
		{
			int tr = dr[i]+rr;
			int tc = dc[i]+cc;
			if(tr>=0&&tc>=0&&tr<R&&tc<C&&!v[tr][tc]&&abs(h[rr][cc]-h[tr][tc])<=d)
			{
				q.push(I2(tr,tc));
				v[tr][tc]=1;
			}
		}
	}
}

int main()
{
#ifndef LOCAL1
	freopen("ccski.in","r",stdin);
	freopen("ccski.out","w",stdout);
#endif
	cin >> R >> C;
	for(int i=0;i!=R;i++)
		for(int j=0;j!=C;j++)
			cin >> h[i][j];
	for(int i=0;i!=R;i++)
	for(int j=0;j!=C;j++)
	{
		cin >> w[i][j];
		if(w[i][j])
		{
			wn++;
			rw = i;
			cw = j;
		}
	}
	int lo = 0;
	int hi = 1000000000;
	while(hi>=lo)
	{
		int mi = (lo+hi)/2;
		cnt = 0;
		memset(v,0,sizeof(v));
		go(rw,cw,mi);
		//cout << mi << " " << cnt << endl;
		if(cnt >= wn)
		{
			hi = mi-1;
		} else {
			lo = mi+1;
		}
	}
	cout << lo << endl;
	return 0;
}