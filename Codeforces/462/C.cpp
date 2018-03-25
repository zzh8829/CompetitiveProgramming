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

typedef long long LL;

LL tot;
LL cur;
int n;
LL num[300001]; 

/*
1 3 5 6
1 | 3 5 6
 	3 | 5 6
 		5 | 6
*/
int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> num[i];
		cur += num[i];
	}
	sort(num,num+n);
	tot += cur;
	for(int i=0;i!=n-1;i++)
	{
		tot += cur;
		cur -= num[i];
	}
	cout << tot << endl;
	return 0;
}