#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct P{
	int x, y,z;
	P(int _x=0,int _y=0):x(_x),y(_y),z(0){}
	bool operator <(const P &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

int cross(const P &O, const P &A, const P &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<P> convex_hull(vector<P> v)
{
	int n = v.size(), k = 0;
	vector<P> h(2*n);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(h[k-2], h[k-1], v[i]) <= 0) k--;
		h[k++] = v[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(h[k-2], h[k-1], v[i]) <= 0) k--;
		h[k++] = v[i];
	}
	h.resize(k);
	return h;
}

vector<P> convex_hull2(vector<P> v)
{
	int n = v.size(), k = 0;
	vector<P> h(2*n);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		while (!v[k-1].z && k >= 2 && cross(h[k-2], h[k-1], v[i]) <= 0) k--;
		h[k++] = v[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (!v[k-1].z && k >= t && cross(h[k-2], h[k-1], v[i]) <= 0) k--;
		h[k++] = v[i];
	}
	h.resize(k);
	return h;
}


bool inside(vector<P>& v,int n, P p)
{
	for(int i=0;i!=n-1;i++)
	{
		if(cross(v[i],v[i+1],p) < 0)
		{
			cout << "#\n";

				cout << p.x << " " << p.y << endl;

			cout << "$\n";

			return false;
		}
	}
	//cout << p.x << " " << p.y << endl;
	return true;
}

double dis(P& a, P& b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

int main()
{
	vector<P> vin;

	int n,m,x,y;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> x >> y;
		vin.push_back(P(x,y));
	}
	vin = convex_hull(vin);
	int vs = vin.size();
	cin >> m;
	for(int i=0;i!=m;i++)
	{
		cin >> x >> y;
		if(inside(vin,vs,P(x,y)))
		{
			cout << "#SD\n";

				cout << x << " " << y << endl;

			cout << "$SDF\n";

			vin.push_back(P(x,y));
			vin[vin.size()-1].z = 1;
		}
	}
	cout << "#\n";
	for(int i=0;i!=vin.size();i++)
	{
		cout << vin[i].x << " " << vin[i].y << endl;
	}
	cout << "$\n";
	vin = convex_hull(vin);
	double tot = 0;
	for(int i=0;i!=vin.size()-1;i++)
	{
		cout << vin[i].x << " " << vin[i].y << endl;
		tot += dis(vin[i],vin[i+1]);
	}
	cout << tot << endl;
	return 0;
}