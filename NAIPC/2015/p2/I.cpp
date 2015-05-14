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

typedef pair<int,int> I2;
typedef vector<int> VI;
map<I2,VI> miv;
int x1s[2001];
int y1s[2001];
int x2s[2001];
int y2s[2001];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
	{
		scanf("%d %d %d %d",&x1s[i],&y1s[i],&x2s[i],&y2s[i]);
		int dy = y2s[i]-y1s[i];
		int dx = x2s[i]-x1s[i];
		if(dx==0)
		{
			miv[I2(-1,0)].push_back(i);
			//cout << -1 <<" " << 0 << endl;
		} else {
			int gcd = __gcd(dy,dx);
			dx/=gcd;dy/=gcd;
			if(dx < 0)
			{
				dx = -dx;
				dy = -dy;
			}
			miv[I2(dy,dx)].push_back(i);
			//cout << dy <<" " <<dx << endl;
		}
	}
	long long cnt = 0;
	for(map<I2,VI>::iterator it = miv.begin();it!=miv.end();it++)
	{
		if(it->first.first < 0) continue;
		vector<int> vi = it->second;
		map<float,int> mfi;
		for(int i=0;i!=vi.size()-1;i++)
		{
			double d = sqrt((y2s[vi[i]]-y1s[vi[i]])*(y2s[vi[i]]-y1s[vi[i]]) + (x2s[vi[i]]-x1s[vi[i]])*(x2s[vi[i]]-x1s[vi[i]]));
			for(int j=i+1;j!=vi.size();j++)
			{
				double f = abs((y2s[vi[i]]-y1s[vi[i]])*x1s[vi[j]] - (x2s[vi[i]]-x1s[vi[i]])*y1s[vi[j]] + x2s[vi[i]]*y1s[vi[i]] - y2s[vi[i]]*x1s[vi[i]])/d;
				mfi[f]++;
			}
		}
		if(!miv.count(I2(-it->first.second,it->first.first)))
			continue;
		vi = miv[I2(-it->first.second,it->first.first)];
		map<float,int> mfi2;
		for(int i=0;i!=vi.size()-1;i++)
		{
			double d = sqrt((y2s[vi[i]]-y1s[vi[i]])*(y2s[vi[i]]-y1s[vi[i]]) + (x2s[vi[i]]-x1s[vi[i]])*(x2s[vi[i]]-x1s[vi[i]]));
			for(int j=i+1;j!=vi.size();j++)
			{
				double f = abs((y2s[vi[i]]-y1s[vi[i]])*x1s[vi[j]] - (x2s[vi[i]]-x1s[vi[i]])*y1s[vi[j]] + x2s[vi[i]]*y1s[vi[i]] - y2s[vi[i]]*x1s[vi[i]])/d;
				mfi2[f]++;
			}
		}
		for(map<float,int>::iterator it2=mfi.begin();it2!=mfi.end();it2++)
		{
			if(mfi2.count(it2->first))
				cnt += it2->second * mfi2[it2->first];
		}
	}
	cout << cnt << endl;
	return 0;
}