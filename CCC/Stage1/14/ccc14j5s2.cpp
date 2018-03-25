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

string none = "@_@";

vector<string> vs;
map<string,string> mss;

int main()
{
	cin >> n;
	string name;
	for(int i=0;i!=n;i++)
	{
		cin >> name;
		vs.push_back(name);
		mss[name] = none;
	}
	for(int i=0;i!=n;i++)
	{
		cin >> name;
		if(name == vs[i] )
		{
			cout << "bad";
			return 0;
		}
		if(mss[name] != none)
		{
			if( mss[mss[name]] != name)
			{
				cout << "bad";
				return 0;
			}
		}
		mss[name] = vs[i];
		mss[vs[i]] = name;
	}
	cout << "good" << endl;
	return 0;
}