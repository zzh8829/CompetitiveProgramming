#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

struct Vec
{
	float x,y,z;
	Vec(float _x=0,float _y=0,float _z=0):x(_x),y(_y),z(_z){};
	Vec operator+(const Vec& v)const{
		return Vec(x+v.x,y+v.y,z+v.z);
	}
	Vec operator-(const Vec& v)const{
		return Vec(x-v.x,y-v.y,z-v.z);
	}
	/*
	x  y  z  x  y  z
		x  x  x
	vx vy vz vx vy vz
	*/
	Vec crossProduct(const Vec& v)const{
		return Vec(
				y*v.z-z*v.y,
				z*v.x-x*v.z,
				x*v.y-y*v.x);
	}
	float dotProduct(const Vec& v)const{
		return x*v.x+y*v.y+z*v.z;
	}
	float norm(){
		return sqrt(x*x+y*y+z*z);
	}
};

Vec pts[1001];
int ptn;

struct Planet
{
	Vec p;
	int r,v;
}pls[1001];
int pln;

bool v[1001];

int D;

bool check(Vec& p0,Vec& p1,Planet& planet)
{
	Vec v0 = p1-p0;
	Vec v1 = planet.p-p0;
	Vec v2 = planet.p-p1;
	if(v0.dotProduct(v1) < 0)
	{
		if(D+planet.r >= v1.norm())
			return true;
		return false;
	}
	if(v0.dotProduct(v2) > 0)
	{
		if(D+planet.r >= v2.norm())
			return true;
		return false;
	}
	if(D+planet.r >= v0.crossProduct(v1).norm()/v0.norm())
		return true;
	return false;
}

int main()
{
	scanf("%d",&pln);
	for(int i=0;i!=pln;i++)
		scanf("%f%f%f%d%d",&pls[i].p.x,&pls[i].p.y,&pls[i].p.z,&pls[i].v,&pls[i].r);
	scanf("%d",&ptn);
	for(int i=0;i!=ptn;i++)
		scanf("%f%f%f",&pts[i].x,&pts[i].y,&pts[i].z);
	scanf("%d",&D);
	int tot = 0;
	for(int i=0;i!=ptn-1;i++)
	for(int j=0;j!=pln;j++)if(!v[j])
	if(check(pts[i],pts[i+1],pls[j]))
	{
		tot +=pls[j].v;
		v[j]=1;
	}
	cout << tot << endl;
	return 0;
}