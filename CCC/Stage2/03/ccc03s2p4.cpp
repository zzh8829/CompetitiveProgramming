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

int n,k,cnt;
int p[10];
int r[10][10];
bool check()
{
	for(int i=0;i!=n-1;i++)
	{
		for(int j=i+1;j!=n;j++)
		{
			if(r[p[i]][p[j]])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cin >> n >> k;	
	for(int i=0;i!=n;i++)
		p[i]=i+1;
	for(int i=0;i!=k;i++)
	{
		int a,b;
		cin >> a >> b;
		r[b][a] = 1;
	}
	do
	{
		if(check())cnt++;
	} while(next_permutation(p,p+n));
	cout << cnt << endl;
	return 0;
}