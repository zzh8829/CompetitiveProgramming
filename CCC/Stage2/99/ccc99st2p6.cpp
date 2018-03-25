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

int n,k;
int r[201];
int s[201],sn;

int test(int len)
{
	sn = 0;
	int tot=0;
	int mid;
	int pos = 0;
	int beg = r[pos];
	while(true)
	{
		while(pos<n && beg+len>=r[pos])
			pos++;
		mid = r[pos-1];
		s[sn++] = mid;
		while(pos<n && mid+len>=r[pos])
			pos++;
		tot++;
		if(pos==n)break;
		beg = r[pos];
	}
	return tot;
}

int main()
{
	freopen("test.txt","r",stdin);
	freopen("test2.txt","w",stdout);
	while(cin >> n && n!=0)
	{
		cin >> k;
		for(int i=0;i!=n;i++)
			cin >> r[i];
		sort(r,r+n);
		int maxi = r[n-1];
		int mini = 0;
		while(maxi > mini)
		{
			int midi = (maxi + mini)>>1;
			if(test(midi)>k)
				mini = midi+1;
			else
				maxi = midi;
		}
		test(maxi);
		for(int i=0;i!=sn;i++)
		{
			if(i)cout << " ";
			cout << s[i];
		}
		for(int i=sn;i<k;i++)
			cout<< " " << s[sn-1];
		cout << endl;
		cout << maxi << endl;
		cout << endl;
	}
	return 0;
}