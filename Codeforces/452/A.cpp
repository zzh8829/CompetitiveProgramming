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

string eevee[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i!=8;i++)
	{
		if(eevee[i].size()!=n) continue;
		bool f=true;
		for(int j=0;j!=n;j++)
		{
			if(s[j]=='.')continue;
			if(eevee[i][j]!=s[j])
			{
				f=  false;
				break;
			}
		}
		if(f)
		{
			cout << eevee[i] << endl;
			return 0;
		}
	}
	return 0;
}