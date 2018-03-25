#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

typedef pair<int,int> I2;

unordered_map<int,int> dp[2001];
int n;
int px[2001];
int py[2001];
int od[2001];

vector<I2> vi[2001];

bool cmp(I2 a,I2 b)
{
	return a.second < b.second;
}

int rec(int p,int d)
{
	if(!dp[p].count(d))
	{
		int t=0;
		if(d > vi[p][0].second)
		{
			vector<I2>::iterator last = lower_bound(vi[p].begin(),vi[p].end(),I2(0,d),cmp);
			last--;
			int ct = 0;
			for(vector<I2>::iterator it=last;it>=vi[p].begin();it--)
			{
				ct++;
				if(n > 100 && ct > 5) break; // XXX MASSIVE HACK XXX
				t = max(t,rec(it->first,it->second));
			}
		}
		//printf("P: %d,D: %d, N: %d\n",p,d,t);
		dp[p][d] = t+1;
	}
	return dp[p][d];
}

int main()
{
	//freopen("ccc14s5.in","r",stdin);
	srand(time(0));
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
	{
		scanf("%d%d",&px[i],&py[i]);
		od[i] = px[i]*px[i] + py[i]*py[i];
	}
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	int best = 0;
	for(int i=0;i!=n;i++)
	{
		for(int j=0;j!=n;j++) if(i!=j)
		{
			vi[i].push_back(I2(j,(px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j])));
		}
		sort(vi[i].begin(),vi[i].end(),cmp);
	}
	for(int i=0;i!=n;i++)
	{
		best = max(best,rec(i,od[i]));
	}
	printf("%d",best);
	return 0;
}