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
#include <queue>

using namespace std;

struct City
{
	string name;
	vector<string> vc;
};

City cs[30];
int cn;
map<string,int> msi;
string s,s2;

int nc;
int nq;

void add_city(string name)
{
	if(!msi.count(name))
	{
		msi[name] = cn;
		cs[cn].name = name;
		cn++;
	}
}

int main()
{
	cin >> nc >> nq;
	for(int i=0;i!=nc;i++)
	{
		cin >> s >> s2;
		add_city(s);
		add_city(s2);
		cs[msi[s]].vc.push_back(s2);
		cs[msi[s2]].vc.push_back(s);
	}
	for(int i=0;i!=nq;i++)
	{
		cin >> s >> s2;
		string path;
		queue<pair<int,string> > q;
		q.push(make_pair(msi[s], ""));
		int vis[30] = {0};
		while(!q.empty())
		{
			pair<int,string> c = q.front();q.pop();
			if(c.first ==msi[s2])
			{
				path = c.second;
				break;
			}
			vis[c.first] = 1;
			for(int j=0;j!=cs[c.first].vc.size();j++)
			{
				if(vis[msi[cs[c.first].vc[j]]])continue;
				q.push(make_pair(msi[cs[c.first].vc[j]],c.second + cs[c.first].name[0]));
			}
		}
		cout << path+s2[0]<< endl;
	}
	return 0;
}