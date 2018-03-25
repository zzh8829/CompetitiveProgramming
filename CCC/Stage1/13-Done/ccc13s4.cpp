/* OMG PLEASE LET ME AC*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <stdint.h>
using namespace std;

int n,m;
int x,y;
vector<int> list[1000001];
bool v[1000001];

int main()
{

	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=0;i!=m;i++)
	{
		scanf("%d%d",&a,&b);
		list[a].push_back(b);
	}
	scanf("%d%d",&x,&y);
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		a = q.front();q.pop();
		if(v[a]) continue;
		v[a] = 1;
		for(int i=0;i!=list[a].size();i++)
		{
			if(list[a][i]==y)
			{
				printf("yes\n");
				return 0;
			}
			q.push(list[a][i]);
		}
	}
	q.push(y);
	memset(v,0,sizeof(v));
	while(!q.empty())
	{
		a = q.front();q.pop();
		if(v[a]) continue;
		v[a] = 1;
		for(int i=0;i!=list[a].size();i++)
		{
			if(list[a][i]==x)
			{
				printf("no\n");
				return 0;
			}
			q.push(list[a][i]);
		}
	}
	printf("unknown\n");
	return 0;
}