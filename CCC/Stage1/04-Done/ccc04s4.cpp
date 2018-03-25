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

double sx,sy,sz;
double px,py,pz;
double x,y,z;

int main()
{
	cin >> sx >> sy >> sz;
	cin >> px >> py >> pz;
	x = px-sx;
	y = py-sy;
	z = pz-sz;
	
	double mind = x*x+y*y+z*z;
	double dis;
	char cmd;
	while(cin>> dis >> cmd)
	{
		double tx = x-dis;
		if(tx*x < 0)
			mind = min(mind,y*y+z*z);
		else
			mind = min(mind,tx*tx+y*y+z*z);

		if(cmd=='E')
			break;
		x = tx;
		double tmp = x;

		if (cmd == 'L')
		{
			x = y;
			y = -tmp;
		}
		else if (cmd == 'R')
		{
			x = -y;
			y = tmp;
		}
		else if (cmd == 'U')
		{
			x = z;
			z = -tmp;
		}
		else
		{
			x = -z;
			z = tmp;
	 	}

	}	
	printf("%.2f",sqrt(mind));
	return 0;
}