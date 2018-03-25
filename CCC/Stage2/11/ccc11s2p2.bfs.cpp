#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	Node(int p,int d,int c):pos(p),dis(d),cost(c){};
	int pos,dis,cost;
	bool operator <(const Node& n) const
	{
		if(dis==n.dis)
		{
			if(cost==n.cost)return pos > n.pos;
			else return cost > n.cost;
		} else {
			return dis > n.dis;
		}
	}
};

struct Edge
{
	Edge(int t,int d,int c)
	{
		to = t;dis=d;cost=c;
		if(c)cost = dis;
	}
	int to,dis,cost;
};
vector<Edge> ve[1605];
int maxTime,nPoint,nEdge;
int save[1605][3601];

int main()
{
	scanf("%d%d%d",&maxTime,&nPoint,&nEdge);
	for(int i=0;i!=nEdge;i++)
	{
		int beg,end,dis,cost;
		scanf("%d%d%d%d",&beg,&end,&dis,&cost);
		ve[beg].push_back(Edge(end,dis,cost));
		ve[end].push_back(Edge(beg,dis,cost));
	}
	for(int i=0;i<=nPoint;i++)
		for(int j=0;j<=maxTime;j++)
			save[i][j]=2e9;
	priority_queue<Node> q;
	q.push(Node(0,0,0));
	while(!q.empty())
	{
		Node n = q.top();q.pop();
		if(n.pos == nPoint -1)
		{
			printf("%d\n",n.dis);
			return 0;
		}
		for(int i=0;i!=ve[n.pos].size();i++)
		{
			// (Time > maxTime or Distance > saveDistance) continue
			if(n.cost + ve[n.pos][i].cost > maxTime ||
				save[ve[n.pos][i].to][n.cost + ve[n.pos][i].cost] <= n.dis + ve[n.pos][i].dis)continue;
			save[ve[n.pos][i].to][n.cost + ve[n.pos][i].cost] = n.dis + ve[n.pos][i].dis;
			q.push(Node(ve[n.pos][i].to,n.dis + ve[n.pos][i].dis,n.cost + ve[n.pos][i].cost));
		}
	}
	printf("-1\n");
	return 0;
}