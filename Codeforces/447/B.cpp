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

string s;
int k;
int v[200];

int main()
{
	cin >> s >> k;
	int maxn = 0;
	for(int i='a';i<='z';i++)
	{
		cin >> v[i];
		maxn = max(v[i],maxn);
	}	
	int maxt = 0;	
	for(int i=0;i<=s.size();i++)
	{
		int tot = 0;
		for(int j=0;j!=i;j++)
		{
			tot += (j+1) * v[s[j]];
		} 
		for(int j=i;j!=i+k;j++)
		{
			tot += (j+1) * maxn;
		}
		for(int j=i+k;j!=s.size()+k;j++)
		{
			tot += (j+1) * v[s[j-k]];
		}
		maxt = max(tot,maxt);
	}	
	cout << maxt << endl;
	return 0;
}