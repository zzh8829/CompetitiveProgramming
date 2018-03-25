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

typedef map<int,int> F;

char primes[1000001];
vector<char> indices[1000001];
vector<int> vp;

long long fs[101][100000];

int N;
int seq[101];

int main()
{
	memset(primes,1,sizeof(primes));
	primes[0]=primes[1]=0;
	cin >> N;
	for(int i=0;i!=N;i++)
	{
		cin >> seq[i];
		indices[seq[i]].push_back(i);
	}
	int maxf=0;
	int numf;
	for(int i=2;i<=1000000;i++)
	{
		if(primes[i])
		{
			vp.push_back(i);
			if(indices[i].size())
			{
				for(int j=0;j!=indices[i].size();j++)
					fs[indices[i][j]][vp.size()-1]=1;
				fs[N][vp.size()-1] += indices[i].size();
			}
			int k=2;
			for(int j=i+i;j<=1000000;j+=i,k++)
			{
				if(indices[j].size() > 0)
				{
					int x = 0;
					int xx = j;
					while(xx%i==0)
					{
						xx/=i;
						x++;
					}
					for(int l=0;l!=indices[j].size();l++)
					{
						fs[indices[j][l]][vp.size()-1]=x;
					}
					fs[N][vp.size()-1] += x * indices[j].size();
				}
				primes[j]=false;
			}
		}
	}
	long long ans = 1;
	int mov = 0;
	for(int i=0;i!=vp.size();i++)
	{
		if(fs[N][i] >= N)
		{
			int k = fs[N][i]/N;
			for(int j=0;j!=N;j++)
			{
				mov += max(0LL,k-fs[j][i]);
			}
			ans = ans * pow(vp[i],k);
		}
	}
	cout << ans << " " << mov << endl;
	return 0;
}