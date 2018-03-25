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
#include <deque>

using namespace std;

multiset<int> msi;
deque<int> dq;
int num[200005];
int n;

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> num[i];
	}
	int k=0;
	for(int i=1;i!=n;i++)
	{
		if(num[i-1] > num[i])
		{
			k = i;
			break;
		}
	}
	if(k==0)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i=k+1;i!=n;i++)
	{
		if(num[i-1] > num[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	if(num[n-1] > num[0])
	{
		cout << -1 << endl;
		return 0;
	}
	cout << n-k << endl;
	return 0;
}

