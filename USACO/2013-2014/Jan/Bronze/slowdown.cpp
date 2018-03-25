#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Frac
{
	Frac():u(0),d(1){}
	Frac(int x):u(x),d(1){}
	Frac(int _u,int _d):u(_u),d(_d){}
	Frac div(Frac f)
	{
		return mul(f.rec());
	}
	Frac mul(Frac f)
	{
		return Frac(u*f.u,d*f.d).nord();
	}
	Frac sub(Frac f)
	{
		return add(f.neg());
	}
	Frac add(Frac f)
	{
		int gcd = __gcd(d,f.d);
		return Frac(u*f.d/gcd + f.u*d/gcd , gcd * d * f.d).nord();
	}
	Frac rec()
	{
		return Frac(d,u);
	}
	Frac neg()
	{
		return Frac(-u,d);
	}
	void nor()
	{
		int k = __gcd(u,d);
		u/=k;
		d/=k;
		if(u*d < 0 && u>0)
		{
			u=-u;
			d=-d;
		}
	}
	Frac nord()
	{
		Frac f(u,d);
		f.nor();
		return f;
	}
	bool equ(Frac f)
	{
		Frac s = nord();
		f.nor();
		return s.u==f.u && s.d==f.d;
	}
	bool operator < (const Frac& f) const
	{
		Frac sp = *this;
		Frac fp = f;
		if(sp.equ(fp))
			return true;
		return (u/(float)d) < (f.u/(float)f.d);
	}
	bool operator > (const Frac& f) const
	{
		return f.operator<(*this);
	}
	int ish()
	{
		return (int)(u/float(d) + 0.5);
	}
	void out()
	{
		cout << u << "/" << d << endl;
	}
	int u,d;
};

int n;
vector<Frac> vt;
vector<Frac> vd;
int nt,nd;
Frac cm;
Frac ct;
int cs=1;
Frac fs(1);

Frac nextTime()
{
	if(nt==vt.size()) return Frac(1001);
	return vt[nt].sub(ct).mul(fs).add(cm);
}

Frac nextDis()
{
	if(nd==vd.size()) return Frac(1001);
	return vd[nd];
}

int main()
{
#ifndef LOCAL
	freopen("slowdown.in","r",stdin);
	freopen("slowdown.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		char c;
		int x;
		cin >> c >> x;
		if(c=='T')
			vt.push_back(Frac(x));
		else 
			vd.push_back(Frac(x));
	}
	sort(vt.begin(),vt.end());
	sort(vd.begin(),vd.end());

	Frac nextd = nextDis();
	Frac nextt = nextTime();

	while(true)
	{
		if(nextt > Frac(1000) && nextd > Frac(1000))
		{
			cout << ct.add(Frac(1000).sub(cm).div(fs)).ish() << endl;
			return 0;
		}
		if(nextt < nextd)
		{
			cm = nextt;
			ct = vt[nt];
			fs.d += 1;
			nt++;
			nextt = nextTime();
		} else if(nextt > nextd) {
			ct = ct.add(vd[nd].sub(cm).div(fs));
			cm = nextd;
			fs.d += 1;
			nd++;
			nextd = nextDis();
			nextt = nextTime();
		} else {
			cm = nextt;
			ct = vt[nt];
			fs.d += 2;
			nd++;
			nt++;
			nextd = nextDis();
			nextt = nextTime();
		}
	}
	return 0;
}
