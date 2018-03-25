/*
ID: zzh8829
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

struct Pass {
	int a,b,c;
	Pass(char _a,char _b,char _c):a(_a),b(_b),c(_c){}
	bool operator < (const Pass& p) const{
		return a==p.a?b==p.b?c<p.c:b<p.b:a<p.a;
	}
};

int n;
int a1,b1,c1;
int a2,b2,c2;

set<Pass> sp;

int main()
{
#ifndef LOCAL1
	ifstream cin("combo.in");
	ofstream cout("combo.out");
#endif
	cin >> n;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	for(int i1=-2;i1<=2;i1++)
	for(int i2=-2;i2<=2;i2++)
	for(int i3=-2;i3<=2;i3++)
	{
		sp.insert(Pass((a1+i1-1+n)%n+1,(b1+i2-1+n)%n+1,(c1+i3-1+n)%n+1));
		sp.insert(Pass((a2+i1-1+n)%n+1,(b2+i2-1+n)%n+1,(c2+i3-1+n)%n+1));
	}
	cout << sp.size();
	return 0;
}
