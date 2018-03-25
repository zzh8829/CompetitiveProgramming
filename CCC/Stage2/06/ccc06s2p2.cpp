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

const double error =  1e-8;

struct Vec
{
	double x,y,z;
	Vec(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z){};
	double dotProduct(const Vec& v)
	{
		return x*v.x + y*v.y + z*v.z;
	}
	Vec operator* (const double& k)
	{
		return Vec(x*k,y*k,z*k);
	}
	Vec operator/ (const double& k)
	{
		return Vec(x/k,y/k,z/k);
	}
	Vec operator+ (const Vec& v)
	{
		return Vec(x+v.x,y+v.y,z+v.z);
	}
	Vec operator- (const Vec& v)
	{
		return Vec(x-v.x,y-v.y,z-v.z);
	}
	double norm()
	{
		return sqrt(x*x+y*y+z*z);
	}
	double normalize()
	{
		double s = norm();
		if(s!=0)
		{
			x/=s;
			y/=s;
			z/=s;
		}
		return s;
	}
};

struct Seg
{
	Vec c,d;
	double l;
	Seg(Vec p1, Vec p2)
	{
		c = (p2+p1)*0.5;
   		d = p2-p1;
		l = 0.5*d.normalize();
	}
};

struct Sphere
{
	Vec c;
	double r;
	bool intersect(Seg seg)
	{
		Vec diff = seg.c - c;
		double a0 = diff.dotProduct(diff) - r*r;
		double a1 = seg.d.dotProduct(diff);
		double dis = a1*a1 - a0;
		if (dis < 0.0)
		{
			return false;
		}
		double tmp0 = seg.l*seg.l + a0; 
		double tmp1 = 2*a1*seg.l;
		double qm = tmp0 - tmp1;
		double qp = tmp0 + tmp1;
		if (qm*qp <= error)
		{
			return true;
		}
		return qm > 0.0 && abs(a1) < seg.l;
	}
};

int main()
{
	Vec p1,p2;
	scanf("%lf%lf%lf",&p1.x,&p1.y,&p1.z);
	scanf("%lf%lf%lf",&p2.x,&p2.y,&p2.z);
	Seg seg(p1,p2);
	int n;
	scanf("%d",&n);
	Sphere sp;
	int cnt = 0;
	for(int i=0;i!=n;i++)
	{
		scanf("%lf%lf%lf%lf",&sp.c.x,&sp.c.y,&sp.c.z,&sp.r);
		if(sp.intersect(seg))
		{
			cnt++;
		}
	}
	printf("%d\n",cnt)
	return 0;
}