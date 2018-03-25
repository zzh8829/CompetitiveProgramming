/*
ID: zzh8829
PROG: nocow
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n,k,m;
set<string> adj[31];
vector<string> vs[31];
vector<string> cow[101];
int ci[101];

bool cmpc(const vector<string>& v1,const vector<string>& v2)
{
	for(int i=0;i!=v1.size();i++)
		if(v1[i]!=v2[i])
			return v1[i]<v2[i];
	return v1.size()<v2.size();
}

int main()
{
#ifndef LOCAL1
	ifstream cin("nocow.in");
	ofstream cout("nocow.out");
#endif
	cin >> n >> k;
	for(int i=0;i!=n;i++)
	{
		int j = 0;
		string str;
		cin >> str >> str >> str >> str;
		while(cin >> str && str!="cow.")
		{
			adj[j].insert(str);
			cow[i].push_back(str);
			j++;
		}
		m = j;
	}
	for(int i=0;i!=m;i++)
		for(set<string>::iterator it=adj[i].begin();it!=adj[i].end();it++)
			vs[i].push_back(*it);
	sort(cow,cow+n,cmpc);
	int hehe;
	for(int i=0;i!=n;i++)
	{
		int mul = 1;
		for(int j=cow[i].size()-1;j>=0;j--)
		{
			ci[i] += mul*(lower_bound(vs[j].begin(),vs[j].end(),cow[i][j])-vs[j].begin());
			mul*= vs[j].size();
		}
		hehe = mul;
	}
	int idx = lower_bound(ci,ci+n,k)-ci;
	int modi = k+idx;
	if(idx==n || ci[idx] > k)modi--;
	while(binary_search(ci,ci+n,modi))modi++;
	int mul = hehe;
	for(int i=0;i!=m;i++)
	{
		if(i)cout << " ";
		mul/=vs[i].size();
		cout << vs[i][modi/mul];
		modi%=mul;
	}
	cout << endl;
	return 0;
}	