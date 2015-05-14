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

int n;
int m[100002];
double ma = 2e9;

int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		m[i-1] = m[i-1] + m[i];
		m[i] = m[i-1];
	}
	for(int i=1;i!=n-1;i++)
	{
		for(int j=i;j!=n-1;j++)
		{
			ma = min(ma,(m[n] - m[j] + m[i-1])/double(n-j+i-1));
		}
	}
	cout << ((int)(ma*1000+0.5))/1000.0 << endl;
	return 0;
}