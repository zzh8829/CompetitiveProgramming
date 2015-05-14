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

char m[105][105];
int n;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> m[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int oc=0;
			for(int d=0;d!=4;d++)
				oc += m[i+dr[d]][j+dc[d]]=='o';
			if(oc%2!=0)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
	return 0;
}