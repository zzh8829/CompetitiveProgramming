#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

int g[102][102],ele[102],n;
bool rep,flag;

bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(g[i][1] != g[1][i])
			return false;
		flag = false;
		for(int j=1;j<=n;j++)
		{
			if(g[i][j]==1 && g[j][i]==1)
				flag = true;
			for(int k=1;k<=n;k++)
				if(g[g[i][j]][k]!=g[i][g[j][k]])
					return false;
		}
		if(!flag)return false;
	}
	return true;
}

int main()
{
	while(cin>>n && n!=0)
	{
		memset(ele,0,sizeof(ele));
		rep = true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cin >> g[i][j];
			if(ele[g[i][1]])
				rep = false;
			ele[g[i][1]]=1;
		}
		cout << ((rep&&check())?"yes":"no") << endl;
	}
	return 0;
}