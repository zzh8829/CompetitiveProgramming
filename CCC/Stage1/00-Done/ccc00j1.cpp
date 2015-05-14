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
	int d,n;
	cin >> d >> n;
	cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
	for(int i=1;i<=n;i++)
	{
		if((i+d-1)%7==1) cout << endl;
		cout << i << " ";
	}
	return 0;
}