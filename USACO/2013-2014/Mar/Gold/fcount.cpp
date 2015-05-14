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

int sum;
int a[502];
int n;
vector<int> vi;

int main()
{
	freopen("fcount.in","r",stdin);
	freopen("fcount.out","w",stdout);
	cin >> n;
	for(int i=0;i!=n+1;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for(int i=0;i!=n+1;i++)
	{
		if((sum - a[i])% 2 == 0)
		{
			vi.push_back(i);
		}
	}
	cout << vi.size() << endl;
	for(int i=0;i!=vi.size();i++)
	{
		cout << vi[i]+1 << endl;
	}
	return 0;
}