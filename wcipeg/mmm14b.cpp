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

typedef long long LL;

int n;
double p[100001];
double v[100001];
double pp[100001];
double vv[100001];
double vp2[100001];

int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
		scanf("%lf",p+i);
	for(int i=0;i!=n;i++)
	{
		int tp;
		scanf("%d",&tp);
		p[i]-=tp;
		pp[i+1]+= pp[i] + p[i]*p[i];
	}	
	for(int i=0;i!=n;i++)
		scanf("%lf",v+i);
	for(int i=0;i!=n;i++)
	{
		int tv;
		scanf("%d",&tv);
		v[i]-=tv;
		vv[i+1]+= vv[i] + v[i]*v[i];
		vp2[i+1]+= vp2[i] + 2*v[i]*p[i];
	}
	double d = vp2[n]*vp2[n] - 4*vv[n]*pp[n];
	double t;
	if(d<0) 
	{
		t = (-vp2[n])/2.0/vv[n];
	} else {
		d = sqrt(d);
		if(-vp2[n] - d < 0)
			d = -d; 
		t = (-vp2[n]-d)/2.0/vv[n];
	}
	if(t < 0 || vv[n]==0) t = 0;
	cout << t << endl;
	return 0;
}