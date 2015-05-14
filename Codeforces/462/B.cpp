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

int n,k;

LL cnt[256];
vector<LL> vi;

int main()
{
	cin >> n >> k;
	for(int i=0;i!=n;i++)
	{
		char c;
		cin >> c;
		cnt[c]++;
	}
	for(int i='A';i<='Z';i++)
	{
		vi.push_back(cnt[i]);
	}
	sort(vi.begin(),vi.end(),greater<LL>());
	int cn=0;
	LL tot=0;
	for(int i=0;i!=vi.size();i++)
	{
		if(cn == k) break;
		LL a = vi[i];
		if(cn + a > k)
		{
			a = k-cn;
		}
		tot += a*a;
		cn+=a;
	}
	cout << tot << endl;
	return 0;
}