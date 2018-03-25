#include <iostream>
using namespace std;

int L,T;
int X,Y;
char E;

int tree[3101][4101];
int v[1001][2001];

void update(int x,int y, int val) {
	for(int xx=x;xx<=3000;xx+=(xx&-xx))
	for(int yy=y;yy<=4000;yy+=(yy&-yy))
		tree[xx][yy] += val;
}

int query(int x,int y) {
	int sum = 0;
	for(int xx=x;xx>0;xx-=(xx&-xx))
	for(int yy=y;yy>0;yy-=(yy&-yy))
		sum += tree[xx][yy];
	return sum;
}

int main()
{
	cin >> L >> T;
	for(int t=0;t!=T;t++)
	{
		cin >> E >> Y >> X;
		if(Y > 2000) {
			continue;
		}
		if(E == 'E')
		{
			v[X][Y] = 1;
			update(X+Y,Y-X+2000,1);
		} else if(E == 'L')	{
			v[X][Y] = 0;
			update(X+Y,Y-X+2000,-1);
		} else if(E == 'S') {
			if(v[X][Y] || v[X+1][Y]) {
				cout << "No" << endl;
				continue;
			}
			cout << query(X+Y,Y-X+2000) + query(X+1+Y,Y-X+1999) << endl;
		}
	}
	int minv = 2e9;
	int minv2 = 2e9;
	for(int x=1;x<=1000;x++)
	for(int y=L+1;y<=2000;y++)
	if(!v[x][y])
	{
		int v = query(x+y, y-x+2000);
		if(v < minv) {
			minv2 = minv;
			minv = v;
		} else if(v < minv2) {
			minv2 = v;
		}
	}
	cout << minv+minv2 << endl;
	return 0;
}