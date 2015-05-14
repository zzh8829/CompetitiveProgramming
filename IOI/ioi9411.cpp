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

int grid[200][100];

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=0;j!=i;j++)
			cin >> grid[n+1-i][j];
	for(int i=1;i<=n;i++)
		for(int j=0;j!=n+1-i;j++)
			grid[i][j] += max(grid[i-1][j],grid[i-1][j+1]); 
	cout << grid[n][0];
	return 0;
}