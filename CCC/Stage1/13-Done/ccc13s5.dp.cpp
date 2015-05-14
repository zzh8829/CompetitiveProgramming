#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

const int INF = 2147483647;
const int M = 5000001;
int cost[M+1];
int n;

int main()
{
	cin >> n;
	for(int i=0;i<=n;i++)
		cost[i]=INF;
	cost[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sqrt(n)+1;j>0;j--)
		{
			if(i%j==0)
			{
				int a = j;
				int b = i/j;
				if(i+a<=n)
					if(cost[i]+b<cost[i+a]) cost[i+a]=cost[i]+b;
				if(i+b<=n)
					if(cost[i]+a<cost[i+b]) cost[i+b]=cost[i]+a;
			}
		}
	}
	cout << cost[n] << endl;
	return 0;
}