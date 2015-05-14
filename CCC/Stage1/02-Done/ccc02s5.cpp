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

double slope;
double w,h;
double sx,sy;
int ans;

int main()
{
	cin >> w >> h;
	cin >> sx >> sy;

	slope = sy/(w-sx);

	for(int k=1;k<=100000;k++)
	{
		double xx = k*w;
		double xy = slope*(xx-sx);
		int ny = (int)((xy+h/2)/h);
		double gy =  ny * h;

		double yy = k*h;
		double yx = yy/slope+sx;
		int nx = (int)((yx+w/2)/2);
		int gx = nx*w;

		if(abs(gy-xy)<5)
		{
			ans = k+ny-2;
			if(xy>gy)ans++;
			break;
		}
		if(abs(gx-yx)<5)
		{
			ans = k+nx-2;
			if(yx>gx)ans++;
			break;
		}
	}
	cout<< ans << endl;
	return 0;
}