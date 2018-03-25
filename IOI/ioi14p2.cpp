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

#ifdef EVAL
#include "station.h"
#endif

int findMinDays(int n,int k,int lodge[])
{
	vector<int> vl;
	for(int i=0;i!=n;i++)
		if(lodge[i])
			vl.push_back(i);
	int p=0;
	int s=0;
	while(p+k<n-1)
	{
		auto it = upper_bound(vl.begin(),vl.end(),p+k)-1;
		int i = *it;
		if(i==p) return -1;
		p = i;
		s++;
	}
	return s+1;
}

#ifndef EVAL

int main()
{
	static int n,k,lodge[500001];
	cin >> n >> k;
	for(int i=0;i!=n;i++)
		cin >> lodge[i];
	cout << findMinDays(n,k,lodge) << endl;
	return 0;
}

#endif