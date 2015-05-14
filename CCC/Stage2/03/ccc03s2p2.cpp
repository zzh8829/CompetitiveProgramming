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

int n,w,h;
int cs;

int main()
{
	cin >> cs;
	while(cs--)
	{
		cin >> n >> w >> h;
		int best = 1000*1000*1000;
		//      a
		//     wwww
		//    h
		// b  h
		//    h
		for(int a=1;a<=n;a++)if(n%a==0)
		{
			int b = n/a;
			if(2*(a*w + b*h)< best)
				best = 2*(a*w + b*h);
		}
		//      a*w 
		// 
		// b*h
		//
		// d*w
		//      c*h
		//  I have no idea why this works. screw it who cares.
		for(int a=1;a<=n;a++)if(a*w%h==0)
		{
			int c = a*w/h;
			for(int b=1;a*b<n;b++)if((n-a*b)%c==0)
			{
				int d = (n-a*b)/c;
				if(2*((a+d)*w + b*h) < best)
				{
					best = 2*((a+d)*w + b*h);
				}
			}
		}
		cout << best << endl;
	}
	return 0;
}