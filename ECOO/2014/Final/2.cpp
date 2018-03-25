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

map<string, set<string> > mtod;
map<string, string > dtom;

int cousins(string name)
{
//	cout << name << endl;
	int cnt = 0;
	string gmom = dtom[dtom[name]];
	//cout << gmom << endl;
	for(string msis: mtod[gmom])
	{
		if(msis != dtom[name])
		{
	//		cout << msis << " ";
			cnt += mtod[msis].size();	
		}
	}
//	cout << endl;
	return cnt;
}

int sisters(string name)
{
	if(!dtom.count(name))
		return 0;
	string mom = dtom[name];
	return mtod[mom].size()-1;
}

int main()
{
	freopen("DATA21.txt","r",stdin);
	int n;
	cin >> n;
	for (int i=0;i!=n;i++)
	{
		string mot,dau;
		cin >> mot >> dau;
		mtod[mot].insert(dau);
		dtom[dau] = mot;
	}
	for (int i=0;i<10;i++)
	{
		string name;
		cin >> name;
		printf("Cousins: %d, Sisters: %d\n",cousins(name),sisters(name));
	}

	return 0;
}