#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;
bool v[101][64002];
int ns[101];
char os[101];
int cs,n;
int ans;
bool flag=0;

void rec(int p,int num)
{
	if(num < -32000 || num > 32000 || flag)
		return;
	if(p==n)
	{
		if(num==ans)
		{
			for(int i=0;i!=n;i++)
			{
				cout << ns[i];
				if(i!=n-1)
					cout << os[i];
			}
			cout << "=" << ans << endl;
			flag = 1;
		}
		return;
	}
	if(v[p][num+32000])
		return;
	v[p][num+32000] =1;
	os[p-1]='+';
	rec(p+1,num+ns[p]);
	os[p-1]='-';
	rec(p+1,num-ns[p]);
	if(abs(ns[p]) < 34000.0/abs(num))
	{
		os[p-1]='*';
		rec(p+1,num*ns[p]);
	}
	if(ns[p]!=0 && num%ns[p]==0)
	{
		os[p-1] = '/';
		rec(p+1,num/ns[p]);
	}
	os[p-1] = ' ';
}

int main()
{
	freopen("test.txt","w",stdout);
	cin >> cs;
	while(cs--)
	{
		cin >> n;
		for(int i=0;i!=n;i++)
			cin >> ns[i];
		cin >> ans;
		flag = 0;
		for(int i=0;i!=100;i++)
			memset(v[i],0,sizeof(v[i]));
		rec(1,ns[0]);
		if(!flag)cout << "NO EXPRESSION" << endl;
	}
	return 0;
}