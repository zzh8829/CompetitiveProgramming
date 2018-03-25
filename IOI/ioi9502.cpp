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

vector<string> vs;
vector<int> tch;
vector<int> ch;
int n = 1;
int bn = 0;
int main()
{
	string str;
	while(getline(cin,str) && str != ".")
		vs.push_back(str);
	tch.push_back(0);
	for(int i=1;i!=vs.size();i++) 
	{
		if(vs[i].size() < vs[i-1].size() || 
			vs[i].substr(0,vs[i-1].size()-1) != vs[i-1]) 
		{
			if(n > bn) ch = tch;
			n = 1;
			tch.clear();
			tch.push_back(i);
		} else {
			n++;
			tch.push_back(i);
		}
	}
	for(int i:ch)
	{
		cout << vs[i] << endl;
	}
	return 0;
}