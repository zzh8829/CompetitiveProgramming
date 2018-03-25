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

int nxt[300001];
int lst[300001];
int vis[300001];
int N,Q;

int fat[300001];

int father(int x)
{
	if(fat[x] == x) 
		return x;
	return father(fat[x]);
}

int merge(int x, int y)
{
	int fx = father(x);
	int fy = father(y);
	fat[fx] = fy;
}

int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++) 
		scanf("%d", &nxt[i]);
	build();
	for(int i=0;i!=Q;i++)
	{
		int cmd,x;
		scanf("%d%d",&cmd,&x);
		if(cmd == 1) 
		{
			if(lst[x])
				cout << lst[x] << endl;
			else
				cout << "CIKLUS" << endl;
		} else {
			nxt[x]=0;
			build();
		}
	}
	
	return 0;
}