#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

vector<int> c[2001];
int m[2001][2001];

int t1,t2;
int cs;

int main()
{
	scanf("%d%d",&t1,&t2);
	scanf("%d",&cs);
	for(int i=0;i!=cs;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		c[a].push_back(b);
	}
	for(int i=1;i<=t1;i++)
	{
		for(int j=0;j!=c[i].size();j++)
		{
			for(int k=0;k!=c[i].size();k++)if(j!=k)
			{
				m[c[i][j]][c[i][k]]++;
				if(m[c[i][j]][c[i][k]] > 1)
				{
					printf("NO\n");
					return 0;
				}
			} 
		}
	}
	printf("YES\n");
	return 0;
}