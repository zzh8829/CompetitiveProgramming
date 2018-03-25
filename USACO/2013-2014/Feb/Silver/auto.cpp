#include <algorithm>
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

set<string> ss;
map<string,int> msi;
int W,N;

bool ok(const string& a,const string& c)
{
	for(int i=0;i!=a.size();i++)
	{
		if(i==c.size())return false;
		if(a[i]!=c[i])return false;
	}
	return true;
}

int main()
{
	ifstream cin("auto.in");
	ofstream cout("auto.out");
	cin >> W >> N;
	for(int i=0;i!=W;i++)
	{
		string s;
		cin >> s;
		ss.insert(s);
		msi[s]=i;
	}
	for(int i=0;i!=N;i++)
	{
		string s;
		int k;
		cin >> k >> s;
		set<string>::iterator it = ss.lower_bound(s);
		while(it!=ss.end()&&--k)
			it++;
		if(it!=ss.end() && ok(s,*it))
			cout << msi[*it]+1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}