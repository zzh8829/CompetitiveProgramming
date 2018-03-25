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

int n,a;

vector< pair<int,int> >rb;
set<int> rq;

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> a;
		rb.push_back(make_pair(a,i));
	}
	sort(rb.begin(),rb.end());
	rq.insert(rb[0].second);
	for(int i=1;i!=n;i++)
	{
		set<int>::iterator it = rq.lower_bound(rb[i].second);
		if(it==rq.begin())
		{
			cout << "NO" << endl;
			return 0;
		}
		it--;
		v[*it]++;
		if(v[*it]==2) rq.erase(it);
		rq.insert(rb[i].second);
	}
	cout << "YES" << endl;
	return 0;
}