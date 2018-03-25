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
typedef pair<I2, int> Node;

int grid[1001][1001];
int v[1001][1001];
I2 start,finish;
map<I2,I2> tp;
int best;
int r,c;

I2 get()
{
	I2 a;
	cin >> a.first >> a.second;
	return a;
}

int dr[] = {1,0,0,-1};
int dc[] = {0,1,-1,0};

int main()
{
	freopen("DATA31.txt","r",stdin);
	freopen("DATA31.out","w",stdout);
	for(int cs=0;cs!=3;cs++)
	{
		tp.clear();
		//memset(grid,0x3f,sizeof(grid));
		memset(v,0,sizeof(v));

		cin >> r >> c;
		start = get();
		finish = get();
		int n;
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			I2 a = get();
			I2 b = get();
			tp[a] = b;
		}

		queue<Node> q;
		q.push(Node(start,0));
		int over = false;
		while(!q.empty() && !over)
		{
			int step = q.front().second;
			I2 beg = q.front().first;q.pop();

			for(int d=0;d!=4;d++)
			{
				int tr = beg.first + dr[d];
				int tc = beg.second + dc[d];
				if(tr >=0 && tc >=0 && tr <r && tc < c)
				{
					if(I2(tr,tc)==finish)
					{
						best = step;
						over = true;
						break;
					}
					if(!v[tr][tc])
					{
						q.push(Node(I2(tr,tc),step+1));
						v[tr][tc]=true;
					}
					if(tp.count(I2(tr,tc)))
					{
						I2 nd = tp[I2(tr,tc)];
						if(nd==finish)
						{
							best = step;
							over = true;
							break;
						}
						if(!v[nd.first][nd.second])
						{
							q.push(Node(nd,step+1));
							v[nd.first][nd.second] = true;
						}
					}
				}
			}
		}
		cout << best+1 << endl;
	}
	return 0;
}
