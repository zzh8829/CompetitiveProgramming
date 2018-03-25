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

int main()
{
	int a = 100;
	int d = 100;

	int n;
	cin >> n;

	for(int i=0;i!=n;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x < y)
			a -= y;
		else if(x > y)
			d -= x;
	}

	cout << a << endl << d << endl;
	
	return 0;
}