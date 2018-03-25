#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

vector<float> vf;
vector<int> per;
int n;

int p[101];
int a[101];

int main()
{
	cin >> n;
	int minp = 2e9;
	for(int i=0;i!=n;i++)
	{
		int t;
		cin >> t;
		p[t] = 1;
	}
	for(int i=1;i<=100;i++)
	{
		memset(a,0,sizeof(a));
		int j=0;
		int per = 0;
		while(per<=100)
		{
			a[per] = 1;
			j+=100;
			per = (int)((j/(float)i)+0.5);
		}
		bool flag = true;
		for(j=0;j<=100;j++)
		{
			if(p[j]) if(!a[j])
			{
				flag = false;
				break;
			}		
		}
		if(flag)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}