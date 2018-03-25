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

int n;
int seq[100001];

vector<int> inc[100001];

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> seq[i];
	int seqn=0;
	inc[seqn].push_back(seq[0]);
	for(int i=1;i!=n;i++)
	{
		if(seq[i] > seq[i-1])
			inc[seqn].push_back(seq[i]);
		else
			inc[++seqn].push_back(seq[i]);
	}
	if(seqn == 0) {
		cout << n << endl;
		return 0;
	}
	size_t maxl = inc[0].size()+1;
	for(int i=1;i<=seqn;i++)
	{
		maxl = max(inc[i].size()+1,maxl);
		if(inc[i].size() > 1)
		{
			if(inc[i][1] - inc[i-1].back() > 1)
			{
				maxl = max(inc[i].size()+inc[i-1].size(),maxl);
			}
		}
		if(inc[i-1].size() > 1)
		{
			if(inc[i][0] - inc[i-1][inc[i-1].size()-2] > 1) 
			{
				maxl = max(inc[i].size()+inc[i-1].size(),maxl); 
			}
		} else {
			maxl = max(inc[i].size()+1,maxl);
		}
		if(inc[i].size()==1)
		{
			if(i!=seqn)
			{
				if(inc[i+1][0] - inc[i-1].back() > 1)
				{
					maxl = max(inc[i-1].size() + inc[i+1].size() +1, maxl);
				}
			}
		}
	}
	cout << maxl << endl;
	return 0;
}