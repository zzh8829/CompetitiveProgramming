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

struct P{
	float x,y;
	P(float _x=0,float _y=0):x(_x),y(_y){}
	float distance(const P& p){
		return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
	}
};

struct Info{
	Info(int _c,int _n,P _p):c(_c),n(_n),p(_p){}
	int c,n;
	P p;
};

int n,m;

int nc;
map<int,int> mc;

P pos;
vector<Info> ps[101];

int tot;
bool dp[50001];
vector<int> ls;

int len,cir;

int search(float val)
{
	int lo = 0;
	int hi = ls.size();
	int mi = 0;
	while(hi>=lo)
	{
		mi = (lo+hi)/2;
		if(ls[mi]<val)
		{
			lo = mi+1;
		} else if(ls[mi]>val) {
			hi = mi-1;
		} else {
			return ls[mi];
		}
	}
	if(lo>=ls.size())return -1;
	return ls[lo];
}

int main()
{
	dp[0]=1;
	cin >> pos.x >> pos.y >> m >> n;
	for(int i=0;i!=m;i++)
	{
		cin >> len;
		tot+=len;
		for(int j=50000;j>=len;j--)
			if(dp[j-len])dp[j]=1;
	}
	for(int i=0;i<=50000;i++)
		if(dp[i])ls.push_back(i);
	for(int i=0;i!=n;i++)
	{
		P p;
		cin >> p.x >> p.y >> cir;
		int dis = search(pos.distance(p));
		if(dis == -1) continue;
		if(mc.count(cir)<=0)
		mc[cir] = nc++;
		ps[mc[cir]].push_back(Info(dis,i,p));
	}
	for(int i=0;i!=nc-1;i++)
	for(int j=i+1;j!=nc;j++)
	for(int o1=0;o1!=ps[i].size();o1++)
	for(int o2=0;o2!=ps[j].size();o2++)
	{
		if(ps[i][o1].c + ps[j][o2].c <= tot)
		{
			if(ps[i][o1].n > ps[j][o2].n)swap(ps[i][o1],ps[j][o2]);
			printf("Harry can connect to outlets at (%.1f, %.1f) and (%.1f, %.1f).\n",
				ps[i][o1].p.x,ps[i][o1].p.y,
				ps[j][o2].p.x,ps[j][o2].p.y);
			return 0;
		}
	}
	cout << "Harry is helpless." << endl;	
	return 0;
}