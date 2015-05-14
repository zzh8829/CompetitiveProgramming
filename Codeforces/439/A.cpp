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

int n,d;
int t;

int main()
{
	cin >> n >> d;
	d += 10;
	for(int i=0;i!=n;i++)
	{
		int a;
		cin >> a;
		t += a;
		t += 10;
	}
	if(t > d) {
		cout << -1 << endl;
	} else {
		cout << ((d-t)/5 + (n-1)*2) << endl;
	}
	 
	return 0;
}