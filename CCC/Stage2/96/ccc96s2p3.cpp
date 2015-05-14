#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

bool t[32][32];
int pos;
string str;

void build(int r,int c,int l)
{
	char q = str[pos++];
	if(q=='f')
		for(int i=r;i!=r+l;i++)
		for(int j=c;j!=c+l;j++)
			t[i][j]=1;
	else if(q=='p')
	{
		int nl = l/2;
		build(r,c+nl,nl);
		build(r,c,nl);
		build(r+nl,c,nl);
		build(r+nl,c+nl,nl);
	}
}

int main()
{
	int cs;
	cin >> cs;
	while(cs--)
	{
		memset(t,0,sizeof(t));
		cin >> str;
		pos = 0;
		build(0,0,32);
		cin >> str;
		pos = 0;
		build(0,0,32);
		int tot = 0;
		for(int i=0;i!=32;i++)
		for(int j=0;j!=32;j++)
			tot += t[i][j];
		printf("There are %d black pixels.\n",tot);
	}
	return 0;
}