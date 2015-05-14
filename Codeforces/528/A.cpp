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

set<int> sh;
set<int> sv;
multiset<int> qh;
multiset<int> qv;
int w,h,n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> w >> h >> n;
	sh.insert(0);
	sh.insert(h);
	sv.insert(0);
	sv.insert(w);
	qh.insert(h);
	qv.insert(w);
	for(int i=0;i!=n;i++)
	{
		char c;
		int a;
		cin >> c >> a;
		if(c=='H')
		{
			auto ib = sh.insert(a);
			auto it = ib.first;
			it--;
			int l = *it;
			it++;
			it++;
			int r = *it;
			qh.erase(qh.equal_range(r-l).first);
			qh.insert(a-l);
			qh.insert(r-a);
			cout << 1LL*(*qh.rbegin())*(*qv.rbegin()) << endl;
		}
		if(c=='V')
		{
			auto ib = sv.insert(a);
			auto it = ib.first;
			it--;
			int l = *it;
			it++;
			it++;
			int r = *it;
			qv.erase(qv.equal_range(r-l).first);
			qv.insert(a-l);
			qv.insert(r-a);
			cout << 1LL*(*qh.rbegin())*(*qv.rbegin()) << endl;
		}
	}
	return 0;
}