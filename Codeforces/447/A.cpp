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

set<int> si;

int main()
{
	int p,n;
	cin >> p >> n;
	for(int i=0;i!=n;i++)
	{
		int a;
		cin >> a;
		a%=p;
		if(si.count(a))
		{
			cout << i+1 << endl;
			return 0;
		}
		si.insert(a);
	}	
	cout << -1 << endl;
	
	return 0;
}