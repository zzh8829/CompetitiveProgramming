#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>

using namespace std;
vector<char> ct[128];
set<char> ans[128];
bool done[128][128];
string junk;

void rec(int i,char j)
{
	if(done[i][j]) return;
	done[i][j] = true;
	if( 'a' <= j &&  j<='z'){
		ans[i].insert(j);
		return;
	}
	for(int k=0;k!=ct[j].size();k++)
		rec(i,ct[j][k]);
	if(ans[i].size()==0)
		ans[i].insert('_');
	if(ans[j].size()==0)
		ans[j].insert('_');
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		char a,b;
		cin >> a >> junk >> b;
		ct[(int)a].push_back(b);
	}
	for(int i='A';i<='Z';i++) if(ct[i].size()!=0)
		for(int j=0;j!=ct[i].size();j++)
			rec(i,ct[i][j]);
	for(int i='A';i<='Z';i++) if(ans[i].size()!=0)
	{
		cout << (char)i << " = {";
		bool f = true;
		for(set<char>::iterator j=ans[i].begin();j!=ans[i].end();j++)
		{
			if('a'<= *j && *j <= 'z'){
				if(!f) cout << ',';
				cout << *j;
				f = false;
			}
		}
		cout <<"}" << endl;
	}
	return 0;
}