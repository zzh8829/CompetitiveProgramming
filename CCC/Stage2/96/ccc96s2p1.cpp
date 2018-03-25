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

int train[51];
int cs,n,cnt;

int main()
{
	cin >> cs;
	while(cs--)
	{
		cin >> n;
		for(int i=1;i<=n;i++) cin >> train[i];
		cnt = 0;
		for(int i=1;i<=n;i++) if(train[i]!=i)
		{
			int t = train[i];
			train[i] = i;
			for(int j=i+1;j<=n;j++)
			{
				swap(t,train[j]);
				if(t==i)
				{
					cnt += j-i;
					break;
				}
			}
		}
		printf("Optimal train swapping takes %d swap(s).\n", cnt );
	}
	return 0;
}