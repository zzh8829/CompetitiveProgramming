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

int r,c;

typedef pair<int,int> I2;
typedef pair<I2, int> Node;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

map<I2,I2> tp;

int str,stc;
int fnr,fnc;

bool v[1005][1005];

int main()
{
	freopen("DATA32.txt","r",stdin);
	//freopen("DATA32.out","w",stdout);
	for(int cs=0;cs!=10;cs++)
	{
		tp.clear();
		cin >> r >> c;
		cin >> str >> stc >> fnr >> fnc;
		int n;
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			I2 a,b;
			cin >> a.first >> a.second >> b.first >> b.second;
			tp[a] = b;
			tp[b] = a;
		} // 0 5 6 7 8 8 7 10 5 10
		queue<Node> q;
		
		q.push(Node(I2(str,stc),0));

		if(str == fnr && stc == fnc) 
		{
			cout << 0 << endl;
			continue;
		}

		if(tp.count(I2(str,stc)))
		{
			I2 nd = tp[I2(str,stc)];
			q.push(Node(nd,0));
			if(nd.first == fnr && nd.second == fnc)
			{
				cout << 0 << endl;
				continue;
			}
		}

		memset(v,0,sizeof(v));
		v[str][stc] = true;
		bool over = false;
		int best = 0;
		while(!q.empty() && !over)
		{
			Node cur = q.front();q.pop();
			int cr = cur.first.first;
			int cc = cur.first.second;
			int step = cur.second;
			//cout << cr << " " << cc << " " << step << endl;
			for(int d=0;d!=4;d++)
			{
				int tr = cr + dr[d];
				int tc = cc + dc[d];
				if(tr < 0 || tc < 0 || tr >= r || tc >= c) continue;
				if(tr == fnr && tc == fnc) 
				{
					over = true;
					best = step+1;
					break;
				}
				if(!v[tr][tc])
				{
					q.push(Node(I2(tr,tc),step+1));
					v[tr][tc] = true;
				}
				if(tp.count(I2(tr,tc)))
				{
					I2 end = tp[I2(tr,tc)];
					if(end.first == fnr && end.second == fnc)
					{
						over = true;
						best = step+1;
						break;
					}
					if(!v[end.first][end.second])
					{
						q.push(Node(I2(end.first,end.second),step+1));
						v[end.first][end.second] = true;
					}
				}
			}
		}
		cout << best << endl;
	}	
	return 0;
}