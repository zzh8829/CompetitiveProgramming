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
#include <cassert>

using namespace std;

#ifdef EVAL
#include"tile.h"
#endif 

int pn;

void rec(int n, int x ,int y, int sx, int sy, int pos[][6], int& pi)
{
	//printf("%d %d %d %d %d %d\n",n,x,y,sx,sy,pi);
	if(n==1) return;
	int nn = n/2;
	int nx = x%nn;
	int ny = y%nn;
	int cpi = pi++;
	int cpii = 0;
	if(x < nn && y < nn)  // BL
	{
		rec(nn, nx, ny, sx, sy, pos, pi);
	} else {
		pos[cpi][cpii++] = sx + nn-1;
		pos[cpi][cpii++] = sy + nn-1;
		rec(nn, nn-1, nn-1, sx, sy, pos, pi);
	}

	if(x >= nn && y < nn) // BR
	{
		rec(nn, nx, ny, sx+nn, sy, pos, pi);
	} else {
		pos[cpi][cpii++] = sx + nn;
		pos[cpi][cpii++] = sy + nn-1;
		rec(nn, 0, nn-1, sx+nn, sy, pos, pi);
	}

	if(x < nn && y >= nn) // TL
	{
		rec(nn, nx, ny, sx, sy+nn, pos, pi);
	} else {
		pos[cpi][cpii++] = sx + nn-1;
		pos[cpi][cpii++] = sy + nn;
		rec(nn, nn-1, 0, sx, sy+nn, pos, pi);
	}

	if(x >= nn && y >= nn) // TR
	{
		rec(nn, nx, ny, sx+nn, sy+nn, pos, pi);
	} else {
		pos[cpi][cpii++] = sx + nn;
		pos[cpi][cpii++] = sy + nn;
		rec(nn, 0, 0, sx+nn, sy+nn, pos, pi);
	}
}

void placeTile(int n, int x, int y, int pos[][6])
{
	n = pow(2,n);
	pn = 0;
	rec(n, x, y ,0, 0, pos ,pn);
}

#ifndef EVAL

int ps[2000000][6];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	placeTile(a,b,c,ps);
	for(int i=0;i!=pn;i++)
	{
		cout << ps[i][0] << " ";
		cout << ps[i][1] << " ";
		cout << ps[i][2] << " ";
		cout << ps[i][3] << " ";
		cout << ps[i][4] << " ";
		cout << ps[i][5] << " ";
		cout << endl;
	}
}

#endif
