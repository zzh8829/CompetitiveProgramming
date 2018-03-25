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

double c[101];
int n;

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> c[i];
	double oldele = 1e100;
	double ele = 1e99;
	while(abs(oldele-ele)>0.00001)
	{
		oldele = ele;
		for(int i=0;i!=n;i++)
		{
			double f = floor(c[i]*1.01/ele);
			if(f*ele<c[i]*0.99) ele = c[i]*1.01/(f+1);
		}
	}
	printf("%.4f\n",ele);	
	return 0;
}