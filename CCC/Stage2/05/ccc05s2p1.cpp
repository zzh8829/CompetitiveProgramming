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

using namespace std;

int m[101][101];
int v[101][101];
int C,R;
int a,b,c;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void rec(int ro,int co)
{
	if(v[ro][co]) return;
	v[ro][co] = 1;
	if(ro==R-1)
	{
		cout << a << " " << b << " " << c  << endl;
		exit(0);
	}
	for(int d=0;d!=4;d++)
	{
		int tr = ro+dr[d];
		int tc = co+dc[d];
		if(tr>=0 && tc>=0 && tr<R && tc<C && (m[tr][tc]==a || m[tr][tc]==b || m[tr][tc]==c))
			rec(tr,tc);
	}
}

int main()
{
	cin >> C >> R;
	for(int i=0;i!=R;i++)
	for(int j=0;j!=C;j++)
		cin >> m[i][j];
	for(a=0;a!=10;a++)
	for(b=0;b!=10;b++)
	for(c=0;c!=10;c++)
	for(int i=0;i!=C;i++)
	if(m[0][i]==a || m[0][i]==b || m[0][i]==c)
	{
		memset(v,0,sizeof(v));
		rec(0,i);
	}
	cout << "-1 -1 -1" << endl;
	return 0;
}